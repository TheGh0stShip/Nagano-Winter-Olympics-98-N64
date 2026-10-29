#!/usr/bin/env python3
"""List unmatched functions in a stable, size-ranked work queue."""

from __future__ import annotations

import argparse
import re
from pathlib import Path
from typing import NamedTuple


ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS = ROOT / "analysis/survey/functions.toml"
MANIFESTS = (
    ROOT / "config/us/matching_kmc_as_units.tsv",
    ROOT / "config/us/matching_asm_units.tsv",
    ROOT / "config/us/matching_ido_asm_units.tsv",
    ROOT / "config/us/matching_ido_units.tsv",
    ROOT / "config/us/matching_ido7_units.tsv",
)
VRAM_ROM_DELTA = 0x7FFFF400
FUNCTION_RE = re.compile(
    r'name = "(?P<name>[^"]+)", vram = (?P<vram>0x[0-9a-f]+), '
    r'size = (?P<size>0x[0-9a-f]+) }, # (?P<kind>\S+)'
)


class Function(NamedTuple):
    name: str
    vram: int
    size: int
    kind: str


def load_functions() -> list[Function]:
    functions = []
    for line in FUNCTIONS.read_text().splitlines():
        match = FUNCTION_RE.search(line)
        if match:
            functions.append(Function(
                match["name"], int(match["vram"], 16),
                int(match["size"], 16), match["kind"],
            ))
    return functions


def load_matched_ranges() -> list[tuple[int, int]]:
    matched = []
    for path in MANIFESTS:
        for line in path.read_text().splitlines():
            if not line or line.startswith("#"):
                continue
            fields = line.split("\t")
            start = int(fields[0], 16) + VRAM_ROM_DELTA
            matched.append((start, start + int(fields[1], 16)))
    return matched


def main() -> None:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--limit", type=int, default=40)
    parser.add_argument("--kind", help="restrict to one survey classification")
    args = parser.parse_args()
    ranges = load_matched_ranges()
    queue = [function for function in load_functions()
             if not any(start <= function.vram and
                        function.vram + function.size <= end
                        for start, end in ranges)]
    if args.kind:
        queue = [function for function in queue if function.kind == args.kind]
    queue.sort(key=lambda function: (function.size, function.vram))
    print("VRAM       SIZE  KIND  FUNCTION")
    for function in queue[:args.limit]:
        print(f"0x{function.vram:08X}  0x{function.size:04X}  "
              f"{function.kind:<5} {function.name}")
    print(f"shown={min(args.limit, len(queue))} unmatched={len(queue)}")


if __name__ == "__main__":
    main()
