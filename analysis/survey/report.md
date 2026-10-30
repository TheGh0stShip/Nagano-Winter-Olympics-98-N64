# Survey: NAGANO OLYMPICS (NH5E)

> **Historical survey snapshot.** These figures record the initial automated
> survey, not current completion status. The 1,469-function count predates the
> verified split at `0x8000D218`; see the repository README and
> `analysis/full_rom_audit.md` for the final 1,470-function catalogue.

- **Program**: static image, main segment 0x80000400..0x80081DE0 (rom); 1469 functions, 241 named from the SDK
- **ROM understood**: 10.2 % by content, plus 7.4 % only referenced by loader tables; 10,372,608 bytes unknown in 7 ranges
- **Next**: ROM 0x3FC620..0xC00000 (0x8039e0 bytes) is unclassified; 7.1 bits/byte, zlib ratio 0.86: raw media or lightly packed data (audio, textures, animation)
- **Next**: ROM 0x2E6E60..0x3F1990 (0x10ab30 bytes) is unclassified; 7.3 bits/byte, zlib ratio 0.92: raw media or lightly packed data (audio, textures, animation)
- **Next**: ROM 0x1AA5E0..0x23C550 (0x91f70 bytes) is unclassified; 7.2 bits/byte, zlib ratio 0.91: raw media or lightly packed data (audio, textures, animation)

## ROM

- **title**: NAGANO OLYMPICS
- **game_code**: NH5E
- **version**: 0
- **sha1**: eaf543e195731031a84f4136b506449209e3a8f5
- **size**: 12582912
- **byte_order**: z64
- **cic**: 6102
- **checksum_ok**: True
- **entry_header**: 0x80000400
- **entry**: 0x80000400
- **crc**: 8D2BAE98/D73725BF

## Program image

- method: static; entry 0x80000400; hand-over 0x80000460; stack 0x80083E58

| vram | end | size | kind | ROM | codec | evidence |
|---|---|---|---|---|---|---|
| 0x80000400 | 0x80081DE0 | 0x819E0 | rom | 0x1000..0x829E0 | - | IPL3 copy |
| 0x80081DE0 | 0x801954A0 | 0x1136C0 | bss | - | - | entry routine clear loop |

Offsets below are ROM offsets.

## Functions

- **text**: 0x80000400..0x80060014
- **text_size**: 392212
- **data_start**: 0x80060014
- **image_end**: 0x80081DE0
- **functions**: 1469
- **kinds**: {'asm': 23, 'c': 940, 'leaf': 412, 'O0': 1, 'stub': 93}
- **seeds**: {'entry': 1, 'call': 1060, 'pointer': 100, 'unreferenced': 308}
- **jump_tables**: 59
- **jump_table_entries**: 1048
- **in_text_data**: ['0x8004F7D8+0x14', '0x8004FAE0+0x10', '0x8005FFC0+0x30']
- **stray_words**: 0
- **findings**: {'in_text_data': 3, 'falls_through': 3, 'branch_outside': 1, 'cross_branch': 1}

## Data map

- **image**: 0x80000400..0x80081DE0 (ROM 0x1000..0x829E0)
- **bss**: 0x80081DE0..0x801954A0
- **sections**: ['.text 0x80000400..0x80000438 (0x38)', '.data 0x80000438..0x80000460 (0x28)', '.text 0x80000460..0x8006161C (0x611BC)', '.data 0x8006161C..0x8007DC40 (0x1C624)', '.rodata 0x8007DC40..0x80081DE0 (0x41A0)']
- **section_bytes**: {'.text': '0x611f4', '.data': '0x1c64c', '.rodata': '0x41a0'}
- **functions**: 1666
- **xref_sites**: 1878
- **data_addresses**: 944
- **objects**: 903
- **object_types**: {'unreferenced': 2, 'words': 435, 'pointers': 19, 'f32': 151, 'string': 19, 'jtbl': 61, 'f64': 216}
- **single_owner_objects**: 781
- **shared_objects**: 120
- **jump_tables**: 61
- **strings**: 19

## SDK

- **functions_named**: 241
- **high_confidence**: 220
- **sdk_version**: ['2.0D/2.0E/2.0F/2.0G/2.0H:libultra_rom', '2.0D/2.0E/2.0F/2.0G/2.0H:libultra']
- **library_compiler**: {'ido': 213}
- **game_compiler**: ido
- **game_compiler_share**: {'ido': 0.983, 'kmc': 0.017}
- **microcode**: ['F3DEX 1.21 @0x821D0']
- **audio**: {'ALBankFile': 3}
- **libmus**: []

## Audio

- **counts**: {'containers': 3, 'samples': 93, 'midi': 0, 'intervals': 2337}
- **bytes**: {'container': 59306, 'padding': 5176, 'payload': 690910}

## Graphics

- **family**: f3dex
- **family_from**: microcode F3DEX 1.21 at ROM 0x821D0
- **display_lists**: 25
- **pools**: ['0x6D180..0x6D440 (10 blobs)']
- **blobs**: 10
- **textured_blobs**: 0
- **pool_bytes**: 704
- **standalone_lists**: 16

## Compressed streams and loader ranges

- **streams**: {}
- **streams_with_loader**: 0
- **loader_ranges**: {'records': 115, 'table': 4}
- **dma_wrappers**: []
- **ledger_bytes**: {'-': 10759784, 'loader_range': 1823128}
- **unknown_bytes**: 10755688

## ROM ledger

- complete: **False** (unknown bytes: 10,372,608 in 7 ranges)

| class | bytes |
|---|---|
| unknown | 10,372,608 |
| referenced | 925,080 |
| payload | 690,910 |
| code | 401,048 |
| data | 129,864 |
| container | 59,306 |
| rom_metadata | 4,096 |

| category | bytes |
|---|---|
| - | 10,372,608 |
| loader_range | 925,080 |
| audio | 750,216 |
| program | 530,912 |
| rom_metadata | 4,096 |

Largest unknown ranges:

- 0x3FC620..0xC00000 (0x8039e0)
- 0x2E6E60..0x3F1990 (0x10ab30)
- 0x1AA5E0..0x23C550 (0x91f70)
- 0xB5110..0xD8CC0 (0x23bb0)
- 0x8A5F0..0xA15F0 (0x17000)
- 0xDA200..0xDFB40 (0x5940)
- 0xEB3B0..0xEF040 (0x3c90)

Overlapping lower-priority intervals dropped: {'graphics': 26}

## Cross-checks

- text end: functions 0x80060014, datamap 0x8006161C; the difference is RSP code linked into .text (0xfdc of 0x1608 bytes): CPU code ends at 0x80060014, the .text section at 0x8006161C

## Next steps

Most bytes (or failures) first.

1. ROM 0x3FC620..0xC00000 (0x8039e0 bytes) is unclassified; 7.1 bits/byte, zlib ratio 0.86: raw media or lightly packed data (audio, textures, animation)
2. ROM 0x2E6E60..0x3F1990 (0x10ab30 bytes) is unclassified; 7.3 bits/byte, zlib ratio 0.92: raw media or lightly packed data (audio, textures, animation)
3. ROM 0x1AA5E0..0x23C550 (0x91f70 bytes) is unclassified; 7.2 bits/byte, zlib ratio 0.91: raw media or lightly packed data (audio, textures, animation)
4. ROM 0xB5110..0xD8CC0 (0x23bb0 bytes) is unclassified; 5.9 bits/byte, zlib ratio 0.57: raw structured data (tables, text, level data)
5. ROM 0x8A5F0..0xA15F0 (0x17000 bytes) is unclassified; 5.9 bits/byte, zlib ratio 0.58: raw structured data (tables, text, level data)
6. ROM 0xDA200..0xDFB40 (0x5940 bytes) is unclassified; 5.9 bits/byte, zlib ratio 0.52: raw structured data (tables, text, level data)
7. review function boundaries flagged in functions.toml: 3 falls_through, 1 branch_outside, 1 cross_branch

## Timings (s)

program_image 0.0, functions 2.41, datamap 1.13, sdk 5.34, audio 0.46, gfx 0.05, assets 7.55, rsp_in_text 0.06
