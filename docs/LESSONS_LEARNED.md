# Nagano Winter Olympics '98 decompilation: lessons learned

This document preserves the methods that brought the USA retail build to a
fully byte-matched program decompilation. It is written for human contributors
and automated coding agents working on IDO-era Nintendo 64 software.

## Completion definition and current evidence

The project uses the USA retail ROM with SHA-1
`eaf543e195731031a84f4136b506449209e3a8f5`. A source unit counts only when
`make verify-matching` recompiles it and proves that its relocated bytes equal
the retail ROM.

At commit `8be4efb`:

- 1,470 / 1,470 functions are covered by verified units.
- 391,940 / 391,940 function-body bytes are byte-exact.
- 129,824 / 129,824 initialized program-data bytes are byte-exact.
- The unmatched-function queue is empty.
- All non-code physical ROM bytes are classified and reconstructed exactly.
- Handwritten assembly is used only where provenance establishes handwritten
  assembly; compiler-generated code is represented by matching C.

The linked CPU text section also contains 232 bytes of alignment/linker
padding. Padding is not C function code, so it is covered by the physical ROM
inventory rather than inflating the code denominator.

“100% matching decompilation” does not mean every asset field has a semantic
name. The nested decoded-container map is presently 13,997,274 / 14,762,912
bytes (94.81%) structurally classified. The remaining 765,638 decoded bytes
round-trip through their original containers exactly but retain unknown
in-file semantics. Keep this distinction in reports and public announcements.

## The verification hierarchy

Use progressively stronger evidence:

1. A mnemonic resemblance or equivalent C implementation is a lead only.
2. A matcher score is a diagnostic, not proof.
3. A standalone exact match proves the selected range and compiler settings.
4. A manifest entry plus `make verify-matching` proves reproducibility in the
   project.
5. `make check`, `make audit`, `make report`, an empty
   `make unmatched` queue, and `git diff --check` are the integration gates.
6. A clean CI report for the pushed commit proves the published tracker
   artifact was produced from that state.

Always compare raw bytes. GNU objdump omits zero words unless `-z` is used;
this once produced a false hazard-NOP diagnosis in the final function.

## Compiler identification and translation units

The program uses several pipelines:

- IDO 5.3 and IDO 7.1 for most C.
- KMC GCC 2.7.2 plus the assembler for a smaller cohort.
- Handwritten assembly for provenance-backed entry, exception, cache, TLB,
  interrupt, and related low-level routines.

Do not assume one optimization level or compiler for the whole image.
Libultra and libaudio objects may use `-O1`, `-O2`, or `-O3`.

Translation-unit layout matters. Functions at object ends can include
alignment that does not belong to the function body. Several matches required
compiling neighboring functions together. For `func_8000D218`, the old
`0x718` catalogue size included eight zero bytes padding its original
translation unit to the next 16-byte boundary; its actual body is `0x710`.

When a candidate differs only at its tail:

1. inspect the next symbol and raw ROM words;
2. identify the likely original object boundary;
3. test a multi-function unit;
4. classify genuine padding separately instead of transcribing it as code.

## IDO source-layout effects

IDO scheduling can depend on source-line and statement shape. Proven levers
include:

- putting related display-list writes on one line;
- block-scoped macro temporaries;
- joining a loop header and its first statement;
- compound assignment to control commutative operand order;
- changing return type or retaining an otherwise unused call result;
- an unused leading `long long` local to reproduce a larger stack frame;
- direct global indexing instead of cached pointers, or the reverse;
- repeating an expression rather than storing it in a local;
- declaration and store ordering;
- tentative definitions for some 64-bit globals;
- using exact signedness at loads, stores, divisions, and binary boundaries.

These forms are not interchangeable under IDO. Preserve a strange-looking
expression when the matcher proves it is load-bearing, and document why.

## UOPT register allocation

Fred Chow’s optimizer work describes the allocator used by IDO. The readable
implementation in `n64decomp/ido`, especially `src/uopt/uoptreg2.c`, made
the following rules concrete.

### Priority

For each live unit, UOPT estimates saved loads and stores, weighted by loop
frequency, and subtracts reload/save costs. It sums this as `totalsave`.
The live-block divisor is bucketed:

```text
if n > 2:
    n = ((n - 2) >> 2) + 2
adjsave = totalsave / n
```

Thus 3–5 blocks divide by 2, 6–9 by 3, and so on. Adding a basic block may not
change priority until it crosses a bucket boundary.

### Coloring

- Constrained live ranges are colored from highest `adjsave` to lowest.
- Ties go to the live range created first.
- Unconstrained ranges are colored later in creation order.
- Equal-cost registers resolve to the first register scanned.
- Outgoing arguments and incoming parameters create preferences for
  `a0`–`a3`; calls penalize caller-saved registers across the call.

This explains why harmless first appearances, dead definitions, and argument
shapes can change the final allocation without emitting code.

### Splitting

A split piece normally begins where a value is defined and grows forward
through successors. It cannot grow backward into a predecessor. This was
decisive in understanding why the final background-rendering function’s
spilled Y expression could not be repaired by merely extending a later range.

### PRE ordering

Partially redundant computations inserted at the same block entry are emitted
in expression-bit order, which follows first source appearance. Carefully
placed optimizer-folded expressions can therefore alter insertion order
without surviving in generated code. Verify every such use; many apparently
similar expressions are hoisted into the wrong block.

## UGEN and assembler behavior

The decompiled UGEN register manager in `LLONSIT/ido-decomp` confirms a FIFO
temporary-register queue. Available temporaries begin with `t6`–`t9`, then
`t0`–`t5`; a register rejoins the queue tail after its final tree use.
Expression use count and evaluation order therefore control the entire
temporary ring.

The assembler performs global copy propagation and scheduling after UGEN.
For display-list macros, UGEN may emit:

```asm
lw    v0, 0(pointer)
move  a3, v0
```

Assembler liveness decides whether the copy is propagated forward, keeping
`v0`, or backward, changing the load destination to `a3`. Diagnose UOPT,
UGEN, and assembler behavior separately instead of attributing every register
difference to the C optimizer.

## The final function: `func_8000D218`

This 1,808-byte background-tile renderer was the final unmatched function.
The successful IDO 7.1 source depended on several interacting mechanisms:

- an initial dead definition fixed creation-order ties;
- exact `(int)(char *)(value << 5)` expression identities created the needed
  PRE pieces;
- the X copy was inserted between display-list mask computations and the Y
  reload;
- the texture-width and map-width quotient/remainder calculations were split
  in-place;
- the Y quotient was killed through its dividend, allowing the height load to
  occur late enough for assembler copy propagation;
- carefully weighted optimizer-folded expressions fixed live-range priority
  and UGEN’s temporary ring;
- direct byte indexing fixed the final address-add operand order.

The apparent last mismatch was not code: two zero words at offsets
`0x710` and `0x714` were translation-unit padding. Correcting the catalogue
to the `0x710` body produced a direct exact match.

The final source is [`src/game/func_8000d218.c`](../src/game/func_8000d218.c).
Its manifest compiler is IDO 7.1 with:

```text
-Iinclude/ultra -O2 -mips2 -non_shared -Xcpluscomm -Wab,-r4300_mul -G 0
```

## Instrumented-compiler method

When source permutation stalls:

1. Build a private, diagnostic copy of the decompiled optimizer.
2. Verify that it emits identical output with all diagnostic knobs disabled.
3. Instrument live-range creation, `adjsave`, interference, splitting, PRE,
   coloring, and UGEN allocation.
4. Temporarily force a register, priority, split, or insertion to learn which
   compiler decision would produce the target.
5. Translate that decision into a source-level constraint.
6. Return to the stock compiler and accept only its byte-exact output.

Never use the instrumented compiler, post-processing, byte patches, inline
assembly, or normalizers to claim a match.

## Efficient batch workflow

- Freeze a cohort before work begins.
- Attack functions in batches, but give hard near-misses dedicated ledgers.
- Record compiler, flags, section pins, candidate path, score, and exact
  residual for every useful experiment.
- Search completed projects for SDK object order, prototypes, compiler
  versions, and handwritten-assembly provenance.
- Reverify every contributed candidate independently before integration.
- Merge independently successful fixes; several major matches came from
  combining two helpers’ orthogonal changes.
- Treat negative experiments as reusable results. Publishing them prevents
  expensive repetition.
- Keep scratch candidates outside tracked source. Only verified units enter
  manifests and progress totals.

## Asset and data lessons

Physical, reconstructed, extracted, and semantically decoded coverage answer
different questions:

- physical inventory: every ROM byte has an owner;
- reconstruction: structured serializers or canonical payloads reproduce the
  original bytes;
- extraction: redistributable files are actually committed;
- nested semantics: decoded container contents have proven record types.

Nagano uses a 538-entry asset table, 524 Konami-LZ containers, four libaudio
banks, 327 VADPCM samples, 23 music sequences, 13 overlays, and extensive
F3DEX content. The exact LZ encoder, audio serializers, overlay data units,
music grammar, and record streams all require round-trip tests.

Do not label unreferenced zero bytes as padding without evidence. Do not turn a
size-divisible blob into records without autocorrelation, reference, parser,
and exact repack evidence. The file-53 `s16[10]` classification, for example,
uses an eight-byte typed header, a unique 20-byte stride signal, and exact
parse/repack verification.

## Coordination lessons

Shared claims, heartbeats, findings, experiment records, and durable messages
prevent duplicated work. A useful coordination record contains:

- function address and owner;
- current best source, compiler, flags, and score;
- exact residual categories and offsets;
- experiment family already exhausted;
- a concise mechanism finding when behavior is understood;
- integration SHA after independent verification.

Advisory model consultations are hypotheses only. They have no filesystem,
build, matching, integration, or publication authority; every suggestion must
be tested with the stock toolchain.

## Primary references

- [Upstream research rounds](../analysis/upstream_research.md)
- [Additional upstream research](../analysis/upstream_research_151_300.md)
- [Full-ROM audit](../analysis/full_rom_audit.md)
- [Data-map methodology](../analysis/data_map/README.md)
- [Fred Chow, Portable Machine-Independent Global Optimizer](https://bitsavers.org/pdf/llnl/s1/Chow_-_A_Portable_Machine-Independent_Global_Optimizer_1984.pdf)
- [n64decomp/ido](https://github.com/n64decomp/ido)
- [LLONSIT/ido-decomp](https://github.com/LLONSIT/ido-decomp)
- [Ocarina of Time IDO -O2 guide](https://github.com/n64decomp/oot/blob/master/docs/guides/-O2%20decompilation%20(for%20IDO%205.3).md)
- [decomp-permuter](https://github.com/simonlindholm/decomp-permuter)
- [Byte-Equivalent Decompilation](https://www.cs.unm.edu/~eschulte/data/bed-full.pdf)

## Final release checklist

```sh
make check
make audit
make report
make unmatched
git diff --check
```

Then confirm that:

- the ROM hash is the required USA retail hash;
- every manifest row recompiles exactly;
- the audit reports 1,470 / 1,470 matched functions;
- the report shows code and initialized data at 100%;
- the unmatched queue is empty;
- the repository tracker manifest says `complete`;
- CI publishes the report artifact for the exact pushed commit.
