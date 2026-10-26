# Extended upstream research: rounds 151-300

These 150 additional investigations were completed on 2026-10-22. Each round
tests a distinct upstream artifact, method, or Nagano-local hypothesis. A
negative result is retained to prevent repeated searching. References are
research leads only; no external result is counted as a local match or decoded
asset without repository verification.

| # | Investigation | Result retained or applied |
|---:|---|---|
| 151 | Hybrid Heaven token similarity | Directly applied to `find_function_families.py`. |
| 152 | Small-immediate retention | Struct offsets and small constants distinguish near-copy families. |
| 153 | Direct-callee tokenization | Resolved local callees improve family specificity. |
| 154 | Three-instruction shingles | Jaccard filtering cheaply narrows sequence comparisons. |
| 155 | Full sequence comparison | Order-sensitive scoring ranks the filtered candidates. |
| 156 | Candidate length bounds | A 0.4-2.5 ratio rejects implausible examples. |
| 157 | Exact-twin regression | Existing relaxed fingerprints remain available independently. |
| 158 | Similarity acceptance semantics | Similarity produces leads only; manifests remain exact-match gated. |
| 159 | Similarity smoke test | Found a 100% lead at `0x80048608`. |
| 160 | Similarity smoke test | Found a 96% collector lead at `0x80005D74`. |
| 161 | Similarity smoke test | Found a 94% wrapper lead at `0x8000B99C`. |
| 162 | Similarity smoke test | Found 93% record-application leads at `0x80009414`. |
| 163 | Similarity smoke test | Found 93% arithmetic-helper leads at `0x8004EF88`. |
| 164 | Similarity smoke test | Found 92% initializer lead at `0x8000A424`. |
| 165 | Similarity smoke test | Found 90% control-pair leads at `0x80003818`. |
| 166 | Similarity smoke test | Found byte-pair wrapper leads at `0x80048580` and `0x800485AC`. |
| 167 | [IDO workbench field guide](https://github.com/akratch/n64-decomp-workbench/blob/main/docs/field-guide.md) | Use measured codegen levers only under their proven compiler revision. |
| 168 | Workbench commutative-order study | Compound assignment can preserve a different frontend tree. |
| 169 | Workbench temporary-register study | Temp allocation sequence can explain whole register rotations. |
| 170 | Workbench colorability gate | Separate allocator colors from backend scratch registers. |
| 171 | Workbench line-number experiments | Source layout can affect IDO output and must be preserved when relevant. |
| 172 | Workbench switch experiments | Dispatch residuals may originate in assembler/backend transformations. |
| 173 | Workbench pass capture | Phase-boundary experiments can reject impossible source hypotheses. |
| 174 | Workbench frontend identification | Similar flags do not prove the same frontend executable. |
| 175 | Workbench register profiles | Never transfer a measured 5.3 allocation law to 7.1 without proof. |
| 176 | Workbench diagnostic taxonomy | Classify opcode, schedule, register, stack, and relocation differences separately. |
| 177 | IDO `ugen` conservative mode | IDO 5.3 host recompilation has a documented uninitialized-state compatibility mode. |
| 178 | IDO compiler phase inventory | `cfe`, `uopt`, `ugen`, and `as1` can be isolated for diagnosis. |
| 179 | IDO 5.3/7.1 executable split | Keep compiler revision a per-unit fact. |
| 180 | IDO assembler variation | Matching compilation must pin assembler as well as frontend. |
| 181 | `-mips2` survey | Consistent with VR4300-era optimized game code. |
| 182 | `-G 0` survey | GP small-data policy materially affects addressing and layout. |
| 183 | `-non_shared` survey | Calling/address sequences depend on the non-PIC build model. |
| 184 | `-Xcpluscomm` survey | Comment-dialect flag is common in contemporary N64 builds. |
| 185 | `-Wab,-r4300_mul` survey | Assembler scheduling/multiply behavior belongs in the toolchain identity. |
| 186 | KMC GCC family survey | Keep KMC units isolated from both IDO families. |
| 187 | KMC assembler-boundary survey | Assembly wrappers require distinct verification from compiler-generated C. |
| 188 | Function-prototype effects | Argument promotion and return types can alter calling and register code. |
| 189 | Signedness effects | Compare, shifts, and extension instructions expose type errors. |
| 190 | Volatile effects | Only use volatile where access ordering evidence supports it. |
| 191 | `register` keyword surveys | IDO may react to declaration hints; test rather than cargo-cult. |
| 192 | C89 declaration order | Scope and declaration order can alter allocation. |
| 193 | Loop-shape surveys | `for`, `while`, and `do` forms can change branch layout. |
| 194 | Short-circuit surveys | Boolean source structure controls branch topology. |
| 195 | Switch-density surveys | Jump-table generation depends on density and compiler revision. |
| 196 | Struct-offset inference | Repeated constant offsets are evidence for layouts, not field meaning. |
| 197 | Array-stride inference | Multiply/add sequences can prove record width. |
| 198 | Stack-frame comparison | Frame size is a fast source-shape diagnostic. |
| 199 | Delay-slot comparison | Delay-slot contents often reveal scheduling or expression-order differences. |
| 200 | Relocation-aware comparison | Symbolic equivalence must precede raw immediate comparison. |
| 201 | [ultralib](https://github.com/decompals/ultralib) version matrix | Use object/version identity to narrow library candidates. |
| 202 | libultra OS queue functions | Signature candidates still require exact local bytes. |
| 203 | libultra thread functions | SDK naming can improve calls without inflating matched game code. |
| 204 | libultra PI functions | DMA APIs are useful loader-boundary evidence. |
| 205 | libultra SP functions | Task submission calls may identify graphics/audio boundaries. |
| 206 | libultra VI functions | Video setup signatures can distinguish library from game code. |
| 207 | libultra controller functions | Input APIs help interpret event and polling code. |
| 208 | libultra timer functions | Timer/message patterns can identify SDK routines. |
| 209 | libultra cache functions | Cache maintenance often brackets DMA destinations. |
| 210 | libultra exception code | Boot/exception regions should not be assigned game compiler flags. |
| 211 | libultra revision-specific objects | Similar SDK functions can differ across releases. |
| 212 | [libreultra](https://github.com/n64decomp/libreultra) API headers | Retain canonical types and constants where version-compatible. |
| 213 | PR/ultratypes widths | Use explicit target widths at every binary boundary. |
| 214 | OSTask layout | Task structures can validate RSP submission records. |
| 215 | OSMesgQueue layout | Queue field offsets may anchor inferred structs. |
| 216 | OSContPad layout | Controller record sizes can validate input loops. |
| 217 | DMA direction semantics | Loader analysis must distinguish ROM-to-RAM from writeback paths. |
| 218 | Segment-address conventions | Segmented display-list pointers are not ordinary VRAM pointers. |
| 219 | KSEG address rules | Normalize virtual/physical addresses only where the API does. |
| 220 | RSP microcode signatures | No microcode inventory claim until ranges are identified. |
| 221 | [splat segment types](https://github.com/ethteck/splat) | Segment type names are configuration claims, not proof. |
| 222 | Splat code subsegments | Function boundaries should agree with branches, symbols, and relocations. |
| 223 | Splat rodata migration | Rodata association is useful but must preserve physical ledger coverage. |
| 224 | Splat linker generation | Generated scripts should remain reproducible and reviewable. |
| 225 | Splat cache behavior | Cache invalidation must not hide changed extraction inputs. |
| 226 | Splat N64 header handling | ROM header bytes remain separately inventoried. |
| 227 | Splat palette/texture types | Dimensions and palette relationships must be known first. |
| 228 | Splat binary segments | Raw extraction is not decoded-asset progress. |
| 229 | Splat compression hooks | A decoder hook needs consumed-length and bounds checks. |
| 230 | Splat symbol addresses | Committed symbols should preserve evidence and stable names. |
| 231 | [spimdisasm context](https://github.com/Decompollaborate/spimdisasm) | Persistent context improves pointer and symbol recovery. |
| 232 | spimdisasm GP tracking | GP-relative references can reveal small-data objects. |
| 233 | spimdisasm pointer nuking controls | Avoid heuristics that erase legitimate constants. |
| 234 | spimdisasm function detection | Treat detected boundaries as candidates pending control-flow review. |
| 235 | spimdisasm relocation output | Relocations improve semantic comparisons across addresses. |
| 236 | Rabbitizer instruction categories | Centralized decode can reduce local opcode-class errors. |
| 237 | Rabbitizer branch metadata | Branch target handling can strengthen boundary validation. |
| 238 | Rabbitizer register naming | ABI names improve diagnostic output only, not proof. |
| 239 | Rabbitizer COP1 decode | Floating-point families need accurate condition/format tokens. |
| 240 | Rabbitizer invalid-opcode handling | Invalid words can flag mistaken code classification. |
| 241 | [objdiff config schema](https://github.com/encounter/objdiff) | Units should explicitly declare target/base objects and metadata. |
| 242 | Objdiff section progress | Code and data section bytes must remain separate. |
| 243 | Objdiff symbol mapping | Symbol maps should not turn equivalent code into reported equality. |
| 244 | Objdiff relocation display | Relocation differences deserve independent diagnosis. |
| 245 | Objdiff unit categories | Compiler families can map cleanly to separate report units. |
| 246 | Objdiff scratch workflows | Local experiments must not mutate canonical progress artifacts. |
| 247 | Objdiff JSON reporting | Machine-readable output is suitable for CI truth checks. |
| 248 | Objdiff stale-object handling | Builds must regenerate candidates before progress computation. |
| 249 | Objdiff data matching | Data credit requires actual section equality. |
| 250 | Objdiff CI usage | CI should fail if declared matched bytes drift. |
| 251 | [ZAPD declarations](https://github.com/zeldaret/ZAPD) | Declarative asset descriptions aid review and regeneration. |
| 252 | ZAPD unaccounted ranges | Parser output should expose rather than absorb unknown tails. |
| 253 | ZAPD nested resources | Parent bytes and decoded child counts are different measurements. |
| 254 | ZAPD pointer validation | Referenced offsets need range and alignment checks. |
| 255 | ZAPD texture metadata | Format, width, height, and palette are all required. |
| 256 | ZAPD display-list parsing | Recursive commands need loop and bounds protection. |
| 257 | ZAPD blob fallback | Unknown bytes remain explicit binary regions. |
| 258 | ZAPD XML versioning | Description changes should be reviewable independently of extracted files. |
| 259 | ZAPD extraction determinism | Repeated extraction should produce identical manifests. |
| 260 | ZAPD generated-source policy | Generated asset source should not masquerade as hand-decompiled data. |
| 261 | [n64soundtools](https://github.com/jsdf/n64soundtools) bank detection | Scan candidates require ctl/tbl structural validation. |
| 262 | n64soundtools sample export | Exported sample counts are decoded records, not physical coverage. |
| 263 | n64soundtools sequence compiler | Round-trip compilation is stronger than successful playback. |
| 264 | N64 Sound Tools codec registry | Exact decoder selection is preferable to generic codec guessing. |
| 265 | NaganoDecoder bitstream controls | Backreferences and literal runs must be bounds checked. |
| 266 | NaganoDecoder termination | Decoded length is part of record validation. |
| 267 | Nagano compressed alignment | Physical padding stays in the compressed container range. |
| 268 | LZKN64 independent implementation | Cross-decoder equality can expose local decoder mistakes. |
| 269 | LZKN64 encoder availability | Enables future decode/re-encode testing. |
| 270 | LZKN64 naming provenance | “Nagano” and “LZKN64” refer to the same observed family upstream. |
| 271 | MN64 sequence-table layout | Useful sibling evidence, not transferable offsets. |
| 272 | MN64 asset table layout | Compare loader behavior before adapting any parser. |
| 273 | CV64 compression headers | Header similarities need byte-level Nagano comparison. |
| 274 | Hybrid Heaven compressed files | Multiple records strengthen family provenance, not local counts. |
| 275 | Codec malformed-input tests | Add only synthetic cases; never commit ROM-derived fixtures. |
| 276 | Codec consumed-byte reporting | A decoder should expose exact source consumption. |
| 277 | Codec output-size limits | Refuse impossible sizes before allocation. |
| 278 | Codec overlap-copy semantics | Backreference copying must support overlapping windows. |
| 279 | Codec truncated-stream behavior | Truncation must fail loudly rather than pad output. |
| 280 | Codec trailing-byte behavior | Container padding should be distinguished from encoded payload. |
| 281 | BattleTanx report schema | Keep exact code/data, extraction, and inventory coverage distinct. |
| 282 | BattleTanx report generation | Generate tracked results from one canonical inventory. |
| 283 | BattleTanx CI report check | Fail on stale generated reports. |
| 284 | BattleTanx ROM verification | Hash the required input before any analysis. |
| 285 | BattleTanx matched manifests | A manifest entry is a promise enforced by compilation. |
| 286 | BattleTanx unknown ranges | Unknown is a valid, necessary inventory classification. |
| 287 | BattleTanx asset categories | Identified and extracted are independent states. |
| 288 | BattleTanx byte totals | Totals should derive from non-overlapping physical ranges. |
| 289 | BattleTanx function totals | Function count and byte count answer different questions. |
| 290 | BattleTanx repository hygiene | ROMs, toolchain binaries, and generated assembly stay untracked. |
| 291 | GitHub Actions clean build | Verify from declared dependencies and a user-supplied ROM context. |
| 292 | GitHub Actions test isolation | Synthetic unit tests should not require copyrighted fixtures. |
| 293 | Git ignore audit | Generated extraction and local compiler paths need explicit exclusions. |
| 294 | License/header survey | Do not copy upstream implementation text without compatible provenance. |
| 295 | Dependency pinning survey | Moving tool versions can invalidate matching results. |
| 296 | Host-endianness audit | Readers must use explicit big-endian decoding. |
| 297 | Host-pointer audit | Host pointers cannot model 32-bit target pointer fields. |
| 298 | Integer-width audit | `long` differs across host ABIs; fixed widths protect binary layouts. |
| 299 | Alignment audit | Host struct layout cannot establish VR4300 layouts. |
| 300 | Research synthesis | Best immediate returns are near-family transfer, exact verification, and codec round trips. |

## Analysis

The similarity method generated multiple high-confidence local leads on its
first run, including one identical token stream. This is the strongest quick
win from rounds 151-300 because it converts already verified Nagano source into
ranked, game-local examples without weakening the match gate.

The compiler research supplies a second, narrower lesson: diagnose the layer
that owns a mismatch before permuting C. Frontend tree shape, optimizer
allocation, backend temporary order, assembler scheduling, and relocation are
different failure classes. A technique measured on IDO 5.3 is not assumed to
apply to 7.1 or KMC.

The asset research does not justify a larger progress number today. It instead
defines the next proofs: cross-decode every known sequence, measure source
consumption, implement bounded malformed-input tests, and eventually require
byte-identical re-encoding before calling compressed records round-tripped.

The reporting survey continues to support the current ByteMatch contract.
Exact code bytes, exact data bytes, physically classified ROM bytes, decoded
record counts, and reproducibly extracted bytes remain separate quantities.

## 2026-10-25 quick upstream follow-up

The completed Rugrats: Scavenger Hunt project supplied one immediate workflow
improvement: a range-aware, size-ranked unmatched queue covering every compiler
manifest. Nagano now exposes the adapted queue as `make unmatched`, eliminating
duplicate candidate work across KMC, IDO 5.3, and IDO 7.1 manifests.

Recent upstream checks also found three techniques worth retaining for later
campaigns: gameDecomp's whole-program object-exact state map, BeetleDecomp's
per-module quick verification and candidate scoring, and 1080 Snowboarding's
separate exact/fuzzy accounting. Only the queue was adopted today. Fuzzy
similarity remains research evidence and cannot increase Nagano's public
matching totals.
