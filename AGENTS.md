# Nagano Winter Olympics '98 decompilation instructions

The target is the USA retail Nintendo 64 ROM with SHA-1
`eaf543e195731031a84f4136b506449209e3a8f5`. Never commit ROMs, extracted
copyrighted assets, compiler binaries, or generated assembly.

This is Nintendo 64 code: big-endian MIPS III / VR4300, 32-bit o32 ABI. Use
explicit-width types at binary boundaries. Host pointer size, alignment, and
endianness are not evidence for target layouts.

The initial program image is ROM `0x1000..0x829E0`, loaded at
`0x80000400..0x80081DE0`; BSS is `0x80081DE0..0x801954A0`. Current evidence
identifies IDO as the predominant game compiler. Check every unit against the
retail ROM: a unit is matching only when `make verify-matching` proves its
relocated bytes equal. Keep speculative or merely equivalent C out of the
matching manifest.

Use `/home/steve/projects/n64-decomp-kit` when available. Override
`N64DK_ROOT` and `N64DK_TOOLCHAIN`; do not embed machine-specific paths.

Inventory claims must distinguish physical byte coverage from decoded asset
counts. Unknown bytes and loader-referenced ranges remain explicitly unknown
until their formats and nested records are proven.

