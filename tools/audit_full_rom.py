#!/usr/bin/env python3
"""Generate a deterministic, whole-ROM decompilation attack audit."""

import argparse
import csv
import hashlib
import json
import math
import struct
import tomllib
from collections import Counter, defaultdict
from pathlib import Path

try:
    from tools.find_function_families import fingerprint, matched_sources, similar_functions
except ModuleNotFoundError:  # direct execution adds tools/, not the project root
    from find_function_families import fingerprint, matched_sources, similar_functions

ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS = ROOT / "analysis/survey/functions.toml"
INVENTORY = ROOT / "analysis/rom_inventory.tsv"
EXPECTED_SHA1 = "eaf543e195731031a84f4136b506449209e3a8f5"
ROM_TO_VRAM = 0x7FFFF400
PROGRAM_END = 0x829E0


def entropy(data: bytes) -> float:
    counts = Counter(data)
    length = len(data)
    return -sum((count / length) * math.log2(count / length)
                for count in counts.values()) if length else 0.0


def size_bucket(size: int) -> str:
    for limit in (0x10, 0x20, 0x40, 0x80, 0x100, 0x200, 0x400, 0x800):
        if size <= limit:
            return f"<=0x{limit:X}"
    return ">0x800"


def scan_function(data: bytes, vram: int, known: dict[int, str]) -> dict:
    calls = []
    jumps = 0
    branches = 0
    indirect_calls = 0
    cop1 = 0
    loads_stores = 0
    for offset, (word,) in enumerate(struct.iter_unpack(">I", data)):
        opcode = word >> 26
        if opcode == 3:
            target = ((vram + offset * 4 + 4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
            calls.append({"address": target, "name": known.get(target)})
        elif opcode == 2:
            jumps += 1
        elif opcode in (1, 4, 5, 6, 7) or opcode == 17 and ((word >> 21) & 0x1F) == 8:
            branches += 1
        elif opcode == 0 and (word & 0x3F) == 9:
            indirect_calls += 1
        if opcode == 17:
            cop1 += 1
        if 32 <= opcode <= 63:
            loads_stores += 1
    trailing_nops = 0
    for (word,) in reversed(list(struct.iter_unpack(">I", data))):
        if word:
            break
        trailing_nops += 1
    return {"direct_calls": calls, "indirect_calls": indirect_calls,
            "jumps": jumps, "branches": branches, "cop1": cop1,
            "loads_stores": loads_stores, "trailing_nops": trailing_nops}


def load_inventory() -> list[dict]:
    with INVENTORY.open() as stream:
        rows = list(csv.DictReader(stream, delimiter="\t"))
    cursor = 0
    for row in rows:
        row["start"] = int(row["start"], 0)
        row["end"] = int(row["end"], 0)
        row["size"] = int(row["size"], 0)
        if row["start"] != cursor or row["end"] - row["start"] != row["size"]:
            raise ValueError(f"inventory discontinuity at 0x{cursor:X}")
        cursor = row["end"]
    return rows


def compiler_for(source: str) -> str:
    if "matching_kmc" in source:
        return "KMC GCC 2.7.2 + assembler"
    if "matching_ido7" in source:
        return "IDO 7.1"
    return "IDO 5.3"


def audit(rom: bytes) -> dict:
    digest = hashlib.sha1(rom).hexdigest()
    if digest != EXPECTED_SHA1:
        raise ValueError(f"wrong ROM SHA-1: {digest}")
    functions = tomllib.loads(FUNCTIONS.read_text())["section"][0]["functions"]
    names = {function["vram"]: function["name"] for function in functions}
    matched = matched_sources()
    manifest_origins = {}
    manifest_ranges = []
    for path in (ROOT / "config/us").glob("matching*_units.tsv"):
        for line in path.read_text().splitlines():
            if line and not line.startswith("#"):
                fields = line.split("\t")
                manifest_origins[(int(fields[0], 0), int(fields[1], 0))] = compiler_for(path.name)
                manifest_ranges.append((int(fields[0], 0), int(fields[0], 0) + int(fields[1], 0),
                                        fields[2], compiler_for(path.name)))

    def covering_unit(start, size):
        # A unit may hold several functions of one translation unit.
        return next(((source, compiler) for lo, hi, source, compiler in manifest_ranges
                     if lo <= start and start + size <= hi), (None, None))

    records = []
    callers = Counter()
    exact_groups = defaultdict(list)
    shape_groups = defaultdict(list)
    for function in functions:
        start = function["vram"] - ROM_TO_VRAM
        size = function["size"]
        data = rom[start:start + size]
        scan = scan_function(data, function["vram"], names)
        for call in scan["direct_calls"]:
            if call["name"]:
                callers[call["name"]] += 1
        source = matched.get((start, size))
        compiler = manifest_origins.get((start, size))
        if source is None:
            source, compiler = covering_unit(start, size)
        record = {"name": function["name"], "vram": function["vram"],
                  "rom": start, "size": size, "matched": source is not None,
                  "source": source, "compiler": compiler,
                  **scan}
        records.append(record)
        exact_groups[hashlib.sha256(data).hexdigest()].append(record)
        shape_groups[(size, fingerprint(data, relaxed=True))].append(record)

    inventory = load_inventory()
    class_bytes = Counter()
    category_bytes = Counter()
    class_records = Counter()
    category_records = Counter()
    for row in inventory:
        class_bytes[row["class"]] += row["size"]
        category_bytes[row["category"]] += row["size"]
        class_records[row["class"]] += 1
        category_records[row["category"]] += 1

    banks = []
    for start in range(0, len(rom), 0x10000):
        data = rom[start:start + 0x10000]
        banks.append({"start": start, "end": start + len(data),
                      "entropy": round(entropy(data), 4),
                      "zero_bytes": data.count(0),
                      "sha256": hashlib.sha256(data).hexdigest()})

    words = struct.iter_unpack(">I", rom[:len(rom) & ~3])
    pointer_counts = Counter()
    for (word,) in words:
        if 0x80000400 <= word < 0x801954A0:
            pointer_counts["program_or_bss_vram"] += 1
        elif 0x1000 <= word < len(rom):
            pointer_counts["possible_rom_offset"] += 1
        elif 0x04000000 <= word < 0x05000000:
            pointer_counts["rsp_address"] += 1

    bucket_order = ("<=0x10", "<=0x20", "<=0x40", "<=0x80", "<=0x100",
                    "<=0x200", "<=0x400", "<=0x800", ">0x800")
    raw_size_counts = Counter(size_bucket(record["size"]) for record in records)
    size_counts = {bucket: raw_size_counts[bucket] for bucket in bucket_order}
    unmatched = [record for record in records if not record["matched"]]
    wrapper_queue = sorted((record for record in unmatched
                            if record["size"] <= 0x60 and record["direct_calls"]),
                           key=lambda item: (item["trailing_nops"], item["size"],
                                             -len(item["direct_calls"]), item["vram"]))[:50]
    leaf_queue = sorted((record for record in unmatched
                         if not record["direct_calls"] and not record["indirect_calls"]),
                        key=lambda item: (item["trailing_nops"], item["size"],
                                          item["vram"]))[:50]
    repeated = [group for group in shape_groups.values() if len(group) > 1]
    repeated_unmatched = [group for group in repeated if any(not item["matched"] for item in group)]
    similarities = similar_functions(rom, limit=100, minimum=0.55)

    strings = []
    run_start = None
    for index, value in enumerate(rom + b"\0"):
        printable = 0x20 <= value <= 0x7E
        if printable and run_start is None:
            run_start = index
        elif not printable and run_start is not None:
            if index - run_start >= 4:
                strings.append((run_start, index - run_start))
            run_start = None

    compiler_counts = Counter(record["compiler"] for record in records if record["compiler"])
    address_bands = []
    for start in range(0x1000, PROGRAM_END, 0x10000):
        members = [record for record in records if start <= record["rom"] < start + 0x10000]
        compilers = Counter(record["compiler"] for record in members if record["compiler"])
        address_bands.append({"start": start, "end": min(start + 0x10000, PROGRAM_END),
                              "functions": len(members),
                              "matched": sum(item["matched"] for item in members),
                              "matched_bytes": sum(item["size"] for item in members
                                                   if item["matched"]),
                              "compiler_matches": dict(compilers)})
    report = {
        "schema_version": 1,
        "rom": {"sha1": digest, "size": len(rom), "program_end": PROGRAM_END,
                "banks_64k": banks, "pointer_like_words": dict(pointer_counts),
                "ascii_runs_min_4": len(strings),
                "ascii_run_bytes": sum(length for _, length in strings)},
        "functions": {
            "total": len(records), "matched": sum(item["matched"] for item in records),
            "matched_bytes": sum(item["size"] for item in records if item["matched"]),
            "total_bytes": sum(item["size"] for item in records),
            "size_buckets": size_counts, "compiler_matches": dict(compiler_counts),
            "address_bands": address_bands,
            "direct_call_sites": sum(len(item["direct_calls"]) for item in records),
            "indirect_call_sites": sum(item["indirect_calls"] for item in records),
            "branch_sites": sum(item["branches"] for item in records),
            "cop1_instructions": sum(item["cop1"] for item in records),
            "exact_duplicate_groups": sum(len(group) > 1 for group in exact_groups.values()),
            "shape_duplicate_groups": len(repeated),
            "shape_groups_with_unmatched": len(repeated_unmatched),
            "trailing_nop_functions": sum(bool(item["trailing_nops"]) for item in records),
        },
        "inventory": {
            "records": len(inventory), "class_bytes": dict(class_bytes),
            "class_records": dict(class_records), "category_bytes": dict(category_bytes),
            "category_records": dict(category_records),
            "largest_unknown_ranges": [row for row in sorted(
                (row for row in inventory if row["class"] == "unknown"),
                key=lambda row: row["size"], reverse=True)[:20]],
        },
        "attack_queues": {
            "similar_to_matched": similarities,
            "small_wrappers": wrapper_queue,
            "small_leaf_functions": leaf_queue,
            "most_called": [{"name": name, "call_sites": count}
                            for name, count in callers.most_common(50)],
        },
    }
    return report


def compact_function(item: dict) -> str:
    return (f"`{item['name']}` (`0x{item['vram']:08X}`, `0x{item['size']:X}` bytes, "
            f"{len(item['direct_calls'])} direct calls, {item['trailing_nops']} trailing nops)")


def markdown(report: dict) -> str:
    functions = report["functions"]
    inventory = report["inventory"]
    queues = report["attack_queues"]
    lines = ["# Full-ROM decompilation audit", "",
             f"Retail ROM SHA-1: `{report['rom']['sha1']}`. This audit scans all "
             f"{report['rom']['size']:,} physical bytes and all {functions['total']:,} "
             "surveyed program functions.", "", "## Code census", "",
             f"- Exact matches: {functions['matched']:,} functions / "
             f"{functions['matched_bytes']:,} bytes.",
             f"- Remaining: {functions['total'] - functions['matched']:,} functions / "
             f"{functions['total_bytes'] - functions['matched_bytes']:,} surveyed bytes.",
             f"- Direct call sites: {functions['direct_call_sites']:,}; indirect call sites: "
             f"{functions['indirect_call_sites']:,}; branch sites: {functions['branch_sites']:,}.",
             f"- COP1 instructions: {functions['cop1_instructions']:,}.",
             f"- Exact duplicate groups: {functions['exact_duplicate_groups']:,}; structural "
             f"duplicate groups: {functions['shape_duplicate_groups']:,}; structural groups "
             f"with unmatched members: {functions['shape_groups_with_unmatched']:,}.",
             f"- Functions ending in one or more zero words: "
             f"{functions['trailing_nop_functions']:,}. These need boundary/padding review; a "
             "zero word is not automatically compiler-owned code.", "", "### Size distribution", ""]
    lines += [f"- {bucket}: {count:,}" for bucket, count in functions["size_buckets"].items()]
    lines += ["", "### Verified compiler units", ""]
    lines += [f"- {name}: {count:,}" for name, count in functions["compiler_matches"].items()]
    lines += ["", "### Program address bands", "",
              "| ROM range | Functions | Matched | Matched bytes | Verified compiler units |",
              "|---|---:|---:|---:|---|"]
    for band in functions["address_bands"]:
        compilers = ", ".join(f"{name}: {count}" for name, count in
                              band["compiler_matches"].items()) or "none"
        lines.append(f"| `0x{band['start']:X}..0x{band['end']:X}` | {band['functions']} | "
                     f"{band['matched']} | {band['matched_bytes']} | {compilers} |")
    banks = report["rom"]["banks_64k"]
    lowest = sorted(banks, key=lambda bank: bank["entropy"])[:5]
    highest = sorted(banks, key=lambda bank: bank["entropy"], reverse=True)[:5]
    pointer_summary = ", ".join(
        f"{name}={count:,}" for name, count in report["rom"]["pointer_like_words"].items())
    lines += ["", "## Whole-ROM structural scan", "",
              f"- Printable ASCII runs of at least four bytes: "
              f"{report['rom']['ascii_runs_min_4']:,}, spanning "
              f"{report['rom']['ascii_run_bytes']:,} bytes.",
              f"- Pointer-like aligned words: {pointer_summary}.",
              "- Lowest-entropy 64 KiB banks: " + ", ".join(
                  f"0x{bank['start']:X} ({bank['entropy']:.4f})" for bank in lowest) + ".",
              "- Highest-entropy 64 KiB banks: " + ", ".join(
                  f"0x{bank['start']:X} ({bank['entropy']:.4f})" for bank in highest) + ".",
              "", "Entropy, printable runs, and pointer-like words are discovery signals only; "
              "they do not change inventory classifications.", "", "## Physical inventory", "",
              f"The ledger has {inventory['records']:,} gap-free records.", "",
              "| Class | Bytes | Records |", "|---|---:|---:|"]
    for name, count in sorted(inventory["class_bytes"].items(), key=lambda item: -item[1]):
        lines.append(f"| {name} | {count:,} | {inventory['class_records'][name]:,} |")
    lines += ["", "| Category | Bytes | Records |", "|---|---:|---:|"]
    for name, count in sorted(inventory["category_bytes"].items(), key=lambda item: -item[1]):
        lines.append(f"| {name} | {count:,} | {inventory['category_records'][name]:,} |")
    lines += ["", "### Largest unknown physical ranges", ""]
    for row in inventory["largest_unknown_ranges"]:
        lines.append(f"- `0x{row['start']:X}..0x{row['end']:X}`: {row['size']:,} bytes ({row['name']}).")
    lines += ["", "## Immediate attack queues", "", "### Highest similarity to verified C", ""]
    for item in queues["similar_to_matched"][:20]:
        lines.append(f"- {item['score']:.2f}: `{item['name']}` at `0x{item['vram']:08X}` "
                     f"from `{item['example']}` ({item['source']}).")
    lines += ["", "### Small direct-call functions", ""]
    lines += [f"- {compact_function(item)}" for item in queues["small_wrappers"][:20]]
    lines += ["", "### Small leaf functions", ""]
    lines += [f"- {compact_function(item)}" for item in queues["small_leaf_functions"][:20]]
    lines += ["", "### Most referenced local functions", ""]
    lines += [f"- `{item['name']}`: {item['call_sites']:,} direct call sites."
              for item in queues["most_called"][:20]]
    lines += ["", "## Conclusions", "",
              "1. Work the similarity queue first, but reject candidates whose only residual is "
              "unproven boundary padding rather than forcing inline assembly.",
              "2. Split the small-wrapper queue by compiler evidence and callee prototype; these "
              "are the next broad source-transfer opportunity.",
              "3. Treat the small-leaf queue as arithmetic, accessors, and SDK-signature work; "
              "MIPS III 64-bit helpers need per-unit `-mips3 -32` flags.",
              "4. Attack unknown physical ranges through loader references and round-trip parsers. "
              "Do not convert pointer-like words or entropy boundaries directly into asset claims.",
              "5. Re-run this audit after each matching or inventory campaign so queues and totals "
              "remain derived from authoritative manifests.", ""]
    return "\n".join(lines)


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--rom", type=Path, default=ROOT / "baseroms/us/baserom.z64")
    parser.add_argument("--json", type=Path, default=ROOT / "analysis/full_rom_audit.json")
    parser.add_argument("--markdown", type=Path, default=ROOT / "analysis/full_rom_audit.md")
    args = parser.parse_args()
    report = audit(args.rom.read_bytes())
    args.json.write_text(json.dumps(report, indent=2) + "\n")
    args.markdown.write_text(markdown(report))
    print(f"audited {report['rom']['size']} bytes and {report['functions']['total']} functions")


if __name__ == "__main__":
    main()
