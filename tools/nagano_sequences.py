#!/usr/bin/env python3
"""Parse the proven outer container of Nagano music sequences.

func_80049A78 reads a track count from D_80074680 and relocates the leading
big-endian u16 offsets against the decoded buffer.  The custom bytecode inside
each bounded track is intentionally left uninterpreted here.
"""
from __future__ import annotations

import struct
from dataclasses import dataclass

META_ROM = 0x75280
SEQUENCE_COUNT = 23


class SequenceError(ValueError):
    pass


@dataclass(frozen=True)
class Track:
    index: int
    start: int
    end: int
    data: bytes


@dataclass(frozen=True)
class Sequence:
    track_count: int
    group: int
    offsets: tuple[int, ...]
    tracks: tuple[Track, ...]


def metadata(rom: bytes) -> tuple[tuple[int, int], ...]:
    raw = rom[META_ROM:META_ROM + SEQUENCE_COUNT * 2]
    if len(raw) != SEQUENCE_COUNT * 2:
        raise SequenceError("truncated sequence metadata table")
    return tuple(zip(raw[::2], raw[1::2]))


def parse(payload: bytes, track_count: int, group: int = 0) -> Sequence:
    header_size = track_count * 2
    if not 1 <= track_count <= 32 or len(payload) < header_size:
        raise SequenceError("invalid track count or truncated offset table")
    offsets = struct.unpack_from(f">{track_count}H", payload)
    if offsets[0] != header_size:
        raise SequenceError("first track does not follow the offset table")
    if any(a >= b for a, b in zip(offsets, offsets[1:])):
        raise SequenceError("track offsets are not strictly increasing")
    if offsets[-1] >= len(payload):
        raise SequenceError("final track begins outside the payload")
    ends = offsets[1:] + (len(payload),)
    tracks = tuple(Track(i, start, end, payload[start:end])
                   for i, (start, end) in enumerate(zip(offsets, ends)))
    return Sequence(track_count, group, offsets, tracks)


def rebuild(sequence: Sequence) -> bytes:
    return (struct.pack(f">{sequence.track_count}H", *sequence.offsets) +
            b"".join(track.data for track in sequence.tracks))
