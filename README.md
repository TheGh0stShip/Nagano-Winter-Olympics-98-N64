# Nagano Winter Olympics '98 (USA) decompilation

[![Progress](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64.svg?mode=shield&label=Code&measure=matched_code_percent)](https://bytematch.dev/TheGh0stShip/Nagano-Winter-Olympics-98-N64)
[![Report](https://github.com/TheGh0stShip/Nagano-Winter-Olympics-98-N64/actions/workflows/progress.yml/badge.svg)](https://github.com/TheGh0stShip/Nagano-Winter-Olympics-98-N64/actions/workflows/progress.yml)

An in-progress, byte-matching C decompilation of the USA Nintendo 64 release.
You must provide your own legally obtained retail ROM.

## Verified baseline

- ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`
- Big-endian `.z64`, 12,582,912 bytes, CIC 6102, game code `NH5E`
- Initial program: ROM `0x1000..0x829E0`, VRAM `0x80000400..0x80081DE0`
- BSS: `0x80081DE0..0x801954A0`
- CPU text catalogue: 1,469 candidate functions / 392,212 bytes
- Program initialized data: 129,864 bytes
- RSP code identified inside the linked text section: 7,296 bytes
- SDK functions named: 241 (220 high-confidence)
- Audio: three libaudio bank files and 93 indexed ADPCM sample payloads
- Music: 23 loader-indexed Konami LZW sequence records decode successfully
- Matching C: 497 functions / 25,220 bytes
- Byte-matched initialized data: 56 / 129,864 bytes
- Identified post-program asset bytes: 794,392 / 12,047,904 bytes
- Extracted asset bytes: 0 / 794,392 identified bytes
- Physical ROM inventory: 12,582,912 / 12,582,912 bytes (100%)

Physical coverage does not mean semantic understanding. The conservative
inventory leaves 10,372,608 bytes in seven unknown ranges and identifies
880,904 bytes only through loader references. It does not claim unproven
texture, model, animation, or sound-effect counts. See
`analysis/rom_map.md` and the gap-free `analysis/rom_inventory.tsv`.
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

`make families` compares mnemonic-level instruction fingerprints across the
function catalogue and reports unmatched functions that share a shape with
verified C. Its output is candidate evidence only; every promoted result must
still pass `make verify-matching`.

