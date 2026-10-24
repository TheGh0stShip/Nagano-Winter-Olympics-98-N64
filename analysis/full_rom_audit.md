# Full-ROM decompilation audit

Retail ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`. This audit scans all 12,582,912 physical bytes and all 1,469 surveyed program functions.

## Code census

- Exact matches: 598 functions / 34,468 bytes.
- Remaining: 871 functions / 357,628 surveyed bytes.
- Direct call sites: 3,929; indirect call sites: 64; branch sites: 7,046.
- COP1 instructions: 7,233.
- Exact duplicate groups: 28; structural duplicate groups: 96; structural groups with unmatched members: 15.
- Functions ending in one or more zero words: 863. These need boundary/padding review; a zero word is not automatically compiler-owned code.

### Size distribution

- <=0x10: 96
- <=0x20: 98
- <=0x40: 237
- <=0x80: 293
- <=0x100: 326
- <=0x200: 222
- <=0x400: 131
- <=0x800: 53
- >0x800: 13

### Verified compiler units

- IDO 5.3: 427
- KMC GCC 2.7.2 + assembler: 67
- IDO 7.1: 104

### Program address bands

| ROM range | Functions | Matched | Matched bytes | Verified compiler units |
|---|---:|---:|---:|---|
| `0x1000..0x11000` | 234 | 101 | 7164 | IDO 5.3: 51, KMC GCC 2.7.2 + assembler: 12, IDO 7.1: 38 |
| `0x11000..0x21000` | 243 | 115 | 5484 | KMC GCC 2.7.2 + assembler: 13, IDO 5.3: 86, IDO 7.1: 16 |
| `0x21000..0x31000` | 274 | 111 | 5624 | KMC GCC 2.7.2 + assembler: 10, IDO 5.3: 83, IDO 7.1: 18 |
| `0x31000..0x41000` | 239 | 93 | 4164 | IDO 5.3: 71, IDO 7.1: 9, KMC GCC 2.7.2 + assembler: 13 |
| `0x41000..0x51000` | 242 | 93 | 6600 | IDO 7.1: 23, IDO 5.3: 60, KMC GCC 2.7.2 + assembler: 10 |
| `0x51000..0x61000` | 237 | 85 | 5432 | IDO 5.3: 76, KMC GCC 2.7.2 + assembler: 9 |
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
- 0.71: `func_8004BA1C` at `0x8004BA1C` from `func_8004C804` (src/game/read_stream_motion_duration_8004c804.c).
- 0.71: `func_8004BE6C` at `0x8004BE6C` from `func_8004C804` (src/game/read_stream_motion_duration_8004c804.c).
- 0.71: `func_8000DA60` at `0x8000DA60` from `func_80005D74` (src/game/collect_flags_80005d74.c).
- 0.70: `func_8003CECC` at `0x8003CECC` from `func_8003CE68` (src/game/update_motion_angle_8003ce68.c).
- 0.69: `func_8002D5AC` at `0x8002D5AC` from `func_80029274` (src/game/store_scaled_unsigned_80029274.c).
- 0.68: `func_8002EC10` at `0x8002EC10` from `func_8000499C` (src/game/copy_selected_template_8000499c.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_800462DC` (src/game/convert_scaled_byte_800462dc.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_80046550` (src/game/convert_scaled_byte_80046550.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_800466E0` (src/game/convert_scaled_byte_800466e0.c).
- 0.67: `func_8002D5AC` at `0x8002D5AC` from `func_8004678C` (src/game/convert_scaled_byte_8004678c.c).
- 0.65: `func_8000DA60` at `0x8000DA60` from `func_80005C48` (src/game/collect_flags_80005c48.c).
- 0.65: `func_8000DA60` at `0x8000DA60` from `func_80005CAC` (src/game/collect_flags_80005cac.c).
- 0.65: `func_8000DA60` at `0x8000DA60` from `func_80005D10` (src/game/collect_flags_80005d10.c).
- 0.65: `func_8004872C` at `0x8004872C` from `func_8004D70C` (src/game/queue_stream_event_8004d70c.c).
- 0.64: `func_8004EEDC` at `0x8004EEDC` from `func_800138C4` (src/game/call_pair_800138c4.c).
- 0.64: `func_8002EC10` at `0x8002EC10` from `func_8000ECBC` (src/game/load_indexed_blob_8000ecbc.c).
- 0.64: `func_8002EC10` at `0x8002EC10` from `func_8000F2B4` (src/game/store_indexed_blob_8000f2b4.c).

### Small direct-call functions

- `func_800366E0` (`0x800366E0`, `0x34` bytes, 1 direct calls, 0 trailing nops)
- `func_8001C3F0` (`0x8001C3F0`, `0x54` bytes, 2 direct calls, 0 trailing nops)
- `func_80037074` (`0x80037074`, `0x44` bytes, 1 direct calls, 1 trailing nops)
- `func_80011CE4` (`0x80011CE4`, `0x48` bytes, 2 direct calls, 1 trailing nops)
- `func_80037348` (`0x80037348`, `0x50` bytes, 2 direct calls, 1 trailing nops)
- `func_80040C70` (`0x80040C70`, `0x54` bytes, 1 direct calls, 1 trailing nops)
- `func_8003227C` (`0x8003227C`, `0x58` bytes, 2 direct calls, 1 trailing nops)
- `func_80005E18` (`0x80005E18`, `0x58` bytes, 1 direct calls, 1 trailing nops)
- `func_8001F96C` (`0x8001F96C`, `0x58` bytes, 1 direct calls, 1 trailing nops)
- `func_80039ACC` (`0x80039ACC`, `0x58` bytes, 1 direct calls, 1 trailing nops)
- `func_8003F9E0` (`0x8003F9E0`, `0x58` bytes, 1 direct calls, 1 trailing nops)
- `func_8001D414` (`0x8001D414`, `0x5C` bytes, 4 direct calls, 1 trailing nops)
- `func_80001650` (`0x80001650`, `0x5C` bytes, 3 direct calls, 1 trailing nops)
- `func_8002F900` (`0x8002F900`, `0x5C` bytes, 3 direct calls, 1 trailing nops)
- `func_8001DD08` (`0x8001DD08`, `0x60` bytes, 2 direct calls, 1 trailing nops)
- `func_8002AACC` (`0x8002AACC`, `0x60` bytes, 2 direct calls, 1 trailing nops)
- `func_80037AA0` (`0x80037AA0`, `0x60` bytes, 1 direct calls, 1 trailing nops)
- `func_8004EEDC` (`0x8004EEDC`, `0x44` bytes, 3 direct calls, 2 trailing nops)
- `func_8003FF50` (`0x8003FF50`, `0x50` bytes, 1 direct calls, 3 trailing nops)
- `func_800520C0` (`0x800520C0`, `0x60` bytes, 2 direct calls, 3 trailing nops)

### Small leaf functions

- `func_8005FFF0` (`0x8005FFF0`, `0xC` bytes, 0 direct calls, 0 trailing nops)
- `func_8005FFFC` (`0x8005FFFC`, `0x18` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F7EC` (`0x8004F7EC`, `0x20` bytes, 0 direct calls, 0 trailing nops)
- `func_80000FA0` (`0x80000FA0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F1F0` (`0x8004F1F0`, `0x2C` bytes, 0 direct calls, 0 trailing nops)
- `func_800306CC` (`0x800306CC`, `0x40` bytes, 0 direct calls, 0 trailing nops)
- `func_8000C190` (`0x8000C190`, `0x44` bytes, 0 direct calls, 0 trailing nops)
- `func_8001805C` (`0x8001805C`, `0x44` bytes, 0 direct calls, 0 trailing nops)
- `func_8004F90C` (`0x8004F90C`, `0x48` bytes, 0 direct calls, 0 trailing nops)
- `func_8001CBA8` (`0x8001CBA8`, `0x50` bytes, 0 direct calls, 0 trailing nops)
- `func_8002B5D0` (`0x8002B5D0`, `0x54` bytes, 0 direct calls, 0 trailing nops)
- `func_8002EC10` (`0x8002EC10`, `0x54` bytes, 0 direct calls, 0 trailing nops)
- `func_80046BA4` (`0x80046BA4`, `0x58` bytes, 0 direct calls, 0 trailing nops)
- `func_8002BE60` (`0x8002BE60`, `0x5C` bytes, 0 direct calls, 0 trailing nops)
- `func_80031E20` (`0x80031E20`, `0x5C` bytes, 0 direct calls, 0 trailing nops)
- `func_80040DBC` (`0x80040DBC`, `0x5C` bytes, 0 direct calls, 0 trailing nops)
- `func_8004B384` (`0x8004B384`, `0x5C` bytes, 0 direct calls, 0 trailing nops)
- `func_8004BE10` (`0x8004BE10`, `0x5C` bytes, 0 direct calls, 0 trailing nops)
- `func_8002F5D4` (`0x8002F5D4`, `0x60` bytes, 0 direct calls, 0 trailing nops)
- `func_8000C6AC` (`0x8000C6AC`, `0x64` bytes, 0 direct calls, 0 trailing nops)

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
