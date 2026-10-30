#!/usr/bin/env python3
"""Model-slot arrays in the model-package asset family (files 65..74).

Each array is a run of fixed 88-byte (0x58) slots:

    +0x00 u32  header: entry count (1..7) in bits 31..24, bits 23..0 zero
    +0x04 entry[7], 12 bytes each:
          u32 param   (<= 0xFFFF; observed 250..309)
          u32 dl      segment-6 pointer to a display list in the same file
          u32 data    0, or a segment-6 pointer into the same file (target
                      semantics unproven: it lands on Vtx, display lists, or
                      inside other slot runs)

Entries at or beyond the count are all zero.  An all-zero slot is an empty
slot.  A run is accepted only when every slot validates, at least four slots
are populated, and every populated entry's `dl` pointer lands on a display
list found by the F3DEX walker (any 8-aligned entry point inside a walker
list counts, because lists are entered mid-run).  `parse`/`serialize` round-trip every byte.
"""
from __future__ import annotations

import struct

SLOT = 88
ENTRIES = 7


def _word(blob: bytes, off: int) -> int:
    return struct.unpack_from(">I", blob, off)[0]


def slot_kind(blob: bytes, off: int):
    """'rec', 'zero', or None when the 88 bytes at `off` are not a valid slot."""
    n = len(blob)
    if off + SLOT > n:
        return None
    header = _word(blob, off)
    if header == 0:
        return "zero" if not any(blob[off:off + SLOT]) else None
    count = header >> 24
    if header & 0xFFFFFF or not 1 <= count <= ENTRIES:
        return None
    seg = lambda w: (w >> 24) == 0x06 and (w & 0xFFFFFF) < n
    for k in range(ENTRIES):
        param, dl, data = struct.unpack_from(">III", blob, off + 4 + 12 * k)
        if k < count:
            if param > 0xFFFF or not seg(dl) or not (data == 0 or seg(data)):
                return None
        elif param or dl or data:
            return None
    return "rec"


def dl_entry_points(lists):
    """Every 8-aligned offset inside each walker-found display list."""
    points = set()
    for start, end in lists:
        points.update(range(start, end, 8))
    return points


def find_runs(blob: bytes, dl_starts=None, min_records: int = 4):
    """[(start, end, records, empty)] for each maximal valid slot run.

    `dl_starts` is a set of valid display-list entry points (see dl_entry_points).
    """
    runs = []
    off = 0
    n = len(blob)
    while off + SLOT <= n:
        if slot_kind(blob, off) != "rec":
            off += 4
            continue
        start, records, empty = off, 0, 0
        while (kind := slot_kind(blob, off)) is not None:
            records += kind == "rec"
            empty += kind == "zero"
            off += SLOT
        # trailing empty slots belong to the array only if more records follow;
        # trim them so an unrelated zero run is not absorbed.
        while off > start and not any(blob[off - SLOT:off]):
            off -= SLOT
            empty -= 1
        # A run is a whole number of 64-slot groups: restore trailing empty
        # slots up to the next group boundary when they are present and zero.
        group_end = start + -(-(off - start) // (64 * SLOT)) * (64 * SLOT)
        if group_end <= n and not any(blob[off:group_end]):
            empty += (group_end - off) // SLOT
            off = group_end
        if records >= min_records and (dl_starts is None or _dls_ok(blob, start, off, dl_starts)):
            runs.append((start, off, records, empty))
        else:
            off = start + 4
    return runs


def _dls_ok(blob: bytes, start: int, end: int, dl_starts) -> bool:
    for off in range(start, end, SLOT):
        count = _word(blob, off) >> 24
        for k in range(count):
            dl = _word(blob, off + 8 + 12 * k) & 0xFFFFFF
            if dl not in dl_starts:
                return False
    return True


def parse(blob: bytes, start: int, end: int):
    slots = []
    for off in range(start, end, SLOT):
        count = _word(blob, off) >> 24
        entries = [struct.unpack_from(">III", blob, off + 4 + 12 * k) for k in range(count)]
        slots.append([(param, dl & 0xFFFFFF, data & 0xFFFFFF if data else 0) for param, dl, data in entries])
    return slots


def serialize(slots) -> bytes:
    out = bytearray()
    for entries in slots:
        out += struct.pack(">I", len(entries) << 24)
        for param, dl, data in entries:
            out += struct.pack(">III", param, 0x06000000 | dl, (0x06000000 | data) if data else 0)
        out += bytes(12 * (ENTRIES - len(entries)))
    return bytes(out)


def roundtrip(blob: bytes, start: int, end: int) -> bool:
    return serialize(parse(blob, start, end)) == blob[start:end]


GROUP = 64 * SLOT  # 0x1600: a slot run is a sequence of 64-slot groups


def group_starts(start: int, end: int):
    return list(range(start, end, GROUP))


def find_group_tables(blob: bytes, runs):
    """[(start, end, run_start, pairs)] for each slot-group pointer table.

    A table is `pairs` x {u32 word, seg6 -> group i of one slot run} followed by
    a {0, 0} terminator, where pair i points exactly at that run's group i and
    `pairs` equals the run's group count.  The first word of each pair is kept
    as an unproven u32 (it may point into this file or past its end).
    """
    n = len(blob)
    tables = []
    for run_start, run_end, _, _ in runs:
        starts = group_starts(run_start, run_end)
        want = 0x06000000 | starts[0]
        for off in range(0, n - 8 * (len(starts) + 1) + 1, 4):
            if _word(blob, off + 4) != want:
                continue
            if all(_word(blob, off + 8 * i + 4) == 0x06000000 | g for i, g in enumerate(starts)):
                end = off + 8 * len(starts)
                if _word(blob, end) == 0 and _word(blob, end + 4) == 0:
                    tables.append((off, end + 8, run_start, len(starts)))
    return sorted(tables)


def table_roundtrip(blob: bytes, start: int, end: int) -> bool:
    words = struct.unpack_from(">%dI" % ((end - start) // 4), blob, start)
    return struct.pack(">%dI" % len(words), *words) == blob[start:end] and words[-2:] == (0, 0)
