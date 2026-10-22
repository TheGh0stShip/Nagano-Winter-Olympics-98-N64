#!/usr/bin/env python3
"""Find structurally identical MIPS functions across the retail program."""

import argparse
import csv
import hashlib
import json
import struct
import tomllib
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS = ROOT / "analysis/survey/functions.toml"
MANIFESTS = (
    ROOT / "config/us/matching_kmc_as_units.tsv",
    ROOT / "config/us/matching_ido_units.tsv",
)


def normalize_instruction(word: int) -> int:
    """Remove address/immediate fields while retaining opcode/register shape."""
    opcode = word >> 26
    if opcode in (2, 3):  # j, jal
        return word & 0xFC000000
    if opcode in (1, 4, 5, 6, 7) or 8 <= opcode <= 15:
        return word & 0xFFFF0000
    if 20 <= opcode <= 25 or 32 <= opcode <= 63:
        return word & 0xFFFF0000
    if opcode == 17 and ((word >> 21) & 0x1F) == 8:  # bc1*
        return word & 0xFFFF0000
    return word


def shape_instruction(word: int) -> int:
    """Return a mnemonic-level key for candidate-family discovery."""
    opcode = word >> 26
    if opcode == 0:
        return (opcode << 16) | (word & 0x3F)
    if opcode == 1:
        return (opcode << 16) | ((word >> 16) & 0x1F)
    if opcode in (16, 17, 18):
        return (opcode << 16) | (((word >> 21) & 0x1F) << 6) | (word & 0x3F)
    return opcode << 16


def fingerprint(data: bytes, relaxed: bool = False) -> str:
    if len(data) % 4:
        raise ValueError("function size is not word aligned")
    normalizer = shape_instruction if relaxed else normalize_instruction
    normalized = (normalizer(word)
                  for (word,) in struct.iter_unpack(">I", data))
    packed = b"".join(struct.pack(">I", word) for word in normalized)
    return hashlib.sha256(packed).hexdigest()


def matched_sources() -> dict[tuple[int, int], str]:
    result = {}
    for manifest in MANIFESTS:
        with manifest.open() as stream:
            for row in csv.reader(stream, delimiter="\t"):
                if not row or row[0].startswith("#"):
                    continue
                result[(int(row[0], 0), int(row[1], 0))] = row[2]
    return result


def families(rom: bytes) -> list[dict]:
    matched = matched_sources()
    functions = tomllib.loads(FUNCTIONS.read_text())["section"][0]["functions"]
    grouped = defaultdict(list)
    for function in functions:
        rom_start = function["vram"] - 0x80000400 + 0x1000
        size = function["size"]
        key = (size, fingerprint(rom[rom_start:rom_start + size], relaxed=True))
        grouped[key].append({
            "name": function["name"],
            "vram": function["vram"],
            "rom": rom_start,
            "size": size,
            "source": matched.get((rom_start, size)),
        })
    result = []
    for (size, digest), members in grouped.items():
        sources = [member for member in members if member["source"]]
        unknown = [member for member in members if not member["source"]]
        if sources and unknown:
            result.append({"size": size, "fingerprint": digest,
                           "matched": sources, "candidates": unknown})
    return sorted(result, key=lambda item: (-item["size"] * len(item["candidates"]),
                                             -item["size"], item["fingerprint"]))


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, default=ROOT / "baseroms/us/baserom.z64")
    parser.add_argument("--json", action="store_true")
    parser.add_argument("--limit", type=int, default=50)
    args = parser.parse_args()
    found = families(args.rom.read_bytes())[:args.limit]
    if args.json:
        print(json.dumps(found, indent=2))
        return
    for family in found:
        print(f"0x{family['size']:X} bytes  {family['fingerprint'][:12]}")
        for member in family["matched"]:
            print(f"  match     0x{member['vram']:08X}  {member['source']}")
        for member in family["candidates"]:
            print(f"  candidate 0x{member['vram']:08X}  {member['name']}")


if __name__ == "__main__":
    main()
