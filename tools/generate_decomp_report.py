#!/usr/bin/env python3
"""Generate the objdiff v2 progress report from reviewed manifests."""
import csv
import json
import tomllib
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
FUNCTIONS = ROOT / "analysis/survey/functions.toml"
MANIFESTS = (
    ROOT / "config/us/matching_kmc_as_units.tsv",
    ROOT / "config/us/matching_ido_units.tsv",
    ROOT / "config/us/matching_ido7_units.tsv",
)
OUTPUT = ROOT / "build/report.json"
INVENTORY = ROOT / "analysis/rom_inventory.tsv"
ASSET_PROGRESS = ROOT / "config/us/asset_progress.toml"
TOTAL_CODE = 392_212
TOTAL_DATA = 129_864
ROM_SIZE = 12_582_912
ASSET_START = 0x829E0
ASSET_END = 0xC00000


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


def asset_measures(total, matched):
    """Expose non-code progress in ByteMatch's code-percent category view."""
    return measures(total, matched, 0, 0, total, matched)


def inventory_progress():
    """Validate the physical ledger and derive conservative asset totals."""
    with INVENTORY.open() as stream:
        rows = list(csv.DictReader(stream, delimiter="\t"))
    cursor = 0
    identified = 0
    audio = 0
    music = 0
    for row in rows:
        start, end = int(row["start"], 0), int(row["end"], 0)
        if start != cursor or end <= start or int(row["size"]) != end - start:
            raise ValueError(f"{INVENTORY}: gap, overlap, or bad size at 0x{cursor:X}")
        cursor = end
        if start >= ASSET_START and row["class"] in {"container", "payload"}:
            identified += end - start
            if row["category"] == "audio":
                audio += end - start
            elif row["category"] == "music":
                music += end - start
    if cursor != ROM_SIZE or ASSET_END != ROM_SIZE:
        raise ValueError(f"{INVENTORY}: inventory does not cover the retail ROM")
    progress = tomllib.loads(ASSET_PROGRESS.read_text())
    region = progress["region"]
    if (region["rom_start"], region["rom_end"]) != (ASSET_START, ASSET_END):
        raise ValueError(f"{ASSET_PROGRESS}: asset region disagrees with the ROM map")
    extracted = progress["extraction"]["extracted_bytes"]
    if not 0 <= extracted <= identified:
        raise ValueError(f"{ASSET_PROGRESS}: invalid extracted byte count")
    return identified, audio, music, extracted


def main():
    funcs = tomllib.loads(FUNCTIONS.read_text())["section"][0]["functions"]
    rows = [line.split("\t") for manifest in MANIFESTS
            for line in manifest.read_text().splitlines()
            if line and not line.startswith("#")]
    # A unit may hold several functions of one translation unit; a function is
    # complete when one verified manifest range covers all of its bytes.
    matched = [(int(r[0], 0), int(r[0], 0) + int(r[1], 0), r[2]) for r in rows]
    units, matched_bytes, matched_count = [], 0, 0
    for fn in funcs:
        start = fn["vram"] - 0x80000400 + 0x1000
        size = fn["size"]
        source = next((src for lo, hi, src in matched
                       if lo <= start and start + size <= hi), None)
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
    identified, audio, music, extracted = inventory_progress()
    asset_total = ASSET_END - ASSET_START
    report = {"measures": measures(TOTAL_CODE, matched_bytes, len(funcs), matched_count,
                                    TOTAL_DATA, data["matched"]),
              "units": units, "version": 2,
              "categories": [{"id": "code", "name": "Program code",
                              "measures": measures(TOTAL_CODE, matched_bytes, len(funcs), matched_count)},
                             {"id": "program_data", "name": "Initialized program data",
                              "measures": measures(0, 0, 0, 0, TOTAL_DATA, data["matched"])},
                             {"id": "assets", "name": "Identified asset-region bytes",
                              "measures": asset_measures(asset_total, identified)},
                             {"id": "assets_audio", "name": "Identified audio banks and samples",
                              "measures": asset_measures(audio, audio)},
                             {"id": "assets_music", "name": "Identified compressed music sequences",
                              "measures": asset_measures(music, music)},
                             {"id": "assets_extracted", "name": "Extracted asset bytes",
                              "measures": asset_measures(identified, extracted)},
                             {"id": "rom_inventory", "name": "Physical ROM inventory coverage",
                              "measures": asset_measures(ROM_SIZE, ROM_SIZE)}]}
    OUTPUT.parent.mkdir(exist_ok=True)
    OUTPUT.write_text(json.dumps(report, indent=2) + "\n")
    print(f"wrote {OUTPUT}: {matched_bytes} / {TOTAL_CODE} code bytes; "
          f"{identified} / {asset_total} identified asset-region bytes")


if __name__ == "__main__":
    main()
