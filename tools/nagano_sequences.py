#!/usr/bin/env python3
"""Parse Nagano's Konami music sequences.

func_80049A78 reads a track count from D_80074680 and relocates the leading
big-endian u16 offsets against the decoded buffer.  Track events use Konami's
Nagano sequence grammar: bytes below 0xd0 encode notes/rests with inherited
duration and length fields, while 0xd0..0xff are control commands.
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
class Event:
    start: int
    end: int
    kind: str
    name: str
    opcode: int
    parameters: tuple[int, ...]
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


COMMAND_SIZES = {
    0xd0: 2, 0xd1: 3, 0xd2: 2, 0xd3: 3, 0xd4: 4, 0xd5: 2,
    0xd6: 3, 0xd7: 3, 0xd8: 2, 0xd9: 2, 0xda: 3,
    0xdd: 2, 0xde: 3, 0xdf: 2, 0xe0: 2, 0xe1: 4, 0xe2: 2,
    0xe3: 4, 0xe4: 4, 0xe5: 4, 0xe6: 2, 0xe7: 1, 0xe8: 4,
    0xe9: 1, 0xea: 4, 0xeb: 1, 0xec: 1, 0xed: 1, 0xee: 1,
    0xef: 2, 0xf0: 2, 0xf1: 2, 0xf2: 2, 0xf3: 3,
    0xfa: 2, 0xfb: 3,
}

COMMAND_NAMES = {
    0xd0: "tempo", 0xd1: "tempo_fade", 0xd2: "instrument",
    0xd3: "instrument_volume", 0xd4: "initial_mix", 0xd5: "volume",
    0xd6: "volume_fade", 0xd7: "unknown_d7", 0xd8: "release_time",
    0xd9: "section_hold", 0xda: "reverb", 0xdd: "pan",
    0xde: "stereo_pan", 0xdf: "coarse_tune", 0xe0: "fine_tune",
    0xe1: "tremolo", 0xe2: "unknown_e2", 0xe3: "unknown_e3",
    0xe4: "pitch_bend_previous", 0xe5: "pitch_ascend_next",
    0xe6: "slide_section", 0xe7: "loop_marker", 0xe8: "loop",
    0xe9: "nested_loop_marker", 0xea: "nested_loop",
    0xeb: "master_loop_start", 0xec: "master_loop_end",
    0xed: "loop_skip_start", 0xee: "loop_skip_middle",
    0xef: "effect_delay", 0xf0: "unknown_f0", 0xf1: "unknown_f1",
    0xf2: "delay_note", 0xf3: "hold_previous", 0xfa: "unknown_fa",
    0xfb: "unknown_fb", 0xff: "end",
}


def parse_events(track: Track) -> tuple[Event, ...]:
    """Split every track byte into losslessly round-trippable Nagano events."""
    data = track.data
    pos = 0
    events = []
    while pos < len(data):
        start = pos
        opcode = data[pos]
        pos += 1
        if opcode < 0xd0:
            kind = "note"
            if opcode in (0x67, 0xcf):
                pos += 1                    # percussion instrument
            if opcode < 0x68:
                pos += 1                    # new duration
            if pos < len(data) and data[pos] < 0x80:
                pos += 1                    # new note length
            pos += 1                        # velocity, bit 7 may be set
        else:
            kind = "command"
            if opcode >= 0xf4 and opcode not in (0xfa, 0xfb):
                pos = start + 1             # terminator family
            else:
                size = COMMAND_SIZES.get(opcode)
                if size is None:
                    raise SequenceError(f"track {track.index}: unsupported command {opcode:#x}")
                pos = start + size
        if pos > len(data):
            raise SequenceError(f"track {track.index}: truncated {kind} {opcode:#x}")
        raw = data[start:pos]
        name = "note_or_rest" if kind == "note" else COMMAND_NAMES.get(opcode, "end")
        events.append(Event(start, pos, kind, name, opcode, tuple(raw[1:]), raw))
        if opcode == 0xff:
            if pos != len(data):
                raise SequenceError(f"track {track.index}: bytes follow end command")
            break
    if not events or events[-1].opcode != 0xff:
        raise SequenceError(f"track {track.index}: missing 0xff terminator")
    return tuple(events)


def rebuild_track(events: tuple[Event, ...]) -> bytes:
    return b"".join(event.data for event in events)
