# USA ROM inventory

This is a gap-free physical map of the 12,582,912-byte retail ROM. Counts are
format-evidence counts, not guesses about nested media.

| Class | Records | Bytes |
|---|---:|---:|
| ROM metadata | 2 | 4,096 |
| Program code (CPU and RSP) | 5 | 401,048 |
| Program initialized data | 3 | 129,864 |
| Loader-referenced, undecoded | 1,036 | 925,080 |
| Audio containers | 1,238 | 59,306 |
| Audio sample payloads | 93 | 690,910 |
| Unknown | 7 | 10,372,608 |
| **Total** | **2,384** | **12,582,912** |

The program catalogue has 1,469 conservative CPU-function candidates. The data
survey identifies 903 objects: 435 word regions, 19 pointer regions, 151 `f32`
objects, 216 `f64` objects, 19 strings, 61 jump tables, and 2 unreferenced
regions. These boundaries remain candidates until manually reviewed.

Audio parsing proves three `ALBankFile` containers and 93 ADPCM sample payloads.
It does not yet prove which samples are music or effects. Graphics scanning
finds 25 candidate F3DEX display lists (10 pooled blobs and 16 standalone
detections, with overlap); this is not a decoded model or texture count.

The address-level ledger is `rom_inventory.tsv`. It covers
`0x000000..0xC00000` without gaps or overlaps. `survey/report.json` preserves
the machine-readable evidence and `survey/report.md` documents caveats.

## Progress domains

The ByteMatch report intentionally tracks different claims independently:

| Domain | Complete bytes | Total bytes | Meaning |
|---|---:|---:|---|
| Byte-matched CPU code | 6,728 | 392,212 | C output verified against retail ROM bytes |
| Byte-matched initialized data | 0 | 129,864 | Reconstructed linked data verified byte-for-byte |
| Asset-region identification | 750,216 | 12,047,904 | Proven audio containers and sample payloads |
| Asset extraction | 0 | 750,216 | Identified assets emitted by a reproducible extraction pipeline |
| Physical ROM inventory | 12,582,912 | 12,582,912 | Every byte assigned one non-overlapping ledger interval |

Inventory coverage is not decompilation progress. Loader references prove that
code consumes a range, but do not identify its format; those bytes therefore
remain unidentified in the asset category.

