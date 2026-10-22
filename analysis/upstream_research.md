# Public-source research survey

Fifty-two targeted search rounds were run on 2026-10-22. No independent public
matching decompilation or original source release for this exact N64 title was
found. Search results offering ROM downloads were not used.

| Rounds | Focus | Result |
|---:|---|---|
| 1-4 | Exact title, source, reverse engineering, `NH5E` | No matching project or source found |
| 5-8 | KCEO/Konami Osaka and sibling N64 games | Hybrid Heaven work exists; no proven shared source |
| 9-12 | Debug symbols, prototypes, Japanese release, patents | Metadata and unrelated PlayStation prototype only |
| 13-16 | IDO, libultra, F3DEX 1.21, `ALBankFile` | Mature references and extractors found |
| 17-20 | Inventory standards, objdiff v2, ByteMatch CI | Objdiff v2 artifact workflow selected |
| 21-24 | Texture/audio/sequence/Konami compression | General tools found; no exact codec identified |
| 25-28 | Konami N64 and sibling decomps | Useful patterns, not format proof |
| 29-32 | splat, Rabbitizer, asm-differ, m2c | Standard tooling remains applicable |
| 33-36 | decomp-permuter, libreultra, IDO, fingerprints | Strong compiler/SDK matching sources |
| 37-40 | Konami filesystem, archive, texture, audio | No public format match established |
| 41-44 | Credits, manual, formats, speedrun notes | No technical source recovered |
| 45-48 | Progress methodology and completed projects | Conservative byte ledger adopted |
| 49-52 | Interviews, Japanese credits, serials, RAM codes | Metadata only; no symbols or layouts |

## Highest-value references

- [libreultra](https://github.com/n64decomp/libreultra) for SDK source candidates.
- [splat](https://github.com/ethteck/splat),
  [asm-differ](https://github.com/simonlindholm/asm-differ),
  [m2c](https://github.com/matt-kempster/m2c), and
  [decomp-permuter](https://github.com/simonlindholm/decomp-permuter) for
  splitting, comparison, reconstruction, and source-shape work.
- [objdiff](https://github.com/encounter/objdiff) for reproducible reports.
- Public Hybrid Heaven, Mystical Ninja, and Castlevania 64 work as organization
  and hypothesis references only. Studio or publisher overlap does not prove
  shared engines, compilers, or formats.

The exact ROM survey remains the strongest title-specific evidence:
predominantly IDO-shaped code with a KMC-shaped minority, libultra 2.0D-2.0H
fingerprints, F3DEX 1.21, three libaudio banks, and a gap-free ROM ledger.

