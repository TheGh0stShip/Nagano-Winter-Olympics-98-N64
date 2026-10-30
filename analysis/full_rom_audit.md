# Full-ROM decompilation audit

Retail ROM SHA-1: `eaf543e195731031a84f4136b506449209e3a8f5`. This audit scans all 12,582,912 physical bytes and all 1,470 surveyed program functions.

## Code census

- Exact matches: 1,470 functions / 391,940 bytes.
- Remaining: 0 functions / 0 surveyed bytes.
- Direct call sites: 3,930; indirect call sites: 64; branch sites: 7,046.
- COP1 instructions: 7,233.
- Exact duplicate groups: 28; structural duplicate groups: 97; structural groups with unmatched members: 0.
- Functions ending in one or more zero words: 862. These need boundary/padding review; a zero word is not automatically compiler-owned code.

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
- IDO 5.3: 772
- IDO 7.1: 614
- KMC GCC 2.7.2 + assembler: 55

### Program address bands

| ROM range | Functions | Matched | Matched bytes | Verified compiler units |
|---|---:|---:|---:|---|
| `0x1000..0x11000` | 234 | 234 | 65616 | hand-written assembly: 1, IDO 5.3: 64, IDO 7.1: 160, KMC GCC 2.7.2 + assembler: 9 |
| `0x11000..0x21000` | 243 | 243 | 65920 | IDO 7.1: 122, KMC GCC 2.7.2 + assembler: 11, IDO 5.3: 110 |
| `0x21000..0x31000` | 274 | 274 | 65220 | KMC GCC 2.7.2 + assembler: 10, IDO 7.1: 144, IDO 5.3: 120 |
| `0x31000..0x41000` | 239 | 239 | 65536 | IDO 7.1: 84, IDO 5.3: 142, KMC GCC 2.7.2 + assembler: 13 |
| `0x41000..0x51000` | 243 | 243 | 65444 | IDO 7.1: 104, IDO 5.3: 119, KMC GCC 2.7.2 + assembler: 9, hand-written assembly: 11 |
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

The ledger has 6,472 gap-free records.

| Class | Bytes | Records |
|---|---:|---:|
| compressed_container | 8,035,702 | 547 |
| audio_bank | 3,149,970 | 1,806 |
| executable_code | 796,368 | 18 |
| padding | 331,944 | 1,514 |
| initialized_data | 92,001 | 401 |
| animation_or_skeleton | 86,400 | 2 |
| code_unit_data | 53,129 | 1,740 |
| readonly_data | 27,964 | 399 |
| pointer_or_offset_table | 4,976 | 23 |
| rom_header_or_boot | 4,096 | 2 |
| text_or_string | 362 | 20 |

| Category | Bytes | Records |
|---|---:|---:|
| konami_lz.asset_file | 7,991,701 | 524 |
| vadpcm_sample | 3,079,110 | 327 |
| overlay_text | 395,320 | 13 |
| cpu_text | 393,752 | 3 |
| zero_alignment | 331,944 | 1,514 |
| data_words | 91,961 | 400 |
| s16x6_record_stream | 86,400 | 2 |
| overlay_data_words | 48,608 | 1,679 |
| libaudio.ALADPCMBook | 44,472 | 327 |
| konami_lz.music_sequence | 44,001 | 23 |
| data_f32 | 15,768 | 32 |
| rsp_ucode | 7,296 | 2 |
| libaudio.ALInstrument | 6,840 | 342 |
| libaudio.ALWaveTable | 6,540 | 327 |
| rodata_f64 | 6,252 | 216 |
| libaudio.ALADPCMloop | 6,000 | 125 |
| libaudio.ALSound | 5,472 | 342 |
| rodata_f32 | 4,760 | 119 |
| rodata_jtbl | 4,396 | 59 |
| asset_file_table | 4,304 | 1 |
| ipl3_cic6102 | 4,032 | 1 |
| libaudio.ALBank | 1,416 | 4 |
| rodata_words | 1,184 | 32 |
| data_pointers | 308 | 19 |
| overlay_table | 256 | 1 |
| rodata_string | 208 | 14 |
| data_string | 138 | 5 |
| data_jtbl | 125 | 2 |
| sequence_tables | 92 | 1 |
| n64_header | 64 | 1 |
| libaudio.ALEnvelope | 64 | 4 |
| data_unreferenced | 40 | 1 |
| libaudio.ALBankFile | 32 | 4 |
| libaudio.ALKeyMap | 24 | 4 |
| developer_signature | 16 | 1 |
| audio_bank_table | 16 | 1 |

### Largest unknown physical ranges


## Immediate attack queues

### Highest similarity to verified C


### Small direct-call functions


### Small leaf functions


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
4. Physical unknown coverage is zero. Continue nested-format work through loader references and round-trip parsers; do not treat container reconstruction as proof that every decoded child record is understood.
5. Re-run this audit after each matching or inventory campaign so queues and totals remain derived from authoritative manifests.
