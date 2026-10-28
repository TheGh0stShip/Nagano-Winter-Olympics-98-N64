#!/usr/bin/env python3
"""Find structurally identical MIPS functions across the retail program."""

import argparse
import csv
import difflib
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
    ROOT / "config/us/matching_asm_units.tsv",
    ROOT / "config/us/matching_ido_units.tsv",
    ROOT / "config/us/matching_ido7_units.tsv",
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


def instruction_token(word: int, pc: int, names: dict[int, str]) -> str:
    """Retain operation shape plus useful small constants and direct callees."""
    opcode = word >> 26
    shape = shape_instruction(word)
    if opcode == 3:  # jal: names are much more useful than absolute targets
        target = ((pc + 4) & 0xF0000000) | ((word & 0x03FFFFFF) << 2)
        return f"{shape:x}:call:{names.get(target, 'external')}"
    if opcode in (2, 3):
        return f"{shape:x}"
    immediate = word & 0xFFFF
    signed = immediate - 0x10000 if immediate & 0x8000 else immediate
    if -0x1000 < signed < 0x1000 and opcode != 0:
        return f"{shape:x}:{signed}"
    return f"{shape:x}"


def token_stream(data: bytes, vram: int, names: dict[int, str]) -> list[str]:
    return [instruction_token(word, vram + index * 4, names)
            for index, (word,) in enumerate(struct.iter_unpack(">I", data))]


def ngrams(tokens: list[str], width: int = 3) -> set[tuple[str, ...]]:
    if len(tokens) < width:
        return {tuple(tokens)} if tokens else set()
    return {tuple(tokens[index:index + width])
            for index in range(len(tokens) - width + 1)}


def matched_sources() -> dict[tuple[int, int], str]:
    result = {}
    for manifest in MANIFESTS:
        with manifest.open() as stream:
            for row in csv.reader(stream, delimiter="\t"):
                if not row or row[0].startswith("#"):
                    continue
                result[(int(row[0], 0), int(row[1], 0))] = row[2]
    return result


def families(rom: bytes, include_unmatched: bool = False) -> list[dict]:
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
        if sources and unknown or include_unmatched and not sources and len(unknown) > 1:
            result.append({"size": size, "fingerprint": digest,
                           "matched": sources, "candidates": unknown})
    return sorted(result, key=lambda item: (-item["size"] * len(item["candidates"]),
                                             -item["size"], item["fingerprint"]))


def similar_functions(rom: bytes, limit: int = 50, minimum: float = 0.45) -> list[dict]:
    """Rank unmatched functions against matched examples with similar instruction streams."""
    matched = matched_sources()
    functions = tomllib.loads(FUNCTIONS.read_text())["section"][0]["functions"]
    names = {function["vram"]: function["name"] for function in functions}
    records = []
    for function in functions:
        rom_start = function["vram"] - 0x80000400 + 0x1000
        size = function["size"]
        tokens = token_stream(rom[rom_start:rom_start + size], function["vram"], names)
        records.append((function, rom_start, tokens, ngrams(tokens),
                        matched.get((rom_start, size))))
    known = [record for record in records if record[4] and len(record[2]) >= 6]
    results = []
    for function, rom_start, tokens, grams, source in records:
        if source or len(tokens) < 6:
            continue
        prefiltered = []
        for candidate, _, other_tokens, other_grams, other_source in known:
            length_ratio = len(other_tokens) / len(tokens)
            if not 0.4 < length_ratio < 2.5:
                continue
            union = grams | other_grams
            jaccard = len(grams & other_grams) / len(union) if union else 0.0
            if jaccard > 0.1:
                prefiltered.append((jaccard, candidate, other_tokens, other_source))
        for jaccard, candidate, other_tokens, other_source in sorted(
                prefiltered, key=lambda item: item[0], reverse=True)[:40]:
            ratio = difflib.SequenceMatcher(None, tokens, other_tokens,
                                             autojunk=False).ratio()
            if ratio >= minimum:
                results.append({"name": function["name"], "vram": function["vram"],
                                "size": function["size"], "score": ratio,
                                "jaccard": jaccard, "example": candidate["name"],
                                "source": other_source})
    return sorted(results, key=lambda item: (-item["score"], -item["size"],
                                              item["vram"]))[:limit]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, default=ROOT / "baseroms/us/baserom.z64")
    parser.add_argument("--json", action="store_true")
    parser.add_argument("--include-unmatched", action="store_true",
                        help="also show repeated families with no matching member")
    parser.add_argument("--similar", action="store_true",
                        help="rank unmatched functions against matched examples")
    parser.add_argument("--minimum", type=float, default=0.45,
                        help="minimum sequence similarity for --similar")
    parser.add_argument("--limit", type=int, default=50)
    args = parser.parse_args()
    rom = args.rom.read_bytes()
    if args.similar:
        found = similar_functions(rom, args.limit, args.minimum)
        if args.json:
            print(json.dumps(found, indent=2))
            return
        for item in found:
            print(f"{item['score']:.2f}  0x{item['vram']:08X} {item['name']} "
                  f"<- {item['example']}  {item['source']}")
        return
    found = families(rom, args.include_unmatched)[:args.limit]
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
