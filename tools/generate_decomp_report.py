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
    ROOT / "config/us/matching_asm_units.tsv",
    ROOT / "config/us/matching_ido_asm_units.tsv",
    ROOT / "config/us/matching_ido_units.tsv",
    ROOT / "config/us/matching_ido7_units.tsv",
)
OUTPUT = ROOT / "build/report.json"
INVENTORY = ROOT / "analysis/data_map/rom_map.tsv"
ASSET_PROGRESS = ROOT / "config/us/asset_progress.toml"
TOTAL_DATA = 129_824
ROM_SIZE = 12_582_912
ASSET_START = 0x829E0
ASSET_END = 0xC00000


def measures(code, matched, functions, matched_functions, data=0,
             matched_data=0, units=None, complete_units=None):
    cp = 100.0 * matched / code if code else 0.0
    dp = 100.0 * matched_data / data if data else 0.0
    fp = 100.0 * matched_functions / functions if functions else 0.0
    if units is None:
        units = functions
    if complete_units is None:
        complete_units = matched_functions
    return {"fuzzy_match_percent": cp, "total_code": str(code),
            "matched_code": str(matched), "matched_code_percent": cp,
            "total_data": str(data), "matched_data": str(matched_data),
            "matched_data_percent": dp, "total_functions": functions,
            "matched_functions": matched_functions,
            "matched_functions_percent": fp, "complete_code": str(matched),
            "complete_code_percent": cp, "complete_data": str(matched_data),
            "complete_data_percent": dp, "total_units": units,
            "complete_units": complete_units}


def data_category_measures(total, matched):
    """Expose non-code progress in ByteMatch's code-percent category view.

    ByteMatch currently renders category percentages from the code fields even
    when a category contains only data.  Mirror the byte counts into both sets
    of fields, as the completed BattleTanx report does, while leaving the
    report's aggregate code and data measures independent.
    """
    return measures(total, matched, 0, 0, total, matched)


def inventory_progress():
    """Validate the authoritative physical ledger and derive asset totals."""
    with INVENTORY.open() as stream:
        rows = list(csv.DictReader(stream, delimiter="\t"))
    cursor = 0
    identified = 0
    audio = 0
    music = 0
    for row in rows:
        start, end = int(row["start"], 0), int(row["end"], 0)
        if start != cursor or end <= start or int(row["size"], 0) != end - start:
            raise ValueError(f"{INVENTORY}: gap, overlap, or bad size at 0x{cursor:X}")
        cursor = end
        if end > ASSET_START:
            size = end - max(start, ASSET_START)
            if row["category"] == "unknown" or row["stage"] == "unknown":
                continue
            identified += size
            if row["category"] == "audio_bank":
                audio += size
            elif row["subtype"] == "konami_lz.music_sequence":
                music += size
    if cursor != ROM_SIZE or ASSET_END != ROM_SIZE:
        raise ValueError(f"{INVENTORY}: inventory does not cover the retail ROM")
    progress = tomllib.loads(ASSET_PROGRESS.read_text())
    region = progress["region"]
    if (region["rom_start"], region["rom_end"]) != (ASSET_START, ASSET_END):
        raise ValueError(f"{ASSET_PROGRESS}: asset region disagrees with the ROM map")
    extracted = progress["extraction"]["extracted_bytes"]
    if not 0 <= extracted <= identified:
        raise ValueError(f"{ASSET_PROGRESS}: invalid extracted byte count")
    nested = progress["nested"]
    if nested["classified_bytes"] + nested["unknown_bytes"] != nested["total_bytes"]:
        raise ValueError(f"{ASSET_PROGRESS}: nested payload totals disagree")
    return identified, audio, music, extracted, nested


def main():
    funcs = tomllib.loads(FUNCTIONS.read_text())["section"][0]["functions"]
    # Track executable function bodies as code. Linker/TU alignment between
    # them remains covered by the physical ROM inventory, but is not C code.
    total_code = sum(fn["size"] for fn in funcs)
    rows = [line.split("\t") for manifest in MANIFESTS
            for line in manifest.read_text().splitlines()
            if line and not line.startswith("#")]
    # A unit may hold several functions of one translation unit; a function is
    # complete when one verified manifest range covers all of its bytes.
    matched = [(int(r[0], 0), int(r[0], 0) + int(r[1], 0), r[2]) for r in rows]
    source_units, matched_bytes, matched_count = {}, 0, 0
    for fn in funcs:
        start = fn["vram"] - 0x80000400 + 0x1000
        size = fn["size"]
        source = next((src for lo, hi, src in matched
                       if lo <= start and start + size <= hi), None)
        complete = source is not None
        matched_bytes += size if complete else 0
        matched_count += complete
        source_path = source or f"asm/us/{fn['name']}.s"
        unit = source_units.setdefault(source_path, {
            "name": source_path,
            "code": 0,
            "matched": 0,
            "functions": [],
            "matched_functions": 0,
            "complete": True,
        })
        unit["code"] += size
        unit["matched"] += size if complete else 0
        unit["matched_functions"] += int(complete)
        unit["complete"] = unit["complete"] and complete
        unit["functions"].append({
            "name": fn["name"],
            "size": str(size),
            "fuzzy_match_percent": 100.0 if complete else 0.0,
            "address": str(fn["vram"]),
            "metadata": {"virtual_address": str(fn["vram"])},
        })
    units = []
    for source_path, unit in source_units.items():
        function_count = len(unit["functions"])
        units.append({
            "name": unit["name"],
            "measures": measures(
                unit["code"], unit["matched"], function_count,
                unit["matched_functions"], units=1,
                complete_units=int(unit["complete"]),
            ),
            "functions": unit["functions"],
            "metadata": {
                "complete": unit["complete"],
                "source_path": source_path,
                "progress_categories": ["code"],
                "auto_generated": not unit["complete"],
            },
        })
    data = tomllib.loads((ROOT / "config/us/data_progress.toml").read_text())["initialized_data"]
    if data["matched"] + data["unmatched"] != TOTAL_DATA:
        raise ValueError("initialized data progress does not cover the program data")
    identified, audio, music, extracted, nested = inventory_progress()
    asset_total = ASSET_END - ASSET_START
    complete_unit_count = sum(unit["metadata"]["complete"] for unit in units)
    report = {"measures": measures(total_code, matched_bytes, len(funcs), matched_count,
                                    TOTAL_DATA, data["matched"], len(units),
                                    complete_unit_count),
              "units": units, "version": 2,
              "categories": [{"id": "code", "name": "Program code",
                              "measures": measures(total_code, matched_bytes, len(funcs), matched_count,
                                                   units=len(units),
                                                   complete_units=complete_unit_count)},
                             {"id": "program_data", "name": "Initialized program data",
                              "measures": data_category_measures(TOTAL_DATA, data["matched"])},
                             {"id": "assets", "name": "Identified asset-region bytes",
                              "measures": data_category_measures(asset_total, identified)},
                             {"id": "assets_audio", "name": "Identified audio banks and samples",
                              "measures": data_category_measures(audio, audio)},
                             {"id": "assets_music", "name": "Identified compressed music sequences",
                              "measures": data_category_measures(music, music)},
                             {"id": "assets_extracted", "name": "Extracted asset bytes",
                              "measures": data_category_measures(asset_total, extracted)},
                             {"id": "assets_reconstructed", "name": "Byte-exact reconstructed asset-region bytes",
                              "measures": data_category_measures(asset_total, identified)},
                             {"id": "assets_nested", "name": "Classified decoded-container bytes",
                              "measures": data_category_measures(nested["total_bytes"],
                                                                nested["classified_bytes"])},
                             {"id": "rom_inventory", "name": "Physical ROM inventory coverage",
                              "measures": data_category_measures(ROM_SIZE, ROM_SIZE)}]}
    OUTPUT.parent.mkdir(exist_ok=True)
    OUTPUT.write_text(json.dumps(report, indent=2) + "\n")
    print(f"wrote {OUTPUT}: {matched_bytes} / {total_code} code bytes; "
          f"{identified} / {asset_total} identified asset-region bytes")


if __name__ == "__main__":
    main()
