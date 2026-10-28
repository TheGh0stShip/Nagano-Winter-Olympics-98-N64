#!/usr/bin/env python3
"""libaudio ALBankFile (.ctl) / wave table (.tbl) parser and exact re-serializer.

The bank list comes from the retail table at RAM 0x80073690 (ROM 0x74290):
ctl starts[4], ctl ends[4], tbl starts[4]; the last tbl ends at the
first compressed sequence (table 0x800736F8).  Structures
are read with explicit big-endian helpers; each object keeps its file offset
so the container can be rebuilt byte-for-byte and compared with the ROM.
"""
from __future__ import annotations

import struct

RAM_BASE = 0x7FFFF400  # RAM = ROM + 0x7FFFF400 for the initial program image


class AudioError(ValueError):
    pass


def u8(b, o):
    if o + 1 > len(b):
        raise AudioError(f"read past end at {o:#x}")
    return b[o]


def s16(b, o):
    if o + 2 > len(b):
        raise AudioError(f"read past end at {o:#x}")
    return struct.unpack_from(">h", b, o)[0]


def u32(b, o):
    if o + 4 > len(b):
        raise AudioError(f"read past end at {o:#x}")
    return struct.unpack_from(">I", b, o)[0]


def bank_table(rom: bytes):
    """Return [(ctl_start, ctl_end, tbl_start, tbl_end)] from the retail table."""
    t = 0x80073690 - RAM_BASE
    ctl_s = [u32(rom, t + 4 * i) for i in range(4)]
    ctl_e = [u32(rom, t + 16 + 4 * i) for i in range(4)]
    tbl_s = [u32(rom, t + 32 + 4 * i) for i in range(4)]
    # the last wave table ends where the sequence table's first record begins
    tbl_e = tbl_s[1:] + [u32(rom, 0x800736F8 - RAM_BASE)]
    return list(zip(ctl_s, ctl_e, tbl_s, tbl_e))


def parse_ctl(ctl: bytes):
    """Parse one ALBankFile; return dict of objects keyed by offset."""
    objs = {}

    def claim(off, size, kind, fields):
        if off in objs:
            if objs[off]["kind"] != kind:
                raise AudioError(f"conflicting object kinds at {off:#x}")
            objs[off]["refs"] += 1
            return False
        if off < 0 or off + size > len(ctl):
            raise AudioError(f"{kind} at {off:#x} outside container")
        objs[off] = {"kind": kind, "size": size, "fields": fields, "refs": 1}
        return True

    if ctl[:2] != b"B1":
        raise AudioError("bad ALBankFile revision")
    nbanks = s16(ctl, 2)
    claim(0, 4 + 4 * nbanks, "ALBankFile", {"revision": 0x4231, "banks": [u32(ctl, 4 + 4 * i) for i in range(nbanks)]})
    waves = []
    for boff in objs[0]["fields"]["banks"]:
        ninst = s16(ctl, boff)
        f = {"instCount": ninst, "flags": u8(ctl, boff + 2), "pad": u8(ctl, boff + 3), "sampleRate": u32(ctl, boff + 4),
             "percussion": u32(ctl, boff + 8), "insts": [u32(ctl, boff + 12 + 4 * i) for i in range(ninst)]}
        claim(boff, 12 + 4 * ninst, "ALBank", f)
        insts = list(f["insts"]) + ([f["percussion"]] if f["percussion"] else [])
        for ioff in insts:
            nsnd = s16(ctl, ioff + 14)
            raw = ctl[ioff:ioff + 14]
            fi = {"head": raw.hex(), "soundCount": nsnd, "sounds": [u32(ctl, ioff + 16 + 4 * i) for i in range(nsnd)]}
            if not claim(ioff, 16 + 4 * nsnd, "ALInstrument", fi):
                continue
            for soff in fi["sounds"]:
                fs = {"env": u32(ctl, soff), "keymap": u32(ctl, soff + 4), "wave": u32(ctl, soff + 8),
                      "tail": ctl[soff + 12:soff + 16].hex()}
                if not claim(soff, 16, "ALSound", fs):
                    continue
                claim(fs["env"], 16, "ALEnvelope", {"raw": ctl[fs["env"]:fs["env"] + 16].hex()})
                claim(fs["keymap"], 6, "ALKeyMap", {"raw": ctl[fs["keymap"]:fs["keymap"] + 6].hex()})
                w = fs["wave"]
                fw = {"base": u32(ctl, w), "len": u32(ctl, w + 4), "type": u8(ctl, w + 8), "flags": u8(ctl, w + 9),
                      "pad": ctl[w + 10:w + 12].hex(), "loop": u32(ctl, w + 12), "book": u32(ctl, w + 16)}
                if claim(w, 20, "ALWaveTable", fw):
                    waves.append(fw)
                    if fw["type"] != 0:
                        raise AudioError(f"non-ADPCM wave at {w:#x}")
                    if fw["book"]:
                        order, npred = u32(ctl, fw["book"]), u32(ctl, fw["book"] + 4)
                        if not (1 <= order <= 8 and 1 <= npred <= 16):
                            raise AudioError(f"bad ADPCM book at {fw['book']:#x}")
                        size = 8 + 2 * 8 * order * npred
                        claim(fw["book"], size, "ALADPCMBook", {"raw": ctl[fw["book"]:fw["book"] + size].hex()})
                    if fw["loop"]:
                        claim(fw["loop"], 0x30, "ALADPCMloop", {"raw": ctl[fw["loop"]:fw["loop"] + 0x30].hex()})
    return objs, waves


def serialize_ctl(objs, size: int) -> bytes:
    """Rebuild a ctl image from parsed objects; gaps are zero alignment."""
    out = bytearray(size)
    for off, o in sorted(objs.items()):
        k, f = o["kind"], o["fields"]
        if k == "ALBankFile":
            b = struct.pack(">hh", f["revision"], len(f["banks"])) + b"".join(struct.pack(">I", x) for x in f["banks"])
        elif k == "ALBank":
            b = struct.pack(">hBBII", f["instCount"], f["flags"], f["pad"], f["sampleRate"], f["percussion"]) + \
                b"".join(struct.pack(">I", x) for x in f["insts"])
        elif k == "ALInstrument":
            b = bytes.fromhex(f["head"]) + struct.pack(">h", f["soundCount"]) + b"".join(struct.pack(">I", x) for x in f["sounds"])
        elif k == "ALSound":
            b = struct.pack(">III", f["env"], f["keymap"], f["wave"]) + bytes.fromhex(f["tail"])
        elif k == "ALWaveTable":
            b = struct.pack(">IIBB", f["base"], f["len"], f["type"], f["flags"]) + bytes.fromhex(f["pad"]) + \
                struct.pack(">II", f["loop"], f["book"])
        else:
            b = bytes.fromhex(f["raw"])
        if len(b) != o["size"]:
            raise AudioError(f"size mismatch rebuilding {k} at {off:#x}")
        if any(out[off:off + len(b)]):
            raise AudioError(f"overlapping objects at {off:#x}")
        out[off:off + len(b)] = b
    return bytes(out)


def tbl_samples(waves, tbl_len: int):
    """Return sorted unique (base, len) sample spans inside one tbl."""
    spans = sorted({(w["base"], w["len"]) for w in waves})
    for base, length in spans:
        if base + length > tbl_len:
            raise AudioError(f"sample {base:#x}+{length:#x} beyond tbl {tbl_len:#x}")
    return spans
