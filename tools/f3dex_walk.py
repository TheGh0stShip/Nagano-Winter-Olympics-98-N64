#!/usr/bin/env python3
"""Structural F3DEX 1.21 display-list walker for decoded Nagano asset files.

A display list here is a maximal run of 8-byte-aligned commands whose opcodes
are all valid F3DEX/RDP opcodes and which ends in G_ENDDL (0xB8000000 00000000).
Counts are candidate structural decodes; they are reported separately from
physical byte coverage and are not a semantic model/texture decode.
"""
from __future__ import annotations

import struct
from collections import Counter

VALID = {0x00, 0x01, 0x03, 0x04, 0x06, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xB6, 0xB7, 0xB8, 0xB9, 0xBA, 0xBB, 0xBC,
         0xBD, 0xBE, 0xBF, 0xC0, 0xE4, 0xE5, 0xE6, 0xE7, 0xE8, 0xE9, 0xEA, 0xEB, 0xEC, 0xED, 0xEE, 0xEF, 0xF0,
         0xF1, 0xF2, 0xF3, 0xF4, 0xF5, 0xF6, 0xF7, 0xF8, 0xF9, 0xFA, 0xFB, 0xFC, 0xFD, 0xFE, 0xFF}
ENDDL = b"\xb8\x00\x00\x00\x00\x00\x00\x00"
FMT = {0: "RGBA", 1: "YUV", 2: "CI", 3: "IA", 4: "I"}
SIZ = {0: 4, 1: 8, 2: 16, 3: 32}


def find_lists(blob: bytes):
    lists = []
    i = 0
    n = len(blob) - len(blob) % 8
    while True:
        j = blob.find(ENDDL, i)
        if j < 0 or j >= n:
            break
        if j % 8:
            i = j + 1
            continue
        k = j
        while k - 8 >= 0 and blob[k - 8] in VALID and blob[k - 8] != 0xB8:
            k -= 8
        if (j - k) // 8 >= 2:
            lists.append((k, j + 8))
        i = j + 8
    return lists


def walk(blob: bytes, start: int, end: int, stats: Counter, textures: Counter):
    tile_fmt = {}
    for o in range(start, end, 8):
        w0, w1 = struct.unpack_from(">II", blob, o)
        op = w0 >> 24
        stats["commands"] += 1
        if op == 0x04:
            nv = (w0 >> 10) & 0x3F  # F3DEX: n in bits 10..15
            stats["vtx_commands"] += 1
            stats["vertices_loaded"] += nv
        elif op == 0xBF:
            stats["tri1"] += 1
            stats["triangles"] += 1
        elif op == 0xB1:
            stats["tri2"] += 1
            stats["triangles"] += 2
        elif op == 0xFD:
            stats["settimg"] += 1
        elif op == 0xF5:
            fmt, siz, tile = (w0 >> 21) & 7, (w0 >> 19) & 3, (w1 >> 24) & 7
            tile_fmt[tile] = (FMT.get(fmt, f"fmt{fmt}"), SIZ[siz])
        elif op == 0xF2:
            tile = (w1 >> 24) & 7
            w = ((w1 >> 12) & 0xFFF) // 4 + 1
            h = (w1 & 0xFFF) // 4 + 1
            if tile in tile_fmt:
                f, s = tile_fmt[tile]
                textures[f"{f}{s} {w}x{h}"] += 1
        elif op == 0xF0:
            stats["loadtlut"] += 1
        elif op == 0x06:
            stats["dl_calls"] += 1
        elif op == 0x01:
            stats["matrix_loads"] += 1


def analyze(blob: bytes):
    stats, textures = Counter(), Counter()
    lists = find_lists(blob)
    for s, e in lists:
        walk(blob, s, e, stats, textures)
    stats["display_lists"] = len(lists)
    stats["dl_bytes"] = sum(e - s for s, e in lists)
    return stats, textures
