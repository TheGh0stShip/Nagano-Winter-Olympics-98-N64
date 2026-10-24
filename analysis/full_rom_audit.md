# Full-ROM decompilation audit

Retail ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`. This audit scans all 12,582,912 physical bytes and all 1,469 surveyed program functions.

## Code census

- Exact matches: 528 functions / 28,084 bytes.
- Remaining: 941 functions / 364,024 surveyed bytes.
- Direct call sites: 3,929; indirect call sites: 64; branch sites: 7,046.
- COP1 instructions: 7,233.
- Exact duplicate groups: 28; structural duplicate groups: 96; structural groups with unmatched members: 16.
- Functions ending in one or more zero words: 863. These need boundary/padding review; a zero word is not automatically compiler-owned code.

### Size distribution

- <=0x10: 96
- <=0x20: 98
- <=0x40: 237
- <=0x80: 292
- <=0x100: 327
- <=0x200: 222
- <=0x400: 131
- <=0x800: 53
- >0x800: 13

### Verified compiler units

- IDO 5.3: 373
- KMC GCC 2.7.2 + assembler: 67
- IDO 7.1: 88

### Program address bands

| ROM range | Functions | Matched | Matched bytes | Verified compiler units |
|---|---:|---:|---:|---|
| `0x1000..0x11000` | 234 | 97 | 6776 | IDO 5.3: 49, KMC GCC 2.7.2 + assembler: 12, IDO 7.1: 36 |
| `0x11000..0x21000` | 243 | 111 | 5140 | KMC GCC 2.7.2 + assembler: 13, IDO 5.3: 83, IDO 7.1: 15 |
| `0x21000..0x31000` | 274 | 103 | 5172 | KMC GCC 2.7.2 + assembler: 10, IDO 5.3: 77, IDO 7.1: 16 |
| `0x31000..0x41000` | 239 | 89 | 3916 | IDO 5.3: 68, IDO 7.1: 8, KMC GCC 2.7.2 + assembler: 13 |
| `0x41000..0x51000` | 242 | 79 | 5024 | IDO 7.1: 13, IDO 5.3: 56, KMC GCC 2.7.2 + assembler: 10 |
| `0x51000..0x61000` | 237 | 49 | 2056 | IDO 5.3: 40, KMC GCC 2.7.2 + assembler: 9 |
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

- 0.80: `func_8002EC10` at `0x8002EC10` from `func_80004B50` (src/game/copy_template_80004b50.c).
- 0.80: `func_8002EC10` at `0x8002EC10` from `func_8000DCC0` (src/game/copy_template_8000dcc0.c).
- 0.80: `func_8002EC10` at `0x8002EC10` from `func_8000FCA8` (src/game/copy_template_8000fca8.c).
- 0.72: `func_8004CBFC` at `0x8004CBFC` from `func_8004CB64` (src/game/update_stream_motion_command_8004cb64.c).
- 0.71: `func_8004BA1C` at `0x8004BA1C` from `func_8004C804` (src/game/read_stream_motion_duration_8004c804.c).
- 0.71: `func_8004BE6C` at `0x8004BE6C` from `func_8004C804` (src/game/read_stream_motion_duration_8004c804.c).
- 0.71: `func_8000DA60` at `0x8000DA60` from `func_80005D74` (src/game/collect_flags_80005d74.c).
- 0.70: `func_8003CECC` at `0x8003CECC` from `func_8003CE68` (src/game/update_motion_angle_8003ce68.c).
- 0.69: `func_8002D5AC` at `0x8002D5AC` from `func_80029274` (src/game/store_scaled_unsigned_80029274.c).
- 0.68: `func_800127BC` at `0x800127BC` from `func_800036F8` (src/game/set_control_pair_800036f8.c).
- 0.68: `func_800127BC` at `0x800127BC` from `func_80003778` (src/game/set_control_pair_80003778.c).
- 0.68: `func_800127BC` at `0x800127BC` from `func_800037C8` (src/game/set_control_pair_800037c8.c).
- 0.68: `func_800127BC` at `0x800127BC` from `func_80003818` (src/game/set_control_pair_80003818.c).
- 0.68: `func_8002EC10` at `0x8002EC10` from `func_8000499C` (src/game/copy_selected_template_8000499c.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_800462DC` (src/game/convert_scaled_byte_800462dc.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_80046550` (src/game/convert_scaled_byte_80046550.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_800466E0` (src/game/convert_scaled_byte_800466e0.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_8004678C` (src/game/convert_scaled_byte_8004678c.c).
- 0.65: `func_8000DA60` at `0x8000DA60` from `func_80005C48` (src/game/collect_flags_80005c48.c).
- 0.65: `func_8000DA60` at `0x8000DA60` from `func_80005CAC` (src/game/collect_flags_80005cac.c).

### Small direct-call functions

- `func_800366E0` (`0x800366E0`, `0x34` bytes, 1 direct calls, 0 trailing nops)
- `func_8001C3F0` (`0x8001C3F0`, `0x54` bytes, 2 direct calls, 0 trailing nops)
- `func_8001C89C` (`0x8001C89C`, `0x54` bytes, 1 direct calls, 0 trailing nops)
- `func_8003EDF4` (`0x8003EDF4`, `0x58` bytes, 1 direct calls, 0 trailing nops)
- `func_80025F90` (`0x80025F90`, `0x40` bytes, 2 direct calls, 1 trailing nops)
- `func_80038FC4` (`0x80038FC4`, `0x40` bytes, 1 direct calls, 1 trailing nops)
- `func_80037074` (`0x80037074`, `0x44` bytes, 1 direct calls, 1 trailing nops)
- `func_80011CE4` (`0x80011CE4`, `0x48` bytes, 2 direct calls, 1 trailing nops)
- `func_80031E7C` (`0x80031E7C`, `0x48` bytes, 2 direct calls, 1 trailing nops)
- `func_80037348` (`0x80037348`, `0x50` bytes, 2 direct calls, 1 trailing nops)
- `func_8005AE20` (`0x8005AE20`, `0x50` bytes, 2 direct calls, 1 trailing nops)
- `func_8005C8B0` (`0x8005C8B0`, `0x50` bytes, 2 direct calls, 1 trailing nops)
- `func_8002F724` (`0x8002F724`, `0x50` bytes, 1 direct calls, 1 trailing nops)
- `func_800522D0` (`0x800522D0`, `0x50` bytes, 1 direct calls, 1 trailing nops)
- `func_80001768` (`0x80001768`, `0x54` bytes, 1 direct calls, 1 trailing nops)
- `func_8000A834` (`0x8000A834`, `0x54` bytes, 1 direct calls, 1 trailing nops)
- `func_8000A888` (`0x8000A888`, `0x54` bytes, 1 direct calls, 1 trailing nops)
- `func_800127BC` (`0x800127BC`, `0x54` bytes, 1 direct calls, 1 trailing nops)
- `func_80040C70` (`0x80040C70`, `0x54` bytes, 1 direct calls, 1 trailing nops)
- `func_80013374` (`0x80013374`, `0x58` bytes, 3 direct calls, 1 trailing nops)

### Small leaf functions

- `func_8005FFF0` (`0x8005FFF0`, `0xC` bytes, 0 direct calls, 0 trailing nops)
- `func_8005FFFC` (`0x8005FFFC`, `0x18` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F7EC` (`0x8004F7EC`, `0x20` bytes, 0 direct calls, 0 trailing nops)
- `func_80000FA0` (`0x80000FA0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F1F0` (`0x8004F1F0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_8005FF10` (`0x8005FF10`, `0x30` bytes, 0 direct calls, 0 trailing nops)
- `func_800306CC` (`0x800306CC`, `0x40` bytes, 0 direct calls, 0 trailing nops)
- `func_8004FAF0` (`0x8004FAF0`, `0x40` bytes, 0 direct calls, 0 trailing nops)
- `func_8000C190` (`0x8000C190`, `0x44` bytes, 0 direct calls, 0 trailing nops)
- `func_8001805C` (`0x8001805C`, `0x44` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F90C` (`0x8004F90C`, `0x48` bytes, 0 direct calls, 0 trailing nops)
- `func_8001CBA8` (`0x8001CBA8`, `0x50` bytes, 0 direct calls, 0 trailing nops)
- `func_8005DB80` (`0x8005DB80`, `0x50` bytes, 0 direct calls, 0 trailing nops)
- `func_8005DBD0` (`0x8005DBD0`, `0x50` bytes, 0 direct calls, 0 trailing nops)
- `func_8002B5D0` (`0x8002B5D0`, `0x54` bytes, 0 direct calls, 0 trailing nops)
- `func_8002EC10` (`0x8002EC10`, `0x54` bytes, 0 direct calls, 0 trailing nops)
- `func_80013058` (`0x80013058`, `0x58` bytes, 0 direct calls, 0 trailing nops)
- `func_80046BA4` (`0x80046BA4`, `0x58` bytes, 0 direct calls, 0 trailing nops)
- `func_800553C8` (`0x800553C8`, `0x58` bytes, 0 direct calls, 0 trailing nops)
- `func_8002BE60` (`0x8002BE60`, `0x5C` bytes, 0 direct calls, 0 trailing nops)

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
