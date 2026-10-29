# Nagano Winter Olympics '98 (USA) decompilation

[![Code](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64)
[![Functions](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64.svg?mode=shield&label=Functions&measure=matched_functions)](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64)
[![Report](https://github.com/TheGh0stShip/Nagano-Winter-Olympics-98-N64/actions/workflows/progress.yml/badge.svg)](https://github.com/TheGh0stShip/Nagano-Winter-Olympics-98-N64/actions/workflows/progress.yml)

An in-progress, byte-matching C decompilation of the USA Nintendo 64 release.
You must provide your own legally obtained retail ROM.

## Verified baseline

- ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`
- Big-endian `.z64`, 12,582,912 bytes, CIC 6102, game code `NH5E`
- Initial program: ROM `0x1000..0x829E0`, VRAM `0x80000400..0x80081DE0`
- BSS: `0x80081DE0..0x801954A0`
- CPU text catalogue: 1,470 candidate functions / 391,964 function bytes
- Tracker CPU-code denominator: 392,172 bytes, including 208 bytes of
  alignment/linker code-section padding outside the function catalogue
- Program initialized data: 129,824 bytes, plus 40 bytes of verified linker padding
- RSP code identified inside the linked text section: 7,296 bytes
- SDK functions named: 241 (220 high-confidence)
- Audio: four libaudio bank files and 327 indexed VADPCM sample payloads
- Music: 23 loader-indexed Konami LZ sequences, 297 tracks, and 33,236 Nagano/Konami events decode and rebuild exactly
- Matching source: 1,469 functions / 390,132 function bytes in 1,327 verified units
- Byte-matched initialized data: 129,824 / 129,824 bytes (100%)
- Classified post-program bytes: 12,047,904 / 12,047,904 bytes (100%)
- Classified decoded-container bytes: 13,997,274 / 14,762,912 bytes (94.81%)
- Extracted redistributable asset bytes: 0 (none are committed)
- Physical ROM inventory: 12,582,912 / 12,582,912 bytes (100%)

Physical coverage does not mean semantic understanding. The exact physical
ledger classifies every ROM byte and reconstructs every non-code range, while
its reproducible nested asset map still leaves 765,638 decoded bytes structurally unknown
across 235 files, plus 870,338 unreferenced zero bytes that are not yet proven
padding. See `analysis/data_map/README.md` and the gap-free
`analysis/data_map/rom_map.tsv`; the earlier conservative inventory remains as
historical evidence rather than the authoritative data map.
These ranges are not unmatched data: their original container bytes decode and
re-encode exactly. Consequently, no non-function byte-matching work remains.
Further names and field meanings improve semantic documentation but do not
change byte-match progress unless new evidence changes a structural boundary.
The generated [full-ROM audit](analysis/full_rom_audit.md) records structural
metrics and prioritized function queues without promoting heuristic findings.

## Verification

Place the ROM at `baseroms/us/baserom.z64` (a symlink is fine), then run:

```sh
make check
```

The default build reuses `../n64-decomp-kit` and `../BattleTanx/.toolchain`.
Override `N64DK_ROOT` or `N64DK_TOOLCHAIN` for another installation.
`make verify-matching` recompiles every manifest row and compares relocated
bytes directly with the retail ROM. `make report` produces the objdiff v2
report published as `NH5E_report` for ByteMatch (with the original
`us_report` artifact retained during migration).

The report keeps separate categories for byte-matched program code,
byte-matched initialized data, identified bytes in the post-program asset
region, reproducibly extracted asset bytes, and gap-free physical inventory.
Only code and initialized data contribute to aggregate decompilation progress.
Identified audio is not reported as extracted, and loader-referenced ranges do
not count as identified assets until their formats are decoded.

## Progress trackers

- [ByteMatch](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64)
  consumes the `NH5E_report` artifact published by every successful push to
  `main`. The legacy `us_report` artifact carries the same report so its
  retained history stays accurate.
- [recomp.fyi](https://recomp.fyi/) and compatible project directories consume
  the root [`.recomp.json`](.recomp.json) manifest. It records the exact USA
  revision, ROM identity, project status, method, maintainership, and live
  ByteMatch report without conflating decompilation with asset inventory.

The machine-readable report is also available directly from
[ByteMatch as JSON](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64.json).

`make families` compares mnemonic-level instruction fingerprints across the
function catalogue and reports unmatched functions that share a shape with
verified C. Its output is candidate evidence only; every promoted result must
still pass `make verify-matching`.

`make unmatched` prints the remaining function queue in stable size/address
order across every matching manifest. This prevents already verified units
from being re-investigated when selecting batch candidates.

