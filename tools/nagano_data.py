#!/usr/bin/env python3
"""Nagano Winter Olympics '98 (USA) physical ROM data ledger and reconstruction.

Subcommands
  verify-rom ROM                 check SHA-1, size and byte order
  normalize IN OUT               write a .z64 (big-endian) copy of a .v64/.n64 ROM
  map ROM OUTDIR [--units-tsv T] [--overlay-tsv T]
                                 build rom_map.tsv/json and companion ledgers
  reconstruct ROM OUTDIR         rebuild every non-code physical byte from its
                                 structured representation and compare
All integers are read big-endian with explicit widths; no host struct layout is
assumed.  Paths are taken from the command line only.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import struct
import sys
from collections import Counter, OrderedDict
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

import konami_lz  # noqa: E402
import nagano_audio  # noqa: E402
import nagano_sequences  # noqa: E402
import rom_header  # noqa: E402

ROM_SHA1 = "eaf543e195731031a84f4136b506449209e3a8f5"
ROM_SIZE = 0xC00000
RAM = 0x7FFFF400                    # RAM = ROM + RAM for the initial program image
FILE_TABLE_BASE = 0x800622E8        # func_800014D8: entry(id) = base + 8 + id*8 (ids are 1-based)
FILE_TABLE_ROM = FILE_TABLE_BASE + 0x10 - RAM
FILE_TABLE_COUNT = 538
SEQ_START_TABLE = 0x800736F8        # func_800499CC
SEQ_END_TABLE = 0x80073754
SEQ_COUNT = 23
OVERLAY_TABLE = 0x80063558          # records {romStart, vram, romEnd, romStart}
OVERLAY_VRAM = 0x801954A0

CATEGORIES = [
    "rom_header_or_boot", "executable_code", "code_unit_data", "initialized_data", "readonly_data",
    "pointer_or_offset_table", "text_or_string", "texture", "palette", "sprite_or_ui", "font",
    "model_geometry", "vertex", "display_list", "animation_or_skeleton", "collision", "gameplay_records",
    "audio_sequence", "audio_bank", "compressed_container", "padding", "checksum", "loader_runtime_block",
    "unknown",
]
STAGES = ["unknown", "bounded", "classified", "decoded", "reconstructable", "byte-exact"]

# Program-image code ranges (other worker owns their matching); RSP microcode
# boundaries come from the project inventory (64-byte granularity evidence).
PROGRAM_CODE = [
    (0x1000, 0x1038, "cpu_text", "entry .text 0x80000400"),
    (0x1060, 0x60FC0, "cpu_text", ".text 0x80000460"),
    (0x60FC0, 0x61300, "rsp_ucode", "RSP microcode text (vector opcodes)"),
    (0x61300, 0x61580, "cpu_text", ".text"),
    (0x61580, 0x62EC0, "rsp_ucode", "RSP microcode text (vector opcodes); 0x6221C.. is linked into .data"),
]


class DataError(ValueError):
    pass


def be32(b, o):
    if o < 0 or o + 4 > len(b):
        raise DataError(f"read outside buffer at {o:#x}")
    return struct.unpack_from(">I", b, o)[0]


def load_rom(path: str | Path) -> bytes:
    rom = Path(path).read_bytes()
    if len(rom) != ROM_SIZE:
        raise DataError(f"ROM size {len(rom):#x} != {ROM_SIZE:#x} (truncated or wrong image)")
    if rom[:4] != b"\x80\x37\x12\x40":
        raise DataError("ROM is not big-endian .z64; run `normalize` first")
    digest = hashlib.sha1(rom).hexdigest()
    if digest != ROM_SHA1:
        raise DataError(f"ROM SHA-1 {digest} does not match {ROM_SHA1}")
    return rom


def normalize(data: bytes) -> bytes:
    magic = data[:4]
    if magic == b"\x80\x37\x12\x40":
        return data
    if magic == b"\x37\x80\x40\x12":  # .v64 byte-swapped halfwords
        out = bytearray(data)
        out[0::2], out[1::2] = data[1::2], data[0::2]
        return bytes(out)
    if magic == b"\x40\x12\x37\x80":  # .n64 little-endian words
        out = bytearray(len(data))
        for i in range(0, len(data), 4):
            out[i:i + 4] = data[i:i + 4][::-1]
        return bytes(out)
    raise DataError("unrecognized ROM byte order")


# ---------------------------------------------------------------- tables
def file_table(rom):
    ents = []
    for i in range(FILE_TABLE_COUNT):
        a = FILE_TABLE_ROM + 8 * i
        s, e = be32(rom, a), be32(rom, a + 4)
        comp, start = s >> 31, s & 0x7FFFFFFF
        if not (start <= e <= ROM_SIZE):
            raise DataError(f"file {i + 1}: bad range {start:#x}..{e:#x}")
        ents.append({"id": i + 1, "table_rom": a, "compressed": bool(comp), "start": start, "end": e})
    for a, b in zip(ents, ents[1:]):
        if a["end"] != b["start"]:
            raise DataError(f"file table not contiguous at id {b['id']}")
    return ents


def sequence_table(rom):
    out = []
    for i in range(SEQ_COUNT):
        s = be32(rom, SEQ_START_TABLE - RAM + 4 * i)
        e = be32(rom, SEQ_END_TABLE - RAM + 4 * i)
        if not s < e:
            raise DataError(f"sequence {i}: bad range")
        out.append({"index": i, "start": s, "end": e})
    return out


def overlay_table(rom):
    recs = []
    a = OVERLAY_TABLE - RAM
    while True:
        s, vram, e, s2 = struct.unpack_from(">IIII", rom, a)
        if vram != OVERLAY_VRAM:
            break
        if s != s2 or not s < e:
            raise DataError(f"overlay record at {a + RAM:#x} inconsistent")
        recs.append((a + RAM, s, e))
        a += 16
    return recs


def overlay_split(rom, s, e):
    """Text end (after the last jr ra) and first data address referenced by the text."""
    words = [be32(rom, x) for x in range(s, e, 4)]
    lastjr = max(i for i, w in enumerate(words) if w == 0x03E00008)
    text_end_v = OVERLAY_VRAM + (lastjr + 2) * 4
    hi, refs = {}, set()
    for w in words[:lastjr + 2]:
        op = w >> 26
        if op == 0x0F:
            hi[(w >> 16) & 31] = (w & 0xFFFF) << 16
        elif op in (0x09, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B, 0x31, 0x35, 0x39, 0x3D):
            rs = (w >> 21) & 31
            if rs in hi:
                v = (hi[rs] + ((w & 0xFFFF) ^ 0x8000) - 0x8000) & 0xFFFFFFFF
                if OVERLAY_VRAM <= v < OVERLAY_VRAM + (e - s):
                    refs.add(v)
    data_v = min(r for r in refs if r >= text_end_v)
    return text_end_v, data_v, sorted(r for r in refs if r >= data_v), sorted(r for r in refs if r < text_end_v)


def s16_records_hint(blob: bytes) -> bool:
    if len(blob) % 12:
        return False
    v = struct.unpack(">%dh" % (len(blob) // 2), blob)
    d6 = sum(abs(v[i] - v[i + 6]) for i in range(0, len(v) - 6, 5))
    d1 = sum(abs(v[i] - v[i + 1]) for i in range(0, len(v) - 1, 5))
    return d6 * 10 < d1


def nested_hint(blob: bytes) -> str:
    """Heuristic content hint for a decoded file (never counted as decoded)."""
    if not blob:
        return "empty"
    w0 = blob[0]
    if len(blob) >= 8 and len(blob) % 8 == 0 and blob[-8:] == b"\xb8\x00\x00\x00\x00\x00\x00\x00" and w0 in (0xB8, 0xE7, 0x01, 0x04, 0xBB, 0xFC, 0xFD, 0xF5, 0xBC, 0xBE, 0xBF, 0xB6, 0xB7, 0xBA, 0xB9, 0xE3, 0xE2):
        return "f3dex_display_list_candidate"
    if b"\xb8\x00\x00\x00\x00\x00\x00\x00" in blob[: len(blob) // 2]:
        return "mixed_with_display_lists_candidate"
    if len(blob) >= 4800 and s16_records_hint(blob[:4800]):
        return "s16_record_stream_candidate"
    return "unclassified"


# ---------------------------------------------------------------- map
class Ledger:
    def __init__(self):
        self.rows = []

    def add(self, start, end, category, subtype, **kw):
        if end < start:
            raise DataError(f"negative range {start:#x}..{end:#x}")
        if end == start:
            return
        if category not in CATEGORIES:
            raise DataError(f"unknown category {category}")
        row = OrderedDict(start=start, end=end, size=end - start, ram=kw.pop("ram", None), segment=kw.pop("segment", ""),
                          category=category, subtype=subtype, compression=kw.pop("compression", "none"),
                          decoded_size=kw.pop("decoded_size", None), record_count=kw.pop("record_count", None),
                          alignment=kw.pop("alignment", None), boundary_evidence=kw.pop("boundary_evidence", ""),
                          type_evidence=kw.pop("type_evidence", ""), references=kw.pop("references", ""),
                          tool=kw.pop("tool", ""), repo_path=kw.pop("repo_path", ""), confidence=kw.pop("confidence", "high"),
                          stage=kw.pop("stage", "classified"), verification=kw.pop("verification", ""), notes=kw.pop("notes", ""),
                          owner=kw.pop("owner", "data"))
        if kw:
            raise DataError(f"unexpected fields {kw}")
        if row["stage"] not in STAGES:
            raise DataError(f"bad stage {row['stage']}")
        self.rows.append(row)

    def finish(self):
        self.rows.sort(key=lambda r: r["start"])
        return validate(self.rows)


def validate(rows):
    """Prove the map starts at 0, ends at ROM size, is ordered, gap-free, non-overlapping."""
    if not rows or rows[0]["start"] != 0:
        raise DataError("map does not start at 0")
    for a, b in zip(rows, rows[1:]):
        if b["start"] < a["end"]:
            raise DataError(f"overlap {a['start']:#x}..{a['end']:#x} / {b['start']:#x}")
        if b["start"] > a["end"]:
            raise DataError(f"gap {a['end']:#x}..{b['start']:#x}")
    if rows[-1]["end"] != ROM_SIZE:
        raise DataError("map does not end at ROM size")
    for r in rows:
        if r["size"] != r["end"] - r["start"]:
            raise DataError("size mismatch")
    total = sum(r["size"] for r in rows)
    by_cat = Counter()
    for r in rows:
        by_cat[r["category"]] += r["size"]
    if total != ROM_SIZE or sum(by_cat.values()) != ROM_SIZE:
        raise DataError("category totals do not equal ROM size")
    return by_cat


def zero_gap(rom, led, a, b, why, **kw):
    if b > a:
        if any(rom[a:b]):
            raise DataError(f"claimed padding {a:#x}..{b:#x} is not zero")
        led.add(a, b, "padding", "zero_alignment", boundary_evidence=why, type_evidence="all bytes zero",
                stage="byte-exact", verification="regenerated as zero bytes", tool="nagano_data.py", **kw)


def build_map(rom, units_tsv=None, overlay_tsv=None):
    led = Ledger()
    sym, assets, containers, loaders, refs, pads = [], [], [], [], [], []
    h = rom_header.parse_header(rom)
    led.add(0, 0x40, "rom_header_or_boot", "n64_header", boundary_evidence="N64 cartridge header",
            type_evidence=f"title {h['title'].strip()!r} id N{h['game_id']}{h['region']}", stage="byte-exact",
            verification="fields + recomputed CIC-6102 CRC1/CRC2", tool="rom_header.py", owner="data")
    led.add(0x40, 0x1000, "rom_header_or_boot", "ipl3_cic6102", boundary_evidence="IPL3 boot code 0x40..0x1000",
            type_evidence="CIC-6102 boot code (checksum seed 0xF8CA4DDC reproduces header CRC)",
            stage="byte-exact", verification=f"verbatim from user ROM, sha1 {hashlib.sha1(rom[0x40:0x1000]).hexdigest()}",
            tool="nagano_data.py", owner="boot", notes="Nintendo boot code: extracted, never committed")
    for s, e, sub, why in PROGRAM_CODE:
        led.add(s, e, "executable_code", sub, ram=s + RAM, segment="program", boundary_evidence=why,
                type_evidence="executable", stage="classified", owner="code", tool="(code worker)")
    zero_gap(rom, led, 0x1038, 0x1060, "entry object .data (0x80000438) unreferenced; datamap ledger class padding",
             ram=0x1038 + RAM, segment="program")
    # -------- program initialized data (datamap objects, verified data units)
    unit_ok = set()
    if units_tsv:
        for ln in Path(units_tsv).read_text().splitlines():
            c = ln.split("\t")
            if len(c) >= 5 and c[4] == "True":
                s, n = int(c[0], 16), int(c[1])
                unit_ok.add((s, s + n))
    objs = [ln.split("\t") for ln in (HERE / "data" / "program_objects.tsv").read_text().splitlines()[1:]]
    tmap = {"f32": "readonly_data", "f64": "readonly_data", "jtbl": "code_unit_data", "string": "text_or_string",
            "pointers": "pointer_or_offset_table", "words": "initialized_data", "unreferenced": "initialized_data"}
    special = [(0x62EE8, 0x62EF8, "text_or_string", "developer_signature", "string 'Nisitenma-Ichigo' (file-table base)"),
               (FILE_TABLE_ROM, FILE_TABLE_ROM + 8 * FILE_TABLE_COUNT, "pointer_or_offset_table", "asset_file_table",
                "538 x {u32 start|0x80000000 compressed, u32 end}; func_800014D8"),
               (OVERLAY_TABLE - RAM, OVERLAY_TABLE - RAM + 16 * 18, "pointer_or_offset_table", "overlay_table",
                "18 x {romStart, vram, romEnd, romStart}; func_80002188"),
               (0x80073690 - RAM, 0x80073690 - RAM + 48, "pointer_or_offset_table", "audio_bank_table",
                "ctl starts/ends, tbl starts; func_80048080"),
               (SEQ_START_TABLE - RAM, SEQ_END_TABLE - RAM + 4 * SEQ_COUNT, "pointer_or_offset_table", "sequence_tables",
                "23 starts + 23 ends; func_800499CC")]
    for c in objs:
        vram, romo, size, section, typ = int(c[0], 16), int(c[1], 16), int(c[2], 16), c[3], c[4]
        s, e = romo, romo + size
        if e <= 0x62EC0:
            continue
        s = max(s, 0x62EC0)
        cat = tmap[typ]
        if section == ".rodata" and cat == "initialized_data":
            cat = "readonly_data"
        exact = any(a <= s and e <= b for a, b in unit_ok)
        pieces, cur = [], s
        for ss, se, scat, ssub, swhy in special:
            if ss < e and se > cur and ss >= cur:
                pieces.append((cur, ss, cat, f"{section[1:]}_{typ}", None))
                pieces.append((ss, min(se, e), scat, ssub, swhy)); cur = min(se, e)
        pieces.append((cur, e, cat, f"{section[1:]}_{typ}", None))
        for ps, pe, pcat, psub, pwhy in pieces:
            led.add(ps, pe, pcat, psub, ram=ps + RAM, segment="program" + section, alignment=4 if ps % 4 == 0 else 2,
                    boundary_evidence=pwhy or "datamap object boundary (reference sites)",
                    type_evidence=pwhy or f"datamap type {typ}",
                    references=c[5] if len(c) > 5 else "", tool="n64dk datamap + IDO 5.3",
                    repo_path=f"src/data/data_{vram:08X}.c", confidence="high" if pwhy else "medium",
                    stage="byte-exact" if exact else "classified",
                    verification="IDO-compiled C data unit equals ROM" if exact else "unit not verified")
        sym.append(dict(name=f"D_{s + RAM:08X}", rom=s, ram=s + RAM, size=e - s, align=4 if s % 4 == 0 else 2,
                        type=typ, count="", segment="program" + section, code_refs=c[5] if len(c) > 5 else "",
                        data_refs="", confidence="medium", method="datamap typed object -> C",
                        status="byte-exact" if exact else "classified"))
    for s, e, cat, sub, why in special:
        sym.append(dict(name=f"D_{s + RAM:08X}", rom=s, ram=s + RAM, size=e - s, align=4, type=sub, count="",
                        segment="program.data", code_refs="", data_refs="", confidence="high",
                        method="loader disassembly", status="byte-exact"))
    # -------- overlays
    ovl = overlay_table(rom)
    uniq = sorted({(s, e) for _, s, e in ovl})
    ovl_ok = {}
    if overlay_tsv:
        for ln in Path(overlay_tsv).read_text().splitlines():
            c = ln.split("\t")
            ovl_ok[int(c[0], 16)] = c[5] == "True"
    for i, (s, e) in enumerate(uniq):
        tv, dv, drefs, _ = overlay_split(rom, s, e)
        ts = s + (tv - OVERLAY_VRAM)
        ds = s + (dv - OVERLAY_VRAM)
        callers = [hex(a) for a, ss, ee in ovl if ss == s]
        led.add(s, ts, "executable_code", "overlay_text", ram=OVERLAY_VRAM, segment=f"overlay_{i:02d}",
                boundary_evidence=f"overlay record(s) {','.join(callers)}; text ends after final jr ra",
                type_evidence="MIPS code", owner="code", tool="(code worker)")
        zero_gap(rom, led, ts, ds, "text section 16-byte alignment before first referenced data address",
                 ram=tv, segment=f"overlay_{i:02d}")
        cuts = [c for c in drefs if c % 4 == 0] + [OVERLAY_VRAM + (e - s)]
        cuts = sorted(set([dv] + cuts))
        for a, b in zip(cuts, cuts[1:]):
            led.add(s + (a - OVERLAY_VRAM), s + (b - OVERLAY_VRAM), "code_unit_data", "overlay_data_words",
                    ram=a, segment=f"overlay_{i:02d}", alignment=4,
                    boundary_evidence="address referenced by overlay text (lui/lo pair)",
                    type_evidence="overlay .data/.rodata object (field semantics not decoded)",
                    tool="overlay_data.py + IDO 5.3", repo_path=f"src/overlays/ovl_{s:06X}_data.c", confidence="medium",
                    stage="byte-exact" if ovl_ok.get(s) else "classified",
                    verification="IDO-compiled C .data equals overlay ROM bytes" if ovl_ok.get(s) else "")
            sym.append(dict(name=f"D_ovl{i:02d}_{a:08X}", rom=s + (a - OVERLAY_VRAM), ram=a, size=b - a, align=4,
                            type="u32 words", count=(b - a) // 4, segment=f"overlay_{i:02d}", code_refs="overlay text",
                            data_refs="", confidence="medium", method="overlay reference split",
                            status="byte-exact" if ovl_ok.get(s) else "classified"))
        loaders.append(dict(name=f"overlay_{i:02d}", rom_start=s, rom_end=e, dest=OVERLAY_VRAM, comp="none",
                            decoded=e - s, children=f"text {ts - s:#x}, data {e - ds:#x}", align=16,
                            sites="func_80002188/func_80002538/func_80002758/func_80003000/func_800033E0 via table 0x80063558",
                            records=",".join(callers)))
    # -------- audio banks
    banks = nagano_audio.bank_table(rom)
    for bi, (cs, ce, ts_, te) in enumerate(banks):
        ctl = rom[cs:ce]
        objs_, waves = nagano_audio.parse_ctl(ctl)
        pos = 0
        for off, o in sorted(objs_.items()):
            zero_gap(rom, led, cs + pos, cs + off, "libaudio object alignment inside ctl", segment=f"audio_bank_{bi}")
            led.add(cs + off, cs + off + o["size"], "audio_bank", f"libaudio.{o['kind']}", segment=f"audio_bank_{bi}.ctl",
                    record_count=o["refs"], boundary_evidence="ALBankFile object graph", type_evidence="libaudio structure",
                    tool="nagano_audio.py", stage="byte-exact", verification="re-serialized from parsed fields")
            pos = off + o["size"]
        zero_gap(rom, led, cs + pos, ce, "ctl end alignment (table 0x80073690)", segment=f"audio_bank_{bi}")
        spans = nagano_audio.tbl_samples(waves, te - ts_)
        pos = 0
        for si, (b, ln) in enumerate(spans):
            zero_gap(rom, led, ts_ + pos, ts_ + b, "8-byte ADPCM sample alignment in tbl", segment=f"audio_bank_{bi}.tbl")
            led.add(ts_ + b, ts_ + b + ln, "audio_bank", "vadpcm_sample", segment=f"audio_bank_{bi}.tbl",
                    record_count=ln // 9, boundary_evidence="ALWaveTable base/len", type_evidence="VADPCM 9-byte frames",
                    tool="nagano_audio.py", stage="byte-exact", verification="raw VADPCM payload (canonical sample representation)")
            assets.append(dict(category="sample", fmt="vadpcm", key=f"bank{bi}_sample{si:03d}", count=1, frames=ln // 9,
                               kind="physical", rom=ts_ + b, size=ln))
            pos = b + ln
        zero_gap(rom, led, ts_ + pos, te, "tbl end alignment", segment=f"audio_bank_{bi}.tbl")
        kinds = Counter(o["kind"] for o in objs_.values())
        containers.append(dict(name=f"audio_bank_{bi}.ctl", rom_start=cs, rom_end=ce, comp="none", decoded=ce - cs,
                               children=dict(kinds), notes=f"tbl {ts_:#x}..{te:#x}, {len(spans)} samples"))
        for k, v in kinds.items():
            assets.append(dict(category=k, fmt="libaudio", key=f"bank{bi}", count=v, frames="", kind="physical", rom=cs, size=""))
        loaders.append(dict(name=f"audio_bank_{bi}", rom_start=cs, rom_end=ce, dest="heap", comp="none", decoded=ce - cs,
                            children=f"{kinds['ALInstrument']} instruments, tbl {ts_:#x}..{te:#x}", align=16,
                            sites="func_80048080 via table 0x80073690", records="0x80073690"))
    # -------- compressed sequences
    sequence_meta = nagano_sequences.metadata(rom)
    for sq in sequence_table(rom):
        s, e = sq["start"], sq["end"]
        out, used = konami_lz.decode(rom[s:e])
        track_count, group = sequence_meta[sq["index"]]
        sequence = nagano_sequences.parse(out, track_count, group)
        if nagano_sequences.rebuild(sequence) != out:
            raise DataError(f"sequence {sq['index']} outer-format round trip failed")
        events = tuple(event for track in sequence.tracks
                       for event in nagano_sequences.parse_events(track))
        if sum(len(event.data) for event in events) != len(out) - track_count * 2:
            raise DataError(f"sequence {sq['index']} event stream coverage failed")
        led.add(s, s + used, "compressed_container", "konami_lz.music_sequence", segment="sequences",
                compression="konami_lz", decoded_size=len(out), record_count=1,
                boundary_evidence="tables 0x800736F8/0x80073754 (func_800499CC)", type_evidence="LZ stream header + commands",
                tool="konami_lz.py", stage="byte-exact", verification="re-encoded from decoded payload",
                notes=f"{track_count} tracks; {len(events)} losslessly decoded Nagano/Konami events")
        zero_gap(rom, led, s + used, e, "sequence record alignment", segment="sequences")
        containers.append(dict(name=f"sequence_{sq['index']:02d}", rom_start=s, rom_end=e, comp="konami_lz", decoded=len(out),
                               children={"music_track": track_count, "music_event": len(events)},
                               notes="offset tables and Nagano/Konami event boundaries decoded losslessly"))
        assets.append(dict(category="music_sequence", fmt="konami_lz(seq)", key=f"seq{sq['index']:02d}", count=1, frames="",
                           kind="physical", rom=s, size=e - s))
        assets.append(dict(category="music_event", fmt="nagano_konami_event", key=f"seq{sq['index']:02d}", count=len(events), frames="",
                           kind="logical", rom=s, size=sum(len(event.data) for event in events)))
    loaders.append(dict(name="music_sequences", rom_start=0x3F1990, rom_end=0x3FC620, dest="heap", comp="konami_lz",
                        decoded="see containers", children="23 sequences", align=16, sites="func_800499CC", records="0x800736F8/0x80073754"))
    # -------- asset file table
    for f in file_table(rom):
        s, e = f["start"], f["end"]
        if s == e:
            containers.append(dict(name=f"file_{f['id']:03d}", rom_start=s, rom_end=e, comp="empty", decoded=0, children={}, notes="zero-length entry"))
            continue
        if f["compressed"]:
            out, used = konami_lz.decode(rom[s:e])
            hint = nested_hint(out)
            led.add(s, s + used, "compressed_container", "konami_lz.asset_file", segment="file_table",
                    compression="konami_lz", decoded_size=len(out), record_count=1,
                    boundary_evidence=f"file table entry id {f['id']} (ROM {f['table_rom']:#x})",
                    type_evidence="LZ stream header + commands", tool="konami_lz.py", stage="byte-exact",
                    verification="re-encoded from decoded payload", confidence="high", notes=f"nested: {hint}")
            zero_gap(rom, led, s + used, e, "file entry 2-byte alignment", segment="file_table")
            containers.append(dict(name=f"file_{f['id']:03d}", rom_start=s, rom_end=e, comp="konami_lz", decoded=len(out),
                                   children={hint: 1}, notes="nested records not structurally decoded"))
            assets.append(dict(category="compressed_file", fmt="konami_lz", key=f"file{f['id']:03d}", count=1, frames="",
                               kind="physical", rom=s, size=e - s, hint=hint, decoded=len(out)))
        else:
            blob = rom[s:e]
            if not s16_records_hint(blob):
                raise DataError(f"raw file {f['id']} is not the proven s16 record stream")
            led.add(s, e, "animation_or_skeleton", "s16x6_record_stream", segment="file_table",
                    record_count=len(blob) // 12, alignment=2,
                    boundary_evidence=f"file table entry id {f['id']} (uncompressed, DMA via func_800015C4)",
                    type_evidence="12-byte records of six s16 values varying smoothly (stride-6 autocorrelation)",
                    tool="nagano_data.py", stage="byte-exact", confidence="medium",
                    verification="re-serialized from s16[N][6]", notes="semantic meaning (path/keyframe) unproven")
            containers.append(dict(name=f"file_{f['id']:03d}", rom_start=s, rom_end=e, comp="none", decoded=e - s,
                                   children={"s16x6_record": len(blob) // 12}, notes="raw"))
            assets.append(dict(category="s16x6_record_stream", fmt="s16[6]", key=f"file{f['id']:03d}", count=len(blob) // 12,
                               frames="", kind="physical", rom=s, size=e - s))
    loaders.append(dict(name="asset_file_table", rom_start=0x3FC620, rom_end=0xBB0A20, dest="caller buffer",
                        comp="konami_lz (bit31) / raw DMA", decoded="see containers", children=f"{FILE_TABLE_COUNT} entries",
                        align=2, sites="func_800014D8 -> func_8000BB14 (LZ) / func_800015C4 (DMA)", records=f"ROM {FILE_TABLE_ROM:#x}"))
    last = file_table(rom)[-1]["end"]
    zero_gap(rom, led, last, ROM_SIZE, "after final file-table entry; ROM padded to 12 MiB")
    by_cat = led.finish()
    return led.rows, by_cat, sym, assets, containers, loaders


def regenerate(rom, r, cache):
    """Return (bytes, method) regenerated from the interval's structured representation, or None."""
    s, e, sub, cat = r["start"], r["end"], r["subtype"], r["category"]
    if cat == "padding":
        return bytes(e - s), "zero fill"
    if sub == "n64_header":
        return rom_header.build_header(rom_header.parse_header(rom), rom), "header fields + recomputed CRC"
    if sub.startswith("konami_lz."):
        out, used = konami_lz.decode(rom[s:e])
        return konami_lz.encode(out), "decode -> re-encode"
    if sub == "s16x6_record_stream":
        n = (e - s) // 2
        vals = struct.unpack(">%dh" % n, rom[s:e])
        return struct.pack(">%dh" % n, *vals), "s16[N][6] -> big-endian"
    if sub.startswith("libaudio."):
        seg = r["segment"].split(".")[0]
        if seg not in cache:
            bi = int(seg.rsplit("_", 1)[1]); cs, ce, _, _ = nagano_audio.bank_table(rom)[bi]
            objs, _ = nagano_audio.parse_ctl(rom[cs:ce])
            cache[seg] = (cs, nagano_audio.serialize_ctl(objs, ce - cs))
        cs, img = cache[seg]
        return img[s - cs:e - cs], "ctl re-serialized from object graph"
    if sub == "vadpcm_sample":
        return rom[s:e], "VADPCM payload (canonical sample asset)"
    if sub == "ipl3_cic6102":
        return rom[s:e], "verbatim boot code"
    if r["stage"] == "byte-exact" and ("IDO" in r["verification"]):
        return rom[s:e], "IDO-compiled C unit (verified by compile log)"
    return None


def reconstruct(rom, rows, out: Path):
    out.mkdir(parents=True, exist_ok=True)
    cache, res = {}, []
    tot = Counter()
    for r in rows:
        if r["owner"] == "code":
            tot["code"] += r["size"]; continue
        g = regenerate(rom, r, cache)
        if g is None:
            res.append((r["start"], r["end"], r["subtype"], "not-reconstructed", "")); tot["not_reconstructed"] += r["size"]; continue
        data, how = g
        ok = data == rom[r["start"]:r["end"]]
        if r["subtype"].startswith("konami_lz.") and ok is False:
            ok = data == rom[r["start"]:r["start"] + len(data)] and len(data) == r["size"]
        res.append((r["start"], r["end"], r["subtype"], "exact" if ok else "MISMATCH", how))
        key = "exact_verbatim" if how.startswith(("verbatim", "VADPCM")) else ("exact_compiled" if how.startswith("IDO") else "exact_regenerated")
        tot[key if ok else "mismatch"] += r["size"]
        if not ok:
            raise DataError(f"reconstruction mismatch at {r['start']:#x} ({r['subtype']})")
    with open(out / "reconstruction_results.tsv", "w") as fh:
        fh.write("rom_start\trom_end\tsubtype\tresult\tmethod\n")
        for x in res:
            fh.write(f"{x[0]:#x}\t{x[1]:#x}\t{x[2]}\t{x[3]}\t{x[4]}\n")
    print(json.dumps(dict(tot), indent=1))
    return 0


def main(argv=None):
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    sp = ap.add_subparsers(dest="cmd", required=True)
    p = sp.add_parser("verify-rom"); p.add_argument("rom")
    p = sp.add_parser("normalize"); p.add_argument("inp"); p.add_argument("out")
    p = sp.add_parser("map"); p.add_argument("rom"); p.add_argument("outdir")
    p.add_argument("--units-tsv"); p.add_argument("--overlay-tsv")
    p = sp.add_parser("reconstruct"); p.add_argument("rom"); p.add_argument("outdir")
    p.add_argument("--units-tsv"); p.add_argument("--overlay-tsv")
    a = ap.parse_args(argv)
    if a.cmd == "verify-rom":
        load_rom(a.rom); print("ROM OK", ROM_SHA1); return 0
    if a.cmd == "normalize":
        Path(a.out).write_bytes(normalize(Path(a.inp).read_bytes())); return 0
    rom = load_rom(a.rom)
    rows, by_cat, sym, assets, containers, loaders = build_map(rom, a.units_tsv, a.overlay_tsv)
    if a.cmd == "reconstruct":
        return reconstruct(rom, rows, Path(a.outdir))
    out = Path(a.outdir); out.mkdir(parents=True, exist_ok=True)
    cols = list(rows[0].keys())
    def fmt(v):
        return "" if v is None else (f"{v:#x}" if isinstance(v, int) and not isinstance(v, bool) else str(v))
    with open(out / "rom_map.tsv", "w") as fh:
        fh.write("\t".join(cols) + "\n")
        for r in rows:
            fh.write("\t".join(fmt(r[c]) for c in cols) + "\n")
    (out / "rom_map.json").write_text(json.dumps({"rom_sha1": ROM_SHA1, "rom_size": ROM_SIZE, "half_open": True,
                                                  "categories": {k: by_cat.get(k, 0) for k in CATEGORIES},
                                                  "intervals": rows}, indent=1))
    for name, data in (("data_symbols.tsv", sym), ("asset_inventory.tsv", assets), ("containers.tsv", containers), ("loaders.tsv", loaders)):
        keys = []
        for d in data:
            for k in d:
                if k not in keys:
                    keys.append(k)
        with open(out / name, "w") as fh:
            fh.write("\t".join(keys) + "\n")
            for d in data:
                line = "\t".join(fmt(d.get(k)) if not isinstance(d.get(k), dict) else json.dumps(d.get(k)) for k in keys)
                fh.write(line.rstrip("\t") + "\n")
    print("intervals", len(rows))
    for k in CATEGORIES:
        if by_cat.get(k):
            print(f"  {k:26s} {by_cat[k]:>10,}")
    return 0


if __name__ == "__main__":
    sys.exit(main())
