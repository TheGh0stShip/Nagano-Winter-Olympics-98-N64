# Full-ROM decompilation audit

Retail ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`. This audit scans all 12,582,912 physical bytes and all 1,469 surveyed program functions.

## Code census

- Exact matches: 994 functions / 123,260 bytes.
- Remaining: 475 functions / 268,796 surveyed bytes.
- Direct call sites: 3,929; indirect call sites: 64; branch sites: 7,046.
- COP1 instructions: 7,233.
- Exact duplicate groups: 28; structural duplicate groups: 96; structural groups with unmatched members: 4.
- Functions ending in one or more zero words: 862. These need boundary/padding review; a zero word is not automatically compiler-owned code.

### Size distribution

- <=0x10: 96
- <=0x20: 98
- <=0x40: 238
- <=0x80: 292
- <=0x100: 326
- <=0x200: 222
- <=0x400: 131
- <=0x800: 53
- >0x800: 13

### Verified compiler units

- hand-written assembly: 23
- IDO 5.3: 708
- KMC GCC 2.7.2 + assembler: 59
- IDO 7.1: 204

### Program address bands

| ROM range | Functions | Matched | Matched bytes | Verified compiler units |
|---|---:|---:|---:|---|
| `0x1000..0x11000` | 234 | 135 | 11260 | hand-written assembly: 1, IDO 5.3: 73, KMC GCC 2.7.2 + assembler: 9, IDO 7.1: 52 |
| `0x11000..0x21000` | 243 | 160 | 10836 | IDO 5.3: 116, KMC GCC 2.7.2 + assembler: 13, IDO 7.1: 31 |
| `0x21000..0x31000` | 274 | 173 | 13440 | KMC GCC 2.7.2 + assembler: 10, IDO 5.3: 104, IDO 7.1: 59 |
| `0x31000..0x41000` | 239 | 147 | 10620 | IDO 7.1: 27, IDO 5.3: 107, KMC GCC 2.7.2 + assembler: 13 |
| `0x41000..0x51000` | 242 | 151 | 18084 | IDO 7.1: 35, IDO 5.3: 100, KMC GCC 2.7.2 + assembler: 9, hand-written assembly: 7 |
| `0x51000..0x61000` | 237 | 228 | 59020 | IDO 5.3: 208, hand-written assembly: 15, KMC GCC 2.7.2 + assembler: 5 |
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

- 0.85: `func_8002EA98` at `0x8002EA98` from `func_8002EB3C` (src/game/init_player_slot_8002eb3c.c).
- 0.76: `func_8002C934` at `0x8002C934` from `func_8002CB28` (src/game/advance_indexed_scene_8002cb28.c).
- 0.71: `func_8002BD84` at `0x8002BD84` from `func_8002BEBC` (src/game/convert_float_to_u16_8002bebc.c).
- 0.70: `func_80020BF0` at `0x80020BF0` from `func_8005AE70` (src/game/build_position_matrix_8005ae70.c).
- 0.69: `func_8002D5AC` at `0x8002D5AC` from `func_80029274` (src/game/store_scaled_unsigned_80029274.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_800462DC` (src/game/convert_scaled_byte_800462dc.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_80046550` (src/game/convert_scaled_byte_80046550.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_800466E0` (src/game/scaled_byte_conversions_800466e0.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_8004678C` (src/game/scaled_byte_conversions_800466e0.c).
- 0.63: `func_80046388` at `0x80046388` from `func_8002BEBC` (src/game/convert_float_to_u16_8002bebc.c).
- 0.63: `func_8004646C` at `0x8004646C` from `func_8002BEBC` (src/game/convert_float_to_u16_8002bebc.c).
- 0.63: `func_800465FC` at `0x800465FC` from `func_8002BEBC` (src/game/convert_float_to_u16_8002bebc.c).
- 0.61: `func_8002CBE4` at `0x8002CBE4` from `func_80029274` (src/game/store_scaled_unsigned_80029274.c).
- 0.60: `func_8002AA18` at `0x8002AA18` from `func_8002A7E0` (src/game/get_ranking_cell_value_8002a7e0.c).
- 0.58: `func_8004F724` at `0x8004F724` from `func_800503BC` (src/game/leo_interrupt_8004fc30.c).
- 0.58: `func_8002CBE4` at `0x8002CBE4` from `func_800462DC` (src/game/convert_scaled_byte_800462dc.c).
- 0.58: `func_8002CBE4` at `0x8002CBE4` from `func_80046550` (src/game/convert_scaled_byte_80046550.c).
- 0.58: `func_8002CBE4` at `0x8002CBE4` from `func_800466E0` (src/game/scaled_byte_conversions_800466e0.c).
- 0.58: `func_8002CBE4` at `0x8002CBE4` from `func_8004678C` (src/game/scaled_byte_conversions_800466e0.c).
- 0.57: `func_80006DC8` at `0x80006DC8` from `func_80006BA8` (src/game/mark_active_runtime_records_80006ba8.c).

### Small direct-call functions


### Small leaf functions

- `func_8004F1F0` (`0x8004F1F0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_80040DBC` (`0x80040DBC`, `0x5C` bytes, 0 direct calls, 0 trailing nops)
- `func_80020E70` (`0x80020E70`, `0x74` bytes, 0 direct calls, 0 trailing nops)
- `func_800212B4` (`0x800212B4`, `0x74` bytes, 0 direct calls, 0 trailing nops)
- `func_8003D0F0` (`0x8003D0F0`, `0x80` bytes, 0 direct calls, 0 trailing nops)
- `func_8002B67C` (`0x8002B67C`, `0xB0` bytes, 0 direct calls, 0 trailing nops)
- `func_8003E75C` (`0x8003E75C`, `0xB0` bytes, 0 direct calls, 0 trailing nops)
- `func_8002D5AC` (`0x8002D5AC`, `0xC4` bytes, 0 direct calls, 0 trailing nops)
- `func_80040E18` (`0x80040E18`, `0xC4` bytes, 0 direct calls, 0 trailing nops)
- `func_8001F0CC` (`0x8001F0CC`, `0xC8` bytes, 0 direct calls, 0 trailing nops)
- `func_8002F9B4` (`0x8002F9B4`, `0xCC` bytes, 0 direct calls, 0 trailing nops)
- `func_80001408` (`0x80001408`, `0xD0` bytes, 0 direct calls, 0 trailing nops)
- `func_80028504` (`0x80028504`, `0xD0` bytes, 0 direct calls, 0 trailing nops)
- `func_80024478` (`0x80024478`, `0xD4` bytes, 0 direct calls, 0 trailing nops)
- `func_8002CBE4` (`0x8002CBE4`, `0xD4` bytes, 0 direct calls, 0 trailing nops)
- `func_8002BD84` (`0x8002BD84`, `0xDC` bytes, 0 direct calls, 0 trailing nops)
- `func_80004A04` (`0x80004A04`, `0xE0` bytes, 0 direct calls, 0 trailing nops)
- `func_80023270` (`0x80023270`, `0xE4` bytes, 0 direct calls, 0 trailing nops)
- `func_80046388` (`0x80046388`, `0xE4` bytes, 0 direct calls, 0 trailing nops)
- `func_8004646C` (`0x8004646C`, `0xE4` bytes, 0 direct calls, 0 trailing nops)

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
