#!/usr/bin/env python3
"""Generate the logical-byte map inside every decoded asset container."""
from __future__ import annotations

import argparse
import csv
from collections import Counter
from pathlib import Path

import asset_decode
import konami_lz
import nagano_data


def spans(blob: bytes):
    rec = asset_decode.record_stream(blob)
    if rec:
        body = rec * 12
        return [(0, body, "anim_records", f"{rec} x s16[6]")] + (
            [(body, len(blob), "pad", "zero end alignment")] if body < len(blob) else [])
    if (len(blob) == 0x14210 and blob[:8] == b"\xb8\x00\x00\x00\x00\x00\x00\x00"
            and blob[0x14008:0x14010] == blob[:8]):
        out = [(0, 8, "dl", "display-list prologue")]
        start = 8
        while start < 0x1408:
            kind = "pad" if blob[start] == 0 else "unknown"
            end = start + 1
            while end < 0x1408 and (blob[end] == 0) == (kind == "pad"):
                end += 1
            out.append((start, end, kind, "unreferenced header/zero area"))
            start = end
        return out + [(0x1408, 0x14008, "image_ci8", "320x240 CI8 background"),
                      (0x14008, 0x14010, "dl", "display-list epilogue"),
                      (0x14010, 0x14210, "tlut", "256 colors RGBA16")]
    regions, _ = asset_decode.decode_file(blob)
    counts, owner, kinds = asset_decode.coverage(blob, regions)
    out = []
    start = 0
    while start < len(owner):
        end = start + 1
        while end < len(owner) and owner[end] == owner[start]:
            end += 1
        out.append((start, end, kinds[owner[start]], ""))
        start = end
    return out


def generate(rom: bytes):
    rows = []
    summaries = []
    totals = Counter()
    for entry in nagano_data.file_table(rom):
        if entry["start"] == entry["end"]:
            continue
        if entry["compressed"]:
            blob, _ = konami_lz.decode(rom[entry["start"]:entry["end"]])
        else:
            blob = rom[entry["start"]:entry["end"]]
        file_counts = Counter()
        file_rows = spans(blob)
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
