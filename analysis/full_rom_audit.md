# Full-ROM decompilation audit

Retail ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`. This audit scans all 12,582,912 physical bytes and all 1,470 surveyed program functions.

## Code census

- Exact matches: 1,457 functions / 379,832 bytes.
- Remaining: 13 functions / 12,116 surveyed bytes.
- Direct call sites: 3,930; indirect call sites: 64; branch sites: 7,046.
- COP1 instructions: 7,233.
- Exact duplicate groups: 28; structural duplicate groups: 97; structural groups with unmatched members: 0.
- Functions ending in one or more zero words: 863. These need boundary/padding review; a zero word is not automatically compiler-owned code.

### Size distribution

- <=0x10: 100
- <=0x20: 95
- <=0x40: 238
- <=0x80: 292
- <=0x100: 326
- <=0x200: 222
- <=0x400: 131
- <=0x800: 53
- >0x800: 13

### Verified compiler units

- hand-written assembly: 29
- IDO 5.3: 771
- IDO 7.1: 602
- KMC GCC 2.7.2 + assembler: 55

### Program address bands

| ROM range | Functions | Matched | Matched bytes | Verified compiler units |
|---|---:|---:|---:|---|
| `0x1000..0x11000` | 234 | 230 | 60596 | hand-written assembly: 1, IDO 5.3: 64, IDO 7.1: 156, KMC GCC 2.7.2 + assembler: 9 |
| `0x11000..0x21000` | 243 | 239 | 63024 | IDO 7.1: 118, KMC GCC 2.7.2 + assembler: 11, IDO 5.3: 110 |
| `0x21000..0x31000` | 274 | 273 | 62912 | KMC GCC 2.7.2 + assembler: 10, IDO 7.1: 143, IDO 5.3: 120 |
| `0x31000..0x41000` | 239 | 239 | 65536 | IDO 7.1: 84, IDO 5.3: 142, KMC GCC 2.7.2 + assembler: 13 |
| `0x41000..0x51000` | 243 | 239 | 63560 | IDO 7.1: 101, IDO 5.3: 118, KMC GCC 2.7.2 + assembler: 9, hand-written assembly: 11 |
| `0x51000..0x61000` | 237 | 237 | 64204 | IDO 5.3: 217, hand-written assembly: 17, KMC GCC 2.7.2 + assembler: 3 |
| `0x61000..0x71000` | 0 | 0 | 0 | none |
| `0x71000..0x81000` | 0 | 0 | 0 | none |
| `0x81000..0x829E0` | 0 | 0 | 0 | none |

## Whole-ROM structural scan

- Printable ASCII runs of at least four bytes: 85,369, spanning 504,692 bytes.
- Pointer-like aligned words: program_or_bss_vram=7,151, possible_rom_offset=90,697, rsp_address=26,028.
- Lowest-entropy 64 KiB banks: 0xBC0000 (-0.0000), 0xBD0000 (-0.0000), 0xBE0000 (-0.0000), 0xBF0000 (-0.0000), 0xBB0000 (0.5056).
- Highest-entropy 64 KiB banks: 0x510000 (7.6862), 0x690000 (7.6676), 0xA60000 (7.6451), 0x620000 (7.6058), 0xAA0000 (7.6050).

Entropy, printable runs, and pointer-like words are discovery signals only; they do not change inventory classifications.

## Physical inventory

The ledger has 2,384 gap-free records.

| Class | Bytes | Records |
|---|---:|---:|
| unknown | 10,372,608 | 7 |
| referenced | 880,904 | 1,013 |
| payload | 690,910 | 93 |
| code | 401,048 | 5 |
| data | 129,864 | 3 |
| container | 103,482 | 1,261 |
| rom_metadata | 4,096 | 2 |

| Category | Bytes | Records |
|---|---:|---:|
| - | 10,372,608 | 7 |
| loader_range | 880,904 | 1,013 |
| audio | 750,216 | 1,331 |
| program | 530,912 | 8 |
| music | 44,176 | 23 |
| rom_metadata | 4,096 | 2 |

### Largest unknown physical ranges

- `0x3FC620..0xC00000`: 8,403,424 bytes (gap_3FC620).
- `0x2E6E60..0x3F1990`: 1,092,400 bytes (gap_2E6E60).
- `0x1AA5E0..0x23C550`: 597,872 bytes (gap_1AA5E0).
- `0xB5110..0xD8CC0`: 146,352 bytes (gap_B5110).
- `0x8A5F0..0xA15F0`: 94,208 bytes (gap_8A5F0).
- `0xDA200..0xDFB40`: 22,848 bytes (gap_DA200).
- `0xEB3B0..0xEF040`: 15,504 bytes (gap_EB3B0).

## Immediate attack queues

### Highest similarity to verified C


### Small direct-call functions


### Small leaf functions

- `func_8001F0CC` (`0x8001F0CC`, `0xC8` bytes, 0 direct calls, 0 trailing nops)
- `func_80048A78` (`0x80048A78`, `0x7C` bytes, 0 direct calls, 1 trailing nops)
- `func_8001FC18` (`0x8001FC18`, `0x160` bytes, 0 direct calls, 1 trailing nops)
- `func_8000D218` (`0x8000D218`, `0x718` bytes, 0 direct calls, 2 trailing nops)

### Most referenced local functions

- `func_800279B8`: 76 direct call sites.
- `func_80027AE0`: 73 direct call sites.
- `func_8005C4E0`: 69 direct call sites.
- `func_8004E9D0`: 62 direct call sites.
- `func_80048580`: 58 direct call sites.
- `func_80005E18`: 54 direct call sites.
- `func_8004E540`: 48 direct call sites.
- `func_8004EF88`: 43 direct call sites.
- `func_80005550`: 41 direct call sites.
- `func_80039004`: 37 direct call sites.
- `func_800437A0`: 32 direct call sites.
- `func_8003EC10`: 32 direct call sites.
- `func_80043E08`: 31 direct call sites.
- `func_800512C0`: 30 direct call sites.
- `func_8005BFF0`: 29 direct call sites.
- `func_80059410`: 27 direct call sites.
- `func_800485AC`: 26 direct call sites.
- `func_800596EC`: 26 direct call sites.
- `func_8005BFD0`: 26 direct call sites.
- `func_80001B7C`: 25 direct call sites.

## Conclusions

1. Work the similarity queue first, but reject candidates whose only residual is unproven boundary padding rather than forcing inline assembly.
2. Split the small-wrapper queue by compiler evidence and callee prototype; these are the next broad source-transfer opportunity.
3. Treat the small-leaf queue as arithmetic, accessors, and SDK-signature work; MIPS III 64-bit helpers need per-unit `-mips3 -32` flags.
4. Attack unknown physical ranges through loader references and round-trip parsers. Do not convert pointer-like words or entropy boundaries directly into asset claims.
5. Re-run this audit after each matching or inventory campaign so queues and totals remain derived from authoritative manifests.
