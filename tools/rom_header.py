#!/usr/bin/env python3
"""N64 ROM header fields and the CIC-NUS-6102 boot checksum (CRC1/CRC2 at 0x10)."""
from __future__ import annotations

import hashlib
import struct

M = 0xFFFFFFFF
CIC_6102_SEED = 0xF8CA4DDC
IPL3_6102_SHA1 = None  # filled by measurement in tests (standard 6102 boot code)


def rol(v: int, n: int) -> int:
    n &= 31
    return ((v << n) | (v >> (32 - n))) & M


def checksum_6102(rom: bytes) -> tuple[int, int]:
    if len(rom) < 0x101000:
        raise ValueError("ROM too small for boot checksum")
    t1 = t2 = t3 = t4 = t5 = t6 = CIC_6102_SEED
    for i in range(0x1000, 0x101000, 4):
        d = struct.unpack_from(">I", rom, i)[0]
        if (t6 + d) & M < t6:
            t4 = (t4 + 1) & M
        t6 = (t6 + d) & M
        t3 ^= d
        r = rol(d, d & 0x1F)
        t5 = (t5 + r) & M
        t2 = (t2 ^ r) if t2 > d else (t2 ^ t6 ^ d)
        t1 = (t1 + (t5 ^ d)) & M
    return (t6 ^ t4 ^ t3) & M, (t5 ^ t2 ^ t1) & M


def parse_header(rom: bytes) -> dict:
    h = rom[:0x40]
    return {
        "pi_config": struct.unpack_from(">I", h, 0)[0],
        "clock_rate": struct.unpack_from(">I", h, 4)[0],
        "entry_point": struct.unpack_from(">I", h, 8)[0],
        "release": struct.unpack_from(">I", h, 12)[0],
        "crc1": struct.unpack_from(">I", h, 16)[0],
        "crc2": struct.unpack_from(">I", h, 20)[0],
        "reserved_18": h[0x18:0x20].hex(),
        "title": h[0x20:0x34].decode("ascii"),
        "reserved_34": h[0x34:0x3B].hex(),
        "media": chr(h[0x3B]),
        "game_id": h[0x3C:0x3E].decode("ascii"),
        "region": chr(h[0x3E]),
        "version": h[0x3F],
    }


def build_header(fields: dict, rom_for_crc: bytes) -> bytes:
    """Rebuild the 64-byte header; CRC words are recomputed, not copied."""
    crc1, crc2 = checksum_6102(rom_for_crc)
    h = struct.pack(">IIII", fields["pi_config"], fields["clock_rate"], fields["entry_point"], fields["release"])
    h += struct.pack(">II", crc1, crc2) + bytes.fromhex(fields["reserved_18"])
    h += fields["title"].encode("ascii") + bytes.fromhex(fields["reserved_34"])
    h += fields["media"].encode() + fields["game_id"].encode() + fields["region"].encode() + bytes([fields["version"]])
    if len(h) != 0x40:
        raise ValueError("header length")
    return h


def sha1(b: bytes) -> str:
    return hashlib.sha1(b).hexdigest()
