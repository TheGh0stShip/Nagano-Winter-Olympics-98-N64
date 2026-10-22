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
the strict matching gate. `tools/find_function_families.py` now performs that
scan reproducibly. Its first run produced five further exact matches in
addition to the 12 earlier matches in commit `a3114ac`.

Rounds 9-20 and 37-40 confirm the reporting policy: exact code/data, identified
formats, reproducibly extracted assets, and gap-free inventory are different
claims and must not be combined into one percentage.

## Extended survey: rounds 51-150

One hundred additional source-specific investigations were completed on
2026-10-22. Each row records a distinct repository, documentation set, search,
or project practice. A retained result is a lead or constraint, not proof that
Nagano contains the same format. Exact-title searches again found no released
source or second matching decompilation.

| # | Target | Result applied or retained |
|---:|---|---|
| 51 | Exact title plus source/decomp searches | No independent source tree or matching project found. |
| 52 | `NH5E` cartridge-code searches | Confirmed metadata only; no useful symbol or file map surfaced. |
| 53 | Exact-title credits and staff searches | Retained KCEO/Konami Osaka lineage for sibling-project selection. |
| 54 | [N64 Sound Tools `NaganoDecoder`](https://github.com/derselbst/N64SoundTools) | Reconfirmed the exact title-specific decoder and block grammar. |
| 55 | [LZKN64](https://github.com/Zoinkity/LZKN64) | Independent encoder/decoder lead for future byte-exact recompression tests. |
| 56 | [Castlevania 64](https://github.com/k64ret/cv64) | Calls the same codec “LZKN64 (a.k.a. Nagano)” and supplies a clean reference decoder. |
| 57 | [Mystical Ninja Starring Goemon](https://github.com/klorfmorf/mnsg) | Same Konami codec plus IDO 5.3, asset tables, and audio-sequence segmentation. |
| 58 | [Hybrid Heaven](https://github.com/southcitycapture/hybridheaven-decomp) | Closest studio/toolchain analogue: IDO 7.1 game code and IDO 5.3 SDK code. |
| 59 | Hybrid Heaven compression round trips | Retained compressed-file re-encoding as the stronger extraction proof. |
| 60 | Hybrid Heaven source-boundary recovery | EOF padding can support file splits, but is not evidence without Nagano-local padding. |
| 61 | Hybrid Heaven `similar.py` | Applied small-immediate/callee tokens, 3-gram prefiltering, and sequence scoring locally. |
| 62 | Hybrid Heaven `propagate.py` | Retained transfer of proven source shapes only through independent byte verification. |
| 63 | Hybrid Heaven `protofix.py` | Prototype consistency is a high-value register-allocation check. |
| 64 | Hybrid Heaven `features.py` | Retained feature-based work prioritization rather than size alone. |
| 65 | Hybrid Heaven `pick.py` | Small, high-similarity functions remain the best low-risk queue. |
| 66 | Hybrid Heaven `ledger.py` | Corroborates keeping physical ranges gap-free and non-overlapping. |
| 67 | Hybrid Heaven `filetable.py` | Loader tables can prove file records; generic carving cannot. |
| 68 | Hybrid Heaven `gen_rodata_splits.py` | Read-only cross-reference evidence can refine rodata boundaries. |
| 69 | Hybrid Heaven `gen_libultra.py` | SDK identification belongs in a separate library/signature workflow. |
| 70 | Hybrid Heaven `check_recompress.py` | Retained decode/re-encode identity as a future compression test gate. |
| 71 | [decompals/ido-static-recomp](https://github.com/decompals/ido-static-recomp) | Reconfirmed separate IDO 5.3 and 7.1 executables and deterministic host execution. |
| 72 | [decompals/ido-matching-decomp-guide](https://github.com/decompals/ido-matching-decomp-guide) | Statement order, casts, and signedness are first-class match variables. |
| 73 | [decomp.me compilers](https://github.com/decompme/compilers) | Compiler identity must include version, executable, and flags. |
| 74 | [decomp.me](https://github.com/decompme/decomp.me) | Scratch isolation is useful, but repository verification owns match status. |
| 75 | [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) | Useful only after types, context, compiler, and flags are constrained. |
| 76 | [asm-differ](https://github.com/simonlindholm/asm-differ) | Branch/register diff display remains the fastest manual feedback loop. |
| 77 | [mips_to_c](https://github.com/Decompollaborate/mips_to_c) | Retained as draft semantics, never as byte-match evidence. |
| 78 | [m2c](https://github.com/matt-kempster/m2c) | Historical MIPS structuring reference; current project tooling remains preferred. |
| 79 | [Rabbitizer](https://github.com/Decompollaborate/rabbitizer) | Instruction decoding can replace handwritten opcode tables if dependency cost is justified. |
| 80 | [spimdisasm](https://github.com/Decompollaborate/spimdisasm) | GP analysis and symbol propagation remain relevant for data reconstruction. |
| 81 | [splat](https://github.com/ethteck/splat) | Segment configuration is evidence plumbing, not an asset-count oracle. |
| 82 | [objdiff](https://github.com/encounter/objdiff) | Its report model reinforces units, sections, and exact byte measurements. |
| 83 | [decomp-toolkit](https://github.com/encounter/decomp-toolkit) | Non-N64 architecture, but useful deterministic object/report practices. |
| 84 | [n64-decomp-workbench](https://github.com/akratch/n64-decomp-workbench) | Retained reproducible split/analyze/diff task orchestration. |
| 85 | [n64split](https://github.com/queueRAM/n64split) | Older splitter is useful for comparison, not a reason to replace proven boundaries. |
| 86 | [n64sym](https://github.com/shygoo/n64sym) | Runtime signature scans may identify SDK routines when static evidence is ambiguous. |
| 87 | [N64LoaderWV](https://github.com/zeroKilo/N64LoaderWV) | Runtime RAM captures remain a path for dynamically loaded ranges. |
| 88 | [Ghidra](https://github.com/NationalSecurityAgency/ghidra) | Headless scripts should preserve deterministic, reviewable analysis. |
| 89 | [Ghidra N64 Loader](https://github.com/zeroKilo/N64LoaderWV) | Loader metadata can accelerate inspection but does not establish source boundaries. |
| 90 | [Ghidra RSP](https://github.com/Random06457/Ghidra-RSP) | Use only after an RSP microcode range is identified. |
| 91 | [Super Mario 64](https://github.com/n64decomp/sm64) | Region/version manifests and generated-asset exclusion remain baseline practice. |
| 92 | [Ocarina of Time](https://github.com/zeldaret/oot) | XML asset descriptions demonstrate reproducible extraction without committing outputs. |
| 93 | [Majora's Mask](https://github.com/zeldaret/mm) | Version-specific configuration prevents progress leakage across ROM revisions. |
| 94 | [Mario Kart 64](https://github.com/n64decomp/mk64) | Audio banks, sequences, textures, and miscellaneous data need separate domains. |
| 95 | [Perfect Dark](https://github.com/n64decomp/perfect_dark) | Matching and nonmatching build modes must never share progress claims. |
| 96 | [GoldenEye 007](https://github.com/n64decomp/007) | Map-derived progress and asset extraction remain separate build products. |
| 97 | [Banjo-Kazooie](https://gitlab.com/banjo.decomp/banjo-kazooie) | Overlay/compression accounting is relevant; Rare-specific codecs are not presumed. |
| 98 | [Banjo-Tooie](https://gitlab.com/banjo.decomp/banjo-tooie) | Overlay tables illustrate why loaded bytes and ROM bytes need distinct coordinates. |
| 99 | [Diddy Kong Racing](https://github.com/DavidSM64/Diddy-Kong-Racing) | Per-version progress reinforces exact-ROM scoping. |
| 100 | [Paper Mario](https://github.com/pmret/papermario) | Toolchain pinning and generated symbol headers are transferable practices. |
| 101 | [Pokémon Snap](https://github.com/ethteck/pokemonsnap) | Asset extraction recipes are separate from matching source. |
| 102 | [Pokémon Stadium](https://github.com/pret/pokestadium) | Large data tables benefit from explicit symbol/type provenance. |
| 103 | [Pokémon Stadium 2](https://github.com/pret/pokestadium) | Multi-version investigation yielded no Nagano-specific overlap. |
| 104 | [Kirby 64](https://github.com/HarbourMasters/katam) | Overlay organization is a useful comparison, not proof of Nagano overlays. |
| 105 | [Star Fox 64](https://github.com/sonicdcer/sf64) | Audio and object assets should retain independent reconstruction checks. |
| 106 | [F-Zero X](https://github.com/inspectredc/fzerox) | Course/model tooling is format-specific; no direct reuse justified yet. |
| 107 | [Wave Race 64](https://github.com/llonsit-games/wave-race-64) | Sports-era Nintendo project inspected; no shared engine evidence found. |
| 108 | [Pilotwings 64](https://github.com/llonsit-games/pilotwings64) | Useful project layout comparison; no title-specific code match identified. |
| 109 | [1080 Snowboarding](https://github.com/angheloalf/1080decomp) | Genre proximity does not establish engine or format compatibility. |
| 110 | [Snowboard Kids](https://github.com/sonicdcer/sbk-decomp) | Recent complete-project methods inspected; no common engine evidence retained. |
| 111 | [Harvest Moon 64](https://github.com/harvestwhisperer/hm64-decomp) | Decoded record counts remain separate from physical extracted bytes. |
| 112 | [Quest 64](https://github.com/Blackgamma7/quest64) | Repository structure reviewed; no direct function or format matches found. |
| 113 | [Jet Force Gemini](https://gitlab.com/banjo.decomp/jet-force-gemini) | Rare engine evidence rejected as unrelated to Konami lineage. |
| 114 | [Donkey Kong 64](https://gitlab.com/banjo.decomp/donkey-kong-64) | Large asset pipelines support provenance-rich manifests, not heuristic totals. |
| 115 | [Conker](https://github.com/mkst/conker) | ROM-decomp guide corroborates compile-and-compare workflow. |
| 116 | [Doom 64](https://github.com/Erick194/DOOM64-RE) | Reconstruction-oriented project; progress semantics are not directly transferable. |
| 117 | [libreultra](https://github.com/n64decomp/libreultra) | SDK implementations and signatures are reference evidence, not automatic game matches. |
| 118 | [ultralib](https://github.com/decompals/ultralib) | Versioned libultra objects may sharpen the IDO 5.3 library partition. |
| 119 | [libdragon](https://github.com/DragonMinded/libdragon) | Hardware/API documentation is useful, but modern implementations cannot prove original code. |
| 120 | [N64brew documentation](https://n64brew.dev/wiki/Main_Page) | Retained RCP, ROM header, and display-list references for interpretation. |
| 121 | [N64 Programming Manual](https://ultra64.ca/files/documentation/online-manuals/man-v5-1/) | Primary ABI and SDK behavior reference. |
| 122 | [VR4300 manual collection](https://n64brew.dev/wiki/VR4300) | Primary CPU behavior governs delay slots, exceptions, and alignment. |
| 123 | [ZAPD](https://github.com/zeldaret/ZAPD) | Parser coverage must report unconsumed bytes and nested references. |
| 124 | [Fast64](https://github.com/Fast-64/fast64) | Useful only after display-list and texture metadata are proven. |
| 125 | [Texture64](https://github.com/queueRAM/Texture64) | Viewer/exporter retained for confirmed N64 texture records. |
| 126 | [sm64tools](https://github.com/queueRAM/sm64tools) | Texture/display-list utilities are validation aids, not scanners of record. |
| 127 | [crunch64](https://github.com/decompals/crunch64) | Common Nintendo codecs screened; codec names must not be guessed from output. |
| 128 | [N64-Tools](https://github.com/jombo23/N64-Tools) | Audio/MIDI extractors may help characterize sequences after format proof. |
| 129 | [Seq64](https://github.com/sauraen/seq64) | Sequence visualization is applicable only after dialect identification. |
| 130 | [n64soundtools](https://github.com/jsdf/n64soundtools) | SGI bank detection/decompilation retained for bank/table investigation. |
| 131 | SM64 sound extraction pipeline | Demonstrates manifest-driven samples, banks, and sequences with rebuild checks. |
| 132 | MK64 sound extraction pipeline | Reinforces separate sequence, bank, table, and sample counts. |
| 133 | Zelda audio extraction pipelines | Bank/table structures can contain shared and aliased records; naive counts overstate assets. |
| 134 | Konami N64 audio searches | No proven Nagano bank/sample map found beyond the 23 compressed sequences. |
| 135 | Konami LZ variant searches | “LZKN64/Nagano” is supported; unrelated Konami codecs remain rejected. |
| 136 | MAME Nagano arcade-driver searches | Arcade sibling metadata did not yield N64 source or reusable formats. |
| 137 | International Track & Field 2000 searches | Successor/title lineage found, but no shared-source evidence. |
| 138 | Hyper Olympic in Nagano searches | Platform-family results did not expose usable source or format documentation. |
| 139 | Project64 game-database history | Emulator settings are behavior clues, not code or inventory evidence. |
| 140 | Mupen64Plus compatibility databases | Compatibility notes yielded no source-boundary or asset proof. |
| 141 | [ares](https://github.com/ares-emulator/ares) | Emulator implementation can validate hardware behavior, not original implementation. |
| 142 | [mupen64plus-core](https://github.com/mupen64plus/mupen64plus-core) | Runtime tracing remains a possible loader-reference validation path. |
| 143 | [simple64](https://github.com/simple64/simple64) | Debug/runtime behavior may corroborate execution paths, not matching status. |
| 144 | [cen64](https://github.com/n64dev/cen64) | Cycle-oriented emulation is useful for hardware edge cases only. |
| 145 | [Hack64](https://hack64.net/wiki/doku.php?id=start) | Format documentation retained as hypotheses requiring ROM-local validation. |
| 146 | [awesome-n64-development](https://github.com/command-tab/awesome-n64-development) | Surveyed maintained specialist tools and rejected unrelated homebrew pipelines. |
| 147 | Reverse Engineering Stack Exchange searches | General compiler-pattern advice added no title-specific evidence. |
| 148 | N64brew community/forum searches | No additional Nagano-specific symbols, maps, or archives found. |
| 149 | ROM-hacking forum and social searches | Exact-title results were gameplay/compatibility discussions, not technical artifacts. |
| 150 | GitHub global code/repository searches | No second Nagano source base; Konami sibling projects remain the strongest upstream family. |

### Applied findings from rounds 51-150

Rounds 56-60 independently strengthen the compression identification: three
Konami-family implementations use the same Nagano/LZKN64 lineage. They do not
change extraction progress by themselves; a future encoder must reproduce each
compressed byte stream before round-trip status is claimed.

Round 61 produced an immediate tooling improvement. The family finder now has
a `--similar` mode (also `make similar`) that retains opcode shape, small
constants, and resolved direct callees. It narrows candidates with 3-gram
Jaccard similarity and ranks them with full token-sequence similarity. Results
are work leads only; the matching manifests still require `make
verify-matching` for every admitted unit.

Rounds 66, 82, 91-119, and 123-133 reinforce the existing report contract:
physical coverage, decoded records, extracted bytes, and byte-matched sections
are independently measurable facts. None may be inferred from another.

Rounds 151-300 and their synthesis are recorded in
[`upstream_research_151_300.md`](upstream_research_151_300.md).
