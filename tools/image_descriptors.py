#!/usr/bin/env python3
"""Full-screen / backdrop image descriptors in main-segment data.

The object template table D_8006BAF0 (consumer func_8002C51C) contains 28-byte
image records that name an asset file explicitly:

    +0x00 u32  file id
    +0x04 u32  pointer to the file's load-list entry {0x40000000 | id, 0}
    +0x08 u32  segment-6 pointer A
    +0x0C u32  segment-6 pointer B
    +0x10 u16  flags (0x8000 = colour-indexed)
    +0x12 u16  width
    +0x14 u16  height

Colour-indexed records (flags 0x8000) use A = 256-entry RGBA16 TLUT and
B = CI8 texels; direct-colour records (flags 0) use A = RGBA16 texels, B = 0.
Every record found by `find` satisfies three independent checks: the load
entry names the same file, both pointers fall inside that file, and
width * height * bytes-per-pixel fits inside the G_ENDDL-delimited block that
starts at the image pointer.
"""
from __future__ import annotations

import csv
import struct
from pathlib import Path

ENDDL = b"\xb8\x00\x00\x00\x00\x00\x00\x00"
VRAM_TO_ROM = 0x7FFFF400


def _word(rom: bytes, off: int) -> int:
    return struct.unpack_from(">I", rom, off)[0]


DATA_CATEGORIES = ("initialized_data", "readonly_data", "code_unit_data")


def data_ranges(rom_map: Path):
    """Data intervals of the program segment and the overlays (ROM offsets)."""
    with rom_map.open() as stream:
        for row in csv.DictReader(stream, delimiter="\t"):
            if row["category"] in DATA_CATEGORIES:
                yield int(row["start"], 0), int(row["end"], 0)


def enddl_blocks(blob: bytes):
    """[(marker_offset, block_start, block_end)] for each 8-aligned G_ENDDL marker."""
    marks = [o for o in range(0, len(blob) - 7, 8) if blob[o:o + 8] == ENDDL]
    out = []
    for i, m in enumerate(marks):
        end = marks[i + 1] if i + 1 < len(marks) else len(blob)
        out.append((m, m + 8, end))
    return out


def find(rom: bytes, files: dict[int, bytes], rom_map: Path):
    """Return {file_id: [descriptor dict]} for every verified image record."""
    found: dict[int, list[dict]] = {}
    seen = set()
    for start, end in data_ranges(rom_map):
        for off in range(start, end - 0x18, 4):
            fid = _word(rom, off)
            if fid not in files or fid in (0,):
                continue
            entry = _word(rom, off + 4)
            if not 0x80000000 <= entry < 0x80400000:
                continue
            eoff = entry - VRAM_TO_ROM
            if not 0 <= eoff < len(rom) - 4 or (_word(rom, eoff) & 0x0FFFFFFF) != fid:
                continue
            a, b = _word(rom, off + 8), _word(rom, off + 12)
            flags, width, height = struct.unpack_from(">HHH", rom, off + 16)
            blob = files[fid]
            n = len(blob)
            seg6 = lambda w: (w >> 24) == 6 and (w & 0xFFFFFF) < n
            if flags == 0x8000 and seg6(a) and seg6(b):
                tlut, image, bpp, fmt = a & 0xFFFFFF, b & 0xFFFFFF, 1, "ci8"
            elif flags == 0 and seg6(a) and b == 0:
                tlut, image, bpp, fmt = None, a & 0xFFFFFF, 2, "rgba16"
            else:
                continue
            if not width or not height:
                continue
            blocks = {s: e for _, s, e in enddl_blocks(blob)}
            if image not in blocks or width * height * bpp > blocks[image] - image:
                continue
            if tlut is not None and tlut not in blocks:
                continue
            key = (fid, image, tlut, width, height, fmt)
            if key in seen:
                continue
            seen.add(key)
            found.setdefault(fid, []).append({
                "record_rom": off, "file": fid, "format": fmt, "bpp": bpp,
                "image": image, "image_block_end": blocks[image], "tlut": tlut,
                "tlut_block_end": blocks.get(tlut) if tlut is not None else None,
                "width": width, "height": height,
            })
    return found


def row_continuity(blob: bytes, image: int, width: int, bpp: int, rows: int, extra: int) -> float:
    """Mean fraction of differing bytes between vertically adjacent rows in the
    `extra` rows that follow the descriptor height (lower = image continues)."""
    stride = width * bpp
    diffs = 0
    total = 0
    for r in range(rows - 1, rows + extra - 1):
        a = blob[image + r * stride:image + (r + 1) * stride]
        b = blob[image + (r + 1) * stride:image + (r + 2) * stride]
        diffs += sum(x != y for x, y in zip(a, b))
        total += stride
    return diffs / total if total else 0.0
