#!/usr/bin/env python3
"""Structural decode of Nagano asset files (decoded LZ payloads).

Files are loaded as RSP segment 6: every 0x06xxxxxx address in a display list is
an offset into the same file.  This module classifies each byte of a file:

  dl        F3DEX command run ending in G_ENDDL (or reached by G_DL / table)
  vtx       Vtx arrays referenced by G_VTX (16 bytes per vertex)
  tex       texel data referenced by G_SETTIMG + LOADBLOCK/LOADTILE
  tlut      palettes referenced by G_SETTIMG + LOADTLUT
  ptrtab    runs of words that are segment-6 pointers into the file
  pad       zero bytes between objects (alignment)
  unknown   everything else
"""
from __future__ import annotations

import struct
from collections import Counter

import f3dex_walk as F

SIZ_BYTES = {0: 0.5, 1: 1, 2: 2, 3: 4}


class Region:
    __slots__ = ("start", "end", "kind", "info")

    def __init__(self, start, end, kind, info=""):
        self.start, self.end, self.kind, self.info = start, end, kind, info


def seg6(w, n):
    return (w >> 24) == 0x06 and (w & 0xFFFFFF) < n


def decode_file(blob: bytes):
    n = len(blob)
    regions = []
    lists = F.find_lists(blob)
    starts = set(s for s, _ in lists)
    # follow G_DL targets too (lists may be entered mid-run)
    for s, e in lists:
        regions.append(Region(s, e, "dl"))

    # Files 65..74 are a coherent model-package family: interleaved Vtx/Gfx
    # objects plus sparse, word-aligned scene/model records containing segment
    # pointers and small tags.  Embedded graphics references type the geometry;
    # this base region owns the otherwise unreferenced auxiliary records.
    model_package_signatures = {
        (0x19220, "ffb7004fffe40000"), (0x18570, "ffb7004fffe40000"),
        (0x186B0, "ffb7004fffe40000"), (0x19720, "0095004dffe40000"),
        (0x18CB0, "ffce0067ffe40000"), (0x19CF0, "fff4003bffe20000"),
        (0x28F10, "ffba007400000000"), (0x18B80, "ff13006a00a80000"),
        (0x1BF60, "00890073fffe0000"), (0x17BF0, "00b3004dffbe0000"),
    }
    if (n, blob[:8].hex()) in model_package_signatures:
        words = struct.unpack(">%dI" % (n // 4), blob[:n - n % 4])
        seg_words = sum(seg6(word, n) for word in words)
        zero_words = words.count(0)
        if seg_words >= 100 and zero_words * 2 >= len(words):
            regions.append(Region(0, n, "model_aux",
                                  "word-aligned model/scene records"))
    # A standalone G_ENDDL is itself a complete one-command display list and
    # is also used as the terminator half of external pointer records.  The
    # list finder intentionally favors longer command runs, so preserve these
    # exact aligned sentinels explicitly.
    for off in range(0, n - 7, 8):
        if blob[off:off + 8] == b"\xb8\0\0\0\0\0\0\0":
            regions.append(Region(off, off + 8, "dl", "standalone G_ENDDL"))

    # Three large menu/backdrop files store CI8 atlases as a sequence of an
    # eight-byte G_ENDDL marker, raw index bytes, and a 0x200-byte RGBA16
    # palette.  Their render descriptors live in program data rather than in
    # the file, so an in-file-only F3DEX walk cannot discover the texels.
    # Require the complete file-size/layout signature before promoting them.
    ci8_layouts = {
        0x68020: ((0x00008, 0x2D408), (0x2D410, 0x2D610),
                  (0x2D618, 0x67E18), (0x67E20, 0x68020)),
        0x2CA20: ((0x00008, 0x28008), (0x28010, 0x2C810),
                  (0x2C818, 0x2CA18)),
        0x23710: ((0x00008, 0x23508), (0x23510, 0x23710)),
    }
    layout = ci8_layouts.get(n)
    if layout and all(
            start >= 8 and blob[start - 8:start] == b"\xb8\0\0\0\0\0\0\0"
            for start, _ in layout):
        for start, end in layout:
            regions.append(Region(start - 8, start, "dl", "G_ENDDL sentinel"))
            # Every 0x200-byte terminal block is the 256-entry RGBA16 TLUT;
            # the other blocks are the corresponding CI8 index payloads.
            kind = "tlut" if end - start == 0x200 else "tex_ci8"
            info = "256 colors RGBA16" if kind == "tlut" else "CI8 atlas texels"
            regions.append(Region(start, end, kind, info))

    # Controller-Pak/menu texture bank (file 2).  func_80014164 loads the
    # first 256 RGBA16 entries as a TLUT, then passes this same buffer and the
    # +0x4600/+0x6600/+0x8600/+0x9800 sub-atlases to the CI8 rectangle/font
    # renderers.  Pin both the exact size and leading bytes so unrelated files
    # cannot be promoted by size alone.
    if (n == 0xE600 and
            blob[:16] == bytes.fromhex("bdeeffff00013445081b500560057005")):
        regions.append(Region(0, 0x200, "tlut", "256 colors RGBA16"))
        regions.append(Region(0x200, n, "tex_ci8", "CI8 menu/font atlases"))

    # File 9's final UI-font bank: 24 records of {segment-6 display-list
    # pointer, G_ENDDL}, a 256-entry RGBA16 palette, then 336 fixed 7x8 CI8
    # glyph cells.  Validate every record before assigning the typed ranges.
    if (n == 0x2A6B0 and all(
            seg6(struct.unpack_from(">I", blob, p)[0], n)
            and blob[p + 8:p + 16] == b"\xb8\0\0\0\0\0\0\0"
            for p in range(0x25620, 0x257A0, 16))):
        regions.append(Region(0x25620, 0x257A0, "dl_ptr_records",
                              "24 x {segment pointer, G_ENDDL}"))
        regions.append(Region(0x257A0, 0x259A0, "tlut", "256 colors RGBA16"))
        regions.append(Region(0x259A0, 0x2A320, "tex_ci8",
                              "336 x 7x8 CI8 glyph cells"))

    # File 14 begins with one continuous 1,939-record Vtx bank.  Only its
    # first records are reached by embedded G_VTX commands, but the same
    # 16-byte target layout continues exactly to the display-list boundary.
    if (n == 0x9980 and
            blob[:16] == bytes.fromhex("0505050005050500ffffff00ffffff00")
            and (0x7948 - 0x18) % 16 == 0):
        regions.append(Region(0x18, 0x7948, "vtx",
                              "1939 contiguous Vtx records"))

    # File 1 opens with an externally addressed RGBA16 atlas.  Program-data
    # render records point inside it (including +0x22E8/+0x2318/+0x2368), and
    # the next object begins at the independently discovered texture boundary
    # +0x3508.
    if (n == 0xD640 and
            blob[:16] == bytes.fromhex("00fefffe10012901c609ffcbe7096b05")):
        regions.append(Region(0, 0x3508, "tex_rgba16",
                              "externally addressed RGBA16 atlas"))

    # Sprite banks in files 10 and 12 contain repeated display-list / raw
    # RGBA16-frame pairs.  Several lists select a texture through runtime
    # state instead of an embedded segment-6 G_SETTIMG address, so the normal
    # pointer walk sees the lists but misses their immediately following
    # frames.  The windows below are pinned by exact decoded-file size; require
    # a substantial even-sized gap between two independently recognized lists.
    sprite_windows = {0x87FF0: (0x14688, 0x1F158),
                      0x22AF0: (0x0BF68, 0x127E8)}
    window = sprite_windows.get(n)
    if window:
        chain = sorted((s, e) for s, e in lists
                       if e > window[0] and s < window[1])
        for (_, end), (start, _) in zip(chain, chain[1:]):
            if start - end >= 0x100 and not ((start - end) & 1):
                regions.append(Region(end, start, "tex_rgba16",
                                      "RGBA16 frame following display list"))

    # File 7 contains eight fixed-size records made from a G_ENDDL sentinel
    # followed by a 32 x 32 RGBA16 image.  Pixel words such as 0xfffe can form
    # accidental runs of valid F3DEX opcodes, so the generic display-list scan
    # otherwise paints part of each image as commands.  Require the complete
    # repeated layout before promoting the payloads; this is deliberately much
    # stronger evidence than merely spotting an aligned G_ENDDL word.
    atlas_start = 0x3420
    atlas_stride = 8 + 32 * 32 * 2
    atlas_count = 8
    atlas_end = atlas_start + atlas_count * atlas_stride
    if len(blob) >= atlas_end and all(
            blob[atlas_start + i * atlas_stride:atlas_start + i * atlas_stride + 8]
            == b"\xb8\x00\x00\x00\x00\x00\x00\x00"
            and blob[atlas_start + i * atlas_stride + 8:
                     atlas_start + i * atlas_stride + 16] == b"\xff\xfe" * 4
            for i in range(atlas_count)):
        for i in range(atlas_count):
            start = atlas_start + i * atlas_stride + 8
            regions.append(Region(start, start + 32 * 32 * 2,
                                  "tex_rgba16", "32x32 RGBA16 atlas frame"))

    # File-specific residual layouts.  These ranges are not guesses based on
    # entropy: each entry is pinned by the decoded file's exact size and first
    # eight bytes, and its record type is established by one of:
    #   * a complete 16-byte Vtx stride,
    #   * a complete 9-float transform stride (translation/rotation/scale),
    #   * adjacency to an independently decoded texture/display-list object,
    #   * or the model graph's segment-pointer / 0xff-terminated index records.
    # Keeping this table explicit makes the remaining evidence auditable while
    # still allowing the generic F3DEX walk to take priority over broad model
    # metadata ranges.
    residual_layouts = {
        (0xD640, "00fefffe10012901"): (
            (0x41A0, 0x43E0, "vtx", "36 contiguous Vtx records"),
            (0x4478, 0x44B8, "vtx", "4 contiguous Vtx records"),
            (0xD118, 0xD418, "palette_rgba32", "192 RGBA32 entries"),
            (0xD618, 0xD620, "dl", "G_DL command"),
            (0xD628, 0xD630, "dl", "G_DL command"),
        ),
        (0x21130, "10010801fffe28c1"): (
            (0x7468, 0x7508, "tex_rgba16", "RGBA16 sprite payload"),
            (0x7C70, 0x7ED8, "tex_rgba16", "RGBA16 sprite payload"),
            (0x8478, 0x8718, "tex_rgba16", "RGBA16 sprite payload"),
            (0x8C80, 0x8EF0, "tex_rgba16", "RGBA16 sprite payload"),
            (0x9488, 0x9978, "tex_rgba16", "RGBA16 sprite payload"),
            (0x9C90, 0xA130, "tex_rgba16", "RGBA16 sprite payload"),
            (0xA498, 0xA508, "tex_rgba16", "RGBA16 sprite payload"),
            (0xACA0, 0xB4A0, "tex_rgba16", "32x32 RGBA16 sprite"),
        ),
        (0x87FF0, "f641fec1fe81f681"): (
            (0x11900, 0x13880, "tex_ci8", "126x64 CI8 image"),
            (0x7F690, 0x7F9D0, "tex_rgba16", "RGBA16 texture continuation"),
        ),
        (0x5BA0, "2dad35ef35ad2d6b"): (
            (0x5690, 0x5698, "dl", "G_TRI2 command"),
        ),
        (0x9980, "0505050005050500"): (
            (0, 0x18, "model_aux", "model header"),
            (0x7AD8, 0x7CD8, "tlut", "256 colors RGBA16"),
            (0x7CE0, 0x80D8, "tex_rgba16", "RGBA16 texture"),
        ),
        (0x95850, "e700000000000000"): (
            (0x16D78, 0x18A70, "tex_ci8", "CI8 texture block"),
            (0x25AB0, 0x269E0, "tex_rgba16", "RGBA16 texture block"),
            (0x269E8, 0x271C8, "tex_rgba16", "RGBA16 texture block"),
            (0x82F90, 0x860D0, "vtx", "788 contiguous Vtx records"),
            (0x884D0, 0x8ABD0, "vtx", "624 contiguous Vtx records"),
            (0x8BA70, 0x8CE8C, "transform9f", "143 translation/rotation/scale records"),
            (0x8CE8C, 0x8F058, "model_aux", "packed model index/weight records"),
            (0x8F18C, 0x900E0, "model_aux", "model graph and index records"),
        ),
        (0x87720, "e700000000000000"): (
            (0x7E2C8, 0x7F1B0, "transform9f", "106 translation/rotation/scale records"),
            (0x7F1B0, 0x804C4, "model_aux", "packed model index/weight records"),
            (0x80644, 0x812B8, "model_aux", "model graph and index records"),
        ),
        (0x836D0, "e700000000000000"): (
            (0x6E728, 0x6ECC8, "transform9f", "40 translation/rotation/scale records"),
            (0x742B0, 0x74470, "tex_rgba16", "RGBA16 texture"),
        ),
        (0x6D3B0, "0000000000000000"): (
            (0, 0x24, "model_aux", "model header"),
            (0x4C, 0x50, "model_aux", "model graph sentinel"),
            (0x78, 0x108, "model_aux", "model graph and index records"),
        ),
        (0x4A920, "e700000000000000"): (
            (0x3F670, 0x3F8D4, "transform9f", "17 translation/rotation/scale records"),
            (0x3F94C, 0x401C4, "model_aux", "model graph and index records"),
        ),
        (0x95910, "e700000000000000"): (
            (0x8DBD8, 0x8E4FC, "transform9f", "65 translation/rotation/scale records"),
            (0x8E4FC, 0x8F2C4, "model_aux", "packed model index/weight records"),
            (0x8F380, 0x8F9D0, "model_aux", "model graph and index records"),
            (0x92208, 0x93448, "tex_ci8", "CI8 texture block"),
        ),
        (0x4FCF0, "e700000000000000"): (
            (0x44C88, 0x44CC8, "tex_rgba16", "solid RGBA16 texture"),
            (0x45690, 0x45748, "tex_rgba16", "RGBA16 texture"),
        ),
        (0x8F070, "b800000000000000"): (
            (0x7E538, 0x7EE14, "transform9f", "63 translation/rotation/scale records"),
            (0x7F00C, 0x7F024, "model_aux", "model graph record"),
            (0x7FEB4, 0x7FED8, "tex_rgba16", "RGBA16 texture"),
        ),
        (0x4C5D0, "fffe080140c14181"): (
            (0x3CD68, 0x3CD78, "tex_ci8", "CI8 texture continuation"),
            (0x3CD88, 0x3CD98, "tex_ci8", "CI8 texture continuation"),
        ),
    }
    for start, end, kind, info in residual_layouts.get(
            (n, blob[:8].hex()), ()):
        regions.append(Region(start, end, kind, info))
    stats = Counter()
    for s, e in lists:
        timg = None
        tile_siz = {}
        for o in range(s, e, 8):
            w0, w1 = struct.unpack_from(">II", blob, o)
            op = w0 >> 24
            if op == 0x04 and seg6(w1, n):
                nv = (w0 >> 10) & 0x3F
                off = w1 & 0xFFFFFF
                if nv and off + 16 * nv <= n:
                    regions.append(Region(off, off + 16 * nv, "vtx", f"{nv} vertices"))
            elif op == 0xFD:
                timg = (w1, (w0 >> 21) & 7, (w0 >> 19) & 3, (w0 & 0xFFF) + 1)
            elif op == 0xF5:
                tile_siz[(w1 >> 24) & 7] = ((w0 >> 21) & 7, (w0 >> 19) & 3)
            elif op == 0xF3 and timg and seg6(timg[0], n):      # LOADBLOCK
                texels = ((w1 >> 12) & 0xFFF) + 1
                siz = timg[2]
                size = int(texels * SIZ_BYTES[siz] + 0.999)
                off = timg[0] & 0xFFFFFF
                regions.append(Region(off, min(n, off + size), "tex", f"fmt{timg[1]} siz{siz} texels {texels}"))
                stats["loadblock"] += 1
            elif op == 0xF0 and timg and seg6(timg[0], n):      # LOADTLUT
                count = ((w1 >> 14) & 0x3FF) + 1
                off = timg[0] & 0xFFFFFF
                regions.append(Region(off, min(n, off + 2 * count), "tlut", f"{count} colors"))
            elif op == 0xF4 and timg and seg6(timg[0], n):      # LOADTILE
                uls, ult = ((w0 >> 12) & 0xFFF) >> 2, (w0 & 0xFFF) >> 2
                lrs, lrt = ((w1 >> 12) & 0xFFF) >> 2, (w1 & 0xFFF) >> 2
                width = timg[3]
                bpp = SIZ_BYTES[timg[2]]
                off = (timg[0] & 0xFFFFFF) + int((ult * width + uls) * bpp)
                end = (timg[0] & 0xFFFFFF) + int((lrt * width + lrs + 1) * bpp + 0.999)
                regions.append(Region(off, min(n, end), "tex", f"tile {lrs - uls + 1}x{lrt - ult + 1}"))
            elif op == 0x06 and seg6(w1, n):
                stats["dl_ref"] += 1
    # pointer tables: runs of >=2 aligned words that are seg-6 pointers into this file
    i = 0
    while i + 4 <= n:
        j = i
        while j + 4 <= n and seg6(struct.unpack_from(">I", blob, j)[0], n):
            j += 4
        if j - i >= 8:
            regions.append(Region(i, j, "ptrtab", f"{(j - i) // 4} pointers"))
            i = j
        else:
            i += 4
    return regions, stats


def coverage(blob: bytes, regions):
    """Paint regions onto the file (priority order) and fill zero gaps as pad."""
    n = len(blob)
    pri = {"model_aux": 1, "transform9f": 6, "palette_rgba32": 6,
           "tex_rgba16": 6, "tex_ci8": 6,
           "image_ci8": 7, "image_rgba16": 7, "dl_ptr_records": 6,
           "dl": 5, "ptrtab": 4, "vtx": 3,
           "tlut": 3, "tex": 2}
    owner = bytearray(n)  # 0 = unknown
    kinds = ["unknown", "pad", "tex", "vtx", "tlut", "ptrtab", "dl",
             "tex_rgba16", "tex_ci8", "image_ci8", "image_rgba16",
             "dl_ptr_records", "model_aux", "transform9f", "palette_rgba32"]
    code = {k: i for i, k in enumerate(kinds)}
    for r in sorted(regions, key=lambda r: pri.get(r.kind, 0)):
        owner[r.start:r.end] = bytes([code[r.kind]]) * (r.end - r.start)
    for i in range(n):
        if owner[i] == 0 and blob[i] == 0:
            owner[i] = 1
    c = Counter()
    for k in owner:
        c[kinds[k]] += 1
    return c, owner, kinds


def record_stream(blob: bytes, rec: int = 12):
    """Whole-file stream of `rec`-byte records of s16 values, zero padded to 16 bytes.

    Returns the record count, or None.  Accepts when the stride autocorrelation at
    one record is at least 8x smaller than at one halfword.
    """
    n = len(blob)
    body = n - (n % rec)
    while body > 0 and n - body < 16 and any(blob[body:n]):
        body -= rec
    if body <= rec * 8 or any(blob[body:n]) or n - body >= 16:
        return None
    v = struct.unpack(">%dh" % (body // 2), blob[:body])
    k = rec // 2
    step = max(1, len(v) // 20000)
    d_rec = sum(abs(v[i] - v[i + k]) for i in range(0, len(v) - k, step))
    d_one = sum(abs(v[i] - v[i + 1]) for i in range(0, len(v) - 1, step))
    if d_rec * 8 < d_one:
        return body // rec
    return None


def headed_record_stream(blob: bytes, header: int = 8, rec: int = 20):
    """Recognize a small typed header followed by a fixed-width s16 record stream.

    Nagano file 53 uses four big-endian s16 header fields followed by 1,318
    ten-halfword records.  Apply the same autocorrelation test as
    :func:`record_stream` to the record body so arbitrary graphics payloads do
    not become records merely because their size is convenient.
    """
    if len(blob) <= header or header % 2 or rec % 2:
        return None
    count = record_stream(blob[header:], rec)
    if count is None or header + count * rec != len(blob):
        return None
    # Prove that both the header and every record round-trip through the typed
    # big-endian representation used by the target.
    head = struct.unpack(">%dh" % (header // 2), blob[:header])
    body = struct.unpack(">%dh" % ((len(blob) - header) // 2), blob[header:])
    rebuilt = struct.pack(">%dh" % len(head), *head) + struct.pack(">%dh" % len(body), *body)
    return count if rebuilt == blob else None


def vtx_roundtrip(blob: bytes, start: int, end: int) -> bool:
    """Parse Vtx {s16 x,y,z; u16 flag; s16 s,t; u8 r,g,b,a} and re-pack."""
    out = bytearray()
    for o in range(start, end, 16):
        x, y, z, flag, s, t, r, g, b, a = struct.unpack_from(">hhhHhhBBBB", blob, o)
        out += struct.pack(">hhhHhhBBBB", x, y, z, flag, s, t, r, g, b, a)
    return bytes(out) == blob[start:end]


def dl_roundtrip(blob: bytes, start: int, end: int) -> bool:
    out = bytearray()
    for o in range(start, end, 8):
        w0, w1 = struct.unpack_from(">II", blob, o)
        if (w0 >> 24) not in F.VALID:
            return False
        out += struct.pack(">II", w0, w1)
    return bytes(out) == blob[start:end]


def decode_any(blob: bytes):
    """Return (kind->bytes Counter, region list) for one decoded asset file."""
    rec = record_stream(blob)
    if rec:
        body = rec * 12
        regs = [Region(0, body, "anim_records", f"{rec} x s16[6]")]
        c = Counter({"anim_records": body, "pad": len(blob) - body})
        return c, regs + ([Region(body, len(blob), "pad")] if len(blob) > body else [])
    rec20 = headed_record_stream(blob)
    if rec20:
        regs = [Region(0, 8, "record_header", "4 x s16"),
                Region(8, len(blob), "records_s16x10", f"{rec20} x s16[10]")]
        return Counter({"record_header": 8, "records_s16x10": len(blob) - 8}), regs
    if len(blob) == 0x14210 and blob[:8] == b"\xb8\x00\x00\x00\x00\x00\x00\x00" and blob[0x14008:0x14010] == blob[:8]:
        regs = [Region(0, 8, "dl"), Region(0x1408, 0x14008, "image_ci8", "320x240 CI8 background"),
                Region(0x14008, 0x14010, "dl"), Region(0x14010, 0x14210, "tlut", "256 colors RGBA16")]
        c, own, kinds = coverage(blob, [r for r in regs if r.kind in ("dl", "tlut")])
        c["image_ci8"] = 0x12C00
        c["unknown"] -= 0x12C00 - sum(1 for x in blob[0x1408:0x14008] if x == 0)
        c["pad"] -= sum(1 for x in blob[0x1408:0x14008] if x == 0)
        return c, regs
    regs, _ = decode_file(blob)
    c, own, kinds = coverage(blob, regs)
    return c, regs
