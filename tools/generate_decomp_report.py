#!/usr/bin/env python3
"""Generate the objdiff v2 progress report from reviewed manifests."""
import json
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS = ROOT / "analysis/survey/functions.toml"
MANIFEST = ROOT / "config/us/matching_kmc_as_units.tsv"
OUTPUT = ROOT / "build/report.json"
TOTAL_CODE = 392_212
TOTAL_DATA = 129_864


def measures(code, matched, functions, matched_functions, data=0, matched_data=0):
    cp = 100.0 * matched / code if code else 0.0
    dp = 100.0 * matched_data / data if data else 0.0
    fp = 100.0 * matched_functions / functions if functions else 0.0
    return {"fuzzy_match_percent": cp, "total_code": str(code),
            "matched_code": str(matched), "matched_code_percent": cp,
            "total_data": str(data), "matched_data": str(matched_data),
            "matched_data_percent": dp, "total_functions": functions,
            "matched_functions": matched_functions,
            "matched_functions_percent": fp, "complete_code": str(matched),
            "complete_code_percent": cp, "complete_data": str(matched_data),
            "complete_data_percent": dp, "total_units": functions,
            "complete_units": matched_functions}


def main():
    funcs = tomllib.loads(FUNCTIONS.read_text())["section"][0]["functions"]
    rows = [line.split("\t") for line in MANIFEST.read_text().splitlines()
            if line and not line.startswith("#")]
    matched = {(int(r[0], 0), int(r[1], 0)): r[2] for r in rows}
    units, matched_bytes, matched_count = [], 0, 0
    for fn in funcs:
        start = fn["vram"] - 0x80000400 + 0x1000
        size = fn["size"]
        source = matched.get((start, size))
        complete = source is not None
        matched_bytes += size if complete else 0
        matched_count += complete
        units.append({"name": fn["name"], "measures": measures(size, size if complete else 0, 1, int(complete)),
                      "functions": [{"name": fn["name"], "size": str(size),
                                     "fuzzy_match_percent": 100.0 if complete else 0.0,
                                     "address": str(fn["vram"]),
                                     "metadata": {"virtual_address": str(fn["vram"])}}],
                      "metadata": {"complete": complete,
                                   "source_path": source or f"asm/us/{fn['name']}.s",
                                   "progress_categories": ["code"],
                                   "auto_generated": not complete}})
    data = tomllib.loads((ROOT / "config/us/data_progress.toml").read_text())["initialized_data"]
    if data["matched"] + data["unmatched"] != TOTAL_DATA:
        raise ValueError("initialized data progress does not cover the program data")
    report = {"measures": measures(TOTAL_CODE, matched_bytes, len(funcs), matched_count,
                                    TOTAL_DATA, data["matched"]),
              "units": units, "version": 2,
              "categories": [{"id": "code", "name": "Program code",
                              "measures": measures(TOTAL_CODE, matched_bytes, len(funcs), matched_count)},
                             {"id": "program_data", "name": "Initialized program data",
                              "measures": measures(0, 0, 0, 0, TOTAL_DATA, data["matched"])}]}
    OUTPUT.parent.mkdir(exist_ok=True)
    OUTPUT.write_text(json.dumps(report, indent=2) + "\n")
    print(f"wrote {OUTPUT}: {matched_bytes} / {TOTAL_CODE} code bytes")


if __name__ == "__main__":
    main()
