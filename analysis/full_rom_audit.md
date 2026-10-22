# Full-ROM decompilation audit

Retail ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`. This audit scans all 12,582,912 physical bytes and all 1,469 surveyed program functions.

## Code census

- Exact matches: 374 functions / 15,740 bytes.
- Remaining: 1,095 functions / 376,388 surveyed bytes.
- Direct call sites: 3,929; indirect call sites: 64; branch sites: 7,046.
- COP1 instructions: 7,233.
- Exact duplicate groups: 26; structural duplicate groups: 95; structural groups with unmatched members: 23.
- Functions ending in one or more zero words: 864. These need boundary/padding review; a zero word is not automatically compiler-owned code.

### Size distribution

- <=0x10: 96
- <=0x20: 96
- <=0x40: 239
- <=0x80: 292
- <=0x100: 327
- <=0x200: 222
- <=0x400: 131
- <=0x800: 53
- >0x800: 13

### Verified compiler units

- IDO 5.3: 267
- KMC GCC 2.7.2 + assembler: 65
- IDO 7.1: 42

### Program address bands

| ROM range | Functions | Matched | Matched bytes | Verified compiler units |
|---|---:|---:|---:|---|
| `0x1000..0x11000` | 234 | 68 | 4452 | IDO 5.3: 36, KMC GCC 2.7.2 + assembler: 12, IDO 7.1: 20 |
| `0x11000..0x21000` | 243 | 90 | 3432 | KMC GCC 2.7.2 + assembler: 13, IDO 5.3: 68, IDO 7.1: 9 |
| `0x21000..0x31000` | 274 | 72 | 2456 | KMC GCC 2.7.2 + assembler: 10, IDO 5.3: 56, IDO 7.1: 6 |
| `0x31000..0x41000` | 239 | 65 | 2364 | IDO 5.3: 49, IDO 7.1: 3, KMC GCC 2.7.2 + assembler: 13 |
| `0x41000..0x51000` | 242 | 46 | 1792 | IDO 5.3: 34, KMC GCC 2.7.2 + assembler: 8, IDO 7.1: 4 |
| `0x51000..0x61000` | 237 | 33 | 1244 | IDO 5.3: 24, KMC GCC 2.7.2 + assembler: 9 |
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

- 0.96: `func_80004AE4` at `0x80004AE4` from `func_80004B1C` (src/game/clear_indexed_halfword_80004b1c.c).
- 0.94: `func_8000B99C` at `0x8000B99C` from `func_80036374` (src/game/call_80043c30_80036374.c).
- 0.93: `func_800132F4` at `0x800132F4` from `func_800131A4` (src/game/allocate_slot_800131a4.c).
- 0.93: `func_800132F4` at `0x800132F4` from `func_80013214` (src/game/allocate_slot_80013214.c).
- 0.93: `func_800132F4` at `0x800132F4` from `func_80013284` (src/game/allocate_slot_80013284.c).
- 0.90: `func_80003818` at `0x80003818` from `func_800036F8` (src/game/set_control_pair_800036f8.c).
- 0.90: `func_80003818` at `0x80003818` from `func_80003778` (src/game/set_control_pair_80003778.c).
- 0.90: `func_80003818` at `0x80003818` from `func_800037C8` (src/game/set_control_pair_800037c8.c).
- 0.88: `func_8003AEF4` at `0x8003AEF4` from `func_8003BEE4` (src/game/process_three_records_8003bee4.c).
- 0.83: `func_8000DD0C` at `0x8000DD0C` from `func_800138C4` (src/game/call_pair_800138c4.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_80011CB4` (src/game/call_80013404_80011cb4.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_80013108` (src/game/call_800130e0_80013108.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_8001CE98` (src/game/call_8001d0a0_8001ce98.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_8001CEB8` (src/game/call_80013404_8001ceb8.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_8001E810` (src/game/call_801954a0_8001e810.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_80020BD0` (src/game/call_80005c48_80020bd0.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_80022CF0` (src/game/call_80022e64_80022cf0.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_800308D4` (src/game/call_800304ec_800308d4.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_800348DC` (src/game/call_80043b58_800348dc.c).
- 0.82: `func_8000B99C` at `0x8000B99C` from `func_8003744C` (src/game/call_800370e0_8003744c.c).

### Small direct-call functions

- `func_800366E0` (`0x800366E0`, `0x34` bytes, 1 direct calls, 0 trailing nops)
- `func_8002D35C` (`0x8002D35C`, `0x38` bytes, 1 direct calls, 0 trailing nops)
- `func_800504B0` (`0x800504B0`, `0x40` bytes, 3 direct calls, 0 trailing nops)
- `func_8005DB40` (`0x8005DB40`, `0x40` bytes, 3 direct calls, 0 trailing nops)
- `func_800517B0` (`0x800517B0`, `0x40` bytes, 2 direct calls, 0 trailing nops)
- `func_8005FF40` (`0x8005FF40`, `0x40` bytes, 2 direct calls, 0 trailing nops)
- `func_800296C0` (`0x800296C0`, `0x4C` bytes, 2 direct calls, 0 trailing nops)
- `func_80004038` (`0x80004038`, `0x50` bytes, 1 direct calls, 0 trailing nops)
- `func_80013F98` (`0x80013F98`, `0x50` bytes, 1 direct calls, 0 trailing nops)
- `func_8001C3F0` (`0x8001C3F0`, `0x54` bytes, 2 direct calls, 0 trailing nops)
- `func_8001C89C` (`0x8001C89C`, `0x54` bytes, 1 direct calls, 0 trailing nops)
- `func_8003AEF4` (`0x8003AEF4`, `0x54` bytes, 1 direct calls, 0 trailing nops)
- `func_8002D304` (`0x8002D304`, `0x58` bytes, 1 direct calls, 0 trailing nops)
- `func_8003EDF4` (`0x8003EDF4`, `0x58` bytes, 1 direct calls, 0 trailing nops)
- `func_8002FCCC` (`0x8002FCCC`, `0x24` bytes, 1 direct calls, 1 trailing nops)
- `func_8002FD2C` (`0x8002FD2C`, `0x24` bytes, 1 direct calls, 1 trailing nops)
- `func_8002FD8C` (`0x8002FD8C`, `0x24` bytes, 1 direct calls, 1 trailing nops)
- `func_800529C8` (`0x800529C8`, `0x30` bytes, 2 direct calls, 1 trailing nops)
- `func_8002B81C` (`0x8002B81C`, `0x30` bytes, 1 direct calls, 1 trailing nops)
- `func_800348FC` (`0x800348FC`, `0x30` bytes, 1 direct calls, 1 trailing nops)

### Small leaf functions

- `func_8005FFF0` (`0x8005FFF0`, `0xC` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F954` (`0x8004F954`, `0x10` bytes, 0 direct calls, 0 trailing nops)
- `func_8004A3DC` (`0x8004A3DC`, `0x18` bytes, 0 direct calls, 0 trailing nops)
- `func_8005FFFC` (`0x8005FFFC`, `0x18` bytes, 0 direct calls, 0 trailing nops)
- `func_800596D0` (`0x800596D0`, `0x1C` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F7EC` (`0x8004F7EC`, `0x20` bytes, 0 direct calls, 0 trailing nops)
- `func_800570F0` (`0x800570F0`, `0x28` bytes, 0 direct calls, 0 trailing nops)
- `func_80000FA0` (`0x80000FA0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_80027CC0` (`0x80027CC0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F1F0` (`0x8004F1F0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_8005A530` (`0x8005A530`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_80003870` (`0x80003870`, `0x30` bytes, 0 direct calls, 0 trailing nops)
- `func_80005DE0` (`0x80005DE0`, `0x30` bytes, 0 direct calls, 0 trailing nops)
- `func_8001D7D8` (`0x8001D7D8`, `0x30` bytes, 0 direct calls, 0 trailing nops)
- `func_80038B20` (`0x80038B20`, `0x30` bytes, 0 direct calls, 0 trailing nops)
- `func_800554D0` (`0x800554D0`, `0x30` bytes, 0 direct calls, 0 trailing nops)
- `func_8005FF10` (`0x8005FF10`, `0x30` bytes, 0 direct calls, 0 trailing nops)
- `func_8001E020` (`0x8001E020`, `0x34` bytes, 0 direct calls, 0 trailing nops)
- `func_80037040` (`0x80037040`, `0x34` bytes, 0 direct calls, 0 trailing nops)
- `func_80037C3C` (`0x80037C3C`, `0x34` bytes, 0 direct calls, 0 trailing nops)

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
