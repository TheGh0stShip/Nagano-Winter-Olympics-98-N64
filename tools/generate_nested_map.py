#!/usr/bin/env python3
"""Generate the logical-byte map inside every decoded asset container."""
from __future__ import annotations

import argparse
import csv
from collections import Counter
from pathlib import Path

import asset_decode
import image_descriptors
import konami_lz
import nagano_data


def descriptor_regions(blob: bytes, descs):
    """Convert verified program-side image descriptors into typed regions.

    These augment the in-file F3DEX walk: the renderer often keeps its image
    pointer in initialized program data, so no segment pointer exists inside
    the asset itself.
    """
    regions = []
    for d in descs:
        stride = d["width"] * d["bpp"]
        shown_end = d["image"] + stride * d["height"]
        source = f"descriptor ROM {d['record_rom']:#x}"
        kind = f"image_{d['format']}"
        regions.append(asset_decode.Region(
            d["image"], shown_end, kind,
            f"{d['width']}x{d['height']} ({source})"))

        # Some storage blocks contain complete continuation scanlines beyond
        # the visible descriptor height.  Only classify whole rows; any tail
        # remains available to the ordinary decoder/unknown accounting.
        rows = (d["image_block_end"] - d["image"]) // stride
        if rows > d["height"]:
            extra_start = shown_end
            extra_end = d["image"] + rows * stride
            continuity = image_descriptors.row_continuity(
                blob, d["image"], d["width"], d["bpp"], d["height"],
                rows - d["height"])
            regions.append(asset_decode.Region(
                extra_start, extra_end, kind,
                f"{rows - d['height']} continuation rows "
                f"(adjacent-row difference {continuity:.3f})"))

        if d["tlut"] is not None:
            # CI8 can address 256 entries.  Keep the entire independently
            # delimited palette block (normally exactly 0x200 bytes).
            regions.append(asset_decode.Region(
                d["tlut"], d["tlut_block_end"], "tlut",
                f"RGBA16 palette ({source})"))
    return regions


def spans(blob: bytes, descs=None):
    rec = asset_decode.record_stream(blob)
    if rec:
        body = rec * 12
        return [(0, body, "anim_records", f"{rec} x s16[6]")] + (
            [(body, len(blob), "pad", "zero end alignment")] if body < len(blob) else [])
    rec20 = asset_decode.headed_record_stream(blob)
    if rec20:
        return [(0, 8, "record_header", "4 x big-endian s16"),
                (8, len(blob), "records_s16x10", f"{rec20} x s16[10]")]
    regions, _ = asset_decode.decode_file(blob)
    if descs:
        regions.extend(descriptor_regions(blob, descs))
    counts, owner, kinds = asset_decode.coverage(blob, regions)
    out = []
    start = 0
    while start < len(owner):
        end = start + 1
        while end < len(owner) and owner[end] == owner[start]:
            end += 1
        out.append((start, end, kinds[owner[start]],
                    "generic structural decoder"))
        start = end
    return out


def generate(rom: bytes, rom_map: Path = Path("analysis/data_map/rom_map.tsv")):
    rows = []
    summaries = []
    totals = Counter()
    entries = [entry for entry in nagano_data.file_table(rom)
               if entry["start"] != entry["end"]]
    blobs = {}
    for entry in entries:
        if entry["compressed"]:
            blobs[entry["id"]], _ = konami_lz.decode(
                rom[entry["start"]:entry["end"]])
        else:
            blobs[entry["id"]] = rom[entry["start"]:entry["end"]]
    descriptors = image_descriptors.find(rom, blobs, rom_map)
    for entry in entries:
        blob = blobs[entry["id"]]
        file_counts = Counter()
        file_rows = spans(blob, descriptors.get(entry["id"]))
        for start, end, kind, info in file_rows:
            size = end - start
            file_counts[kind] += size
            totals[kind] += size
            rows.append((entry["id"], start, end, size, kind, info))
        summaries.append((entry["id"], entry["start"], entry["end"], len(blob),
                          file_counts["unknown"], file_counts["pad"],
                          len(file_rows)))
    return rows, summaries, totals


def write_tsv(path: Path, header, rows):
    path.parent.mkdir(parents=True, exist_ok=True)
    with path.open("w", newline="") as stream:
        writer = csv.writer(stream, delimiter="\t", lineterminator="\n")
        writer.writerow(header)
        writer.writerows(rows)


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument("rom", type=Path)
    parser.add_argument("--out", type=Path, default=Path("analysis/data_map"))
    args = parser.parse_args()
    rom = nagano_data.load_rom(args.rom)
    rows, summaries, totals = generate(rom)
    write_tsv(args.out / "nested_map.tsv",
              ("file_id", "decoded_start", "decoded_end", "size", "kind", "info"), rows)
    write_tsv(args.out / "nested_summary.tsv",
              ("file_id", "rom_start", "rom_end", "decoded_size", "unknown_bytes",
               "unreferenced_zero_bytes", "region_count"), summaries)
    print(" ".join(f"{kind}={size}" for kind, size in sorted(totals.items())))


if __name__ == "__main__":
    main()
