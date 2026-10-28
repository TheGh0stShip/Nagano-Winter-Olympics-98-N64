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
    pri = {"dl": 5, "ptrtab": 4, "vtx": 3, "tlut": 3, "tex": 2}
    owner = bytearray(n)  # 0 = unknown
    kinds = ["unknown", "pad", "tex", "vtx", "tlut", "ptrtab", "dl"]
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
