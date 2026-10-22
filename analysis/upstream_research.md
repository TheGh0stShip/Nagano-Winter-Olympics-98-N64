# Public-source research survey

Fifty distinct research rounds were completed on 2026-10-22. ROM-download
results were excluded. No second matching decompilation or original source
release for this exact title was found.

| # | Target | Result applied or retained |
|---:|---|---|
| 1 | [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) | Near-match source-shape search after flags are fixed. |
| 2 | [asm-differ](https://github.com/simonlindholm/asm-differ) | Interactive instruction comparison. |
| 3 | [mips_to_c](https://github.com/Kelebek1/mips_to_c) | Semantic starting point, never match evidence. |
| 4 | [objdiff](https://github.com/encounter/objdiff) | Objdiff v2 is the report contract. |
| 5 | [splat](https://github.com/ethteck/splat) | ROM segmentation and symbol plumbing. |
| 6 | [ido-static-recomp](https://github.com/decompals/ido-static-recomp) | Pin compiler revisions and verify outputs. |
| 7 | [Rabbitizer](https://github.com/Decompollaborate/rabbitizer) | Shared decoder for structural scans. |
| 8 | [spimdisasm](https://github.com/Decompollaborate/spimdisasm) | GP-relative and overlay-aware disassembly. |
| 9 | [Super Mario 64](https://github.com/n64decomp/sm64) | Version extraction manifests. |
| 10 | [Ocarina of Time](https://github.com/zeldaret/oot) | Separate asset descriptions from extraction. |
| 11 | [Mario Kart 64](https://github.com/n64decomp/mk64) | Distinct music, bank, texture, and raw domains. |
| 12 | [Perfect Dark](https://github.com/n64decomp/perfect_dark) | Independent extraction and ROM verification. |
| 13 | [Banjo-Kazooie](https://github.com/n64decomp/banjo-kazooie) | Overlay and compression-aware progress. |
| 14 | [GoldenEye 007](https://github.com/n64decomp/007) | IDO stages and asset rebuild boundaries. |
| 15 | [Diddy Kong Racing](https://github.com/DavidSM64/Diddy-Kong-Racing) | Separate matching from documentation quality. |
| 16 | [Paper Mario](https://github.com/pmret/papermario) | Game-specific compiler/binutils pinning. |
| 17 | [ZAPD](https://github.com/zeldaret/ZAPD) | Unaccounted-byte warnings for asset parsers. |
| 18 | [Fast64](https://github.com/Fast-64/fast64) | Use after display-list/resource proof. |
| 19 | [sm64tools](https://github.com/queueRAM/sm64tools) | Standard texture and display-list utilities. |
| 20 | [libreultra](https://github.com/n64decomp/libreultra) | SDK source/signature reference. |
| 21 | [crunch64](https://github.com/decompals/crunch64) | Test common codecs without guessing labels. |
| 22 | [SM64 sound tools](https://github.com/n64decomp/sm64/blob/master/tools/assemble_sound.py) | Round-trip bank/sample manifest patterns. |
| 23 | [N64 Sound Tools](https://github.com/derselbst/N64SoundTools) | Found title-specific `NaganoDecoder`. |
| 24 | [n64soundtools](https://github.com/jsdf/n64soundtools) | Independent SGI bank validation. |
| 25 | Exact-title reverse-engineering search | No independent N64 project/source. |
| 26 | `NaganoDecoder` source search | Located exact block grammar. |
| 27 | `EncodeKonamiLZW` search | Found encoder for future round-trip proof. |
| 28 | `NH5E` and title-code search | Metadata only; no format database. |
| 29 | [decomp.me compiler docs](https://github.com/decompme/decomp.me/blob/main/docs/COMPILER.md) | Record compiler, flags, libraries together. |
| 30 | [decomp.me compilers](https://github.com/decompme/compilers) | Pin packaging recipe and revision. |
| 31 | N64 `-Wab,-r4300_mul` survey | Required by the matching IDO flag family. |
| 32 | N64 `-Xcpluscomm` survey | Corroborated across mature projects. |
| 33 | ROM pointer-scanner search | Loader evidence beats generic heuristics. |
| 34 | Display-list scanner search | Recursive validation required for counts. |
| 35 | [Texture64](https://github.com/queueRAM/Texture64) | Viewer after dimensions/palettes are known. |
| 36 | Filesystem-table research | No conventional filesystem header proven. |
| 37 | [ByteMatch activity](https://bytematch.dev/activity) | Exact progress comes from report artifacts. |
| 38 | [BattleTanx](https://github.com/TheGh0stShip/BattleTanx) | Separate code/data, extraction, inventory. |
| 39 | ByteMatch report-source search | Progress categories are byte-based. |
| 40 | ByteMatch inventory search | Keep the local gap-free physical ledger. |
| 41 | N64 decompilation forums | Compile-and-diff remains acceptance gate. |
| 42 | N64 homebrew discussions | Static recompilation is not matching C. |
| 43 | IDO matching blogs | Exhaust compiler/context before permutations. |
| 44 | N64 matching talks | Registers, delay slots, and order matter. |
| 45 | [N64 resources](https://github.com/command-tab/awesome-n64-development) | Routed to maintained specialist tools. |
| 46 | [N64 decomp workbench](https://github.com/akratch/n64-decomp-workbench) | Automate relocation-aware family analysis. |
| 47 | [N64LoaderWV](https://github.com/zeroKilo/N64LoaderWV) | Runtime-loaded code needs dump evidence. |
| 48 | [n64sym](https://github.com/shygoo/n64sym) | SDK signature leads; prefer RDRAM scans. |
| 49 | [Ghidra headless](https://github.com/NationalSecurityAgency/ghidra/blob/master/Ghidra/RuntimeScripts/support/analyzeHeadlessREADME.md) | Deterministic imports over GUI-only state. |
| 50 | [Ghidra RSP](https://github.com/Random06457/Ghidra-RSP) | Separate analysis for identified RSP ranges. |

## Applied findings

Round 23 was immediately testable. `tools/decode_nagano_lzw.py` decodes every
one of the 23 loader-indexed records at ROM `0x3F1990..0x3FC620`; decoded sizes
range from `0x1A0` to `0x391C`. The physical ledger now classifies the full
44,176-byte aligned span as compressed music sequences. These bytes remain zero
in the extraction category.

Rounds 1-8 and 46 support normalized instruction-family transfer followed by
the strict matching gate. That method produced the 12 exact matches in commit
`a3114ac`; it should be automated rather than repeated ad hoc.

Rounds 9-20 and 37-40 confirm the reporting policy: exact code/data, identified
formats, reproducibly extracted assets, and gap-free inventory are different
claims and must not be combined into one percentage.
