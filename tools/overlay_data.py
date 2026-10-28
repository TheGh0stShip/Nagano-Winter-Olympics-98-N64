#!/usr/bin/env python3
"""Bound each overlay's text/data split and emit its data as typed C units.

Overlay records live at RAM 0x80063558.. as {u32 romStart, u32 vram, u32 romEnd, u32 romStart}.
Text ends after the final `jr ra` delay slot; data starts at the first address
referenced by the overlay's own lui/lo address pairs at or after that point.
Data objects are split at every referenced address; each object becomes a
u32/u16/u8 array whose values reproduce the retail bytes.
"""
import os, struct, sys
RAM = 0x7FFFF400
VB = 0x801954A0
def overlays(rom):
    recs = []
    a = 0x80063558 - RAM
    while True:
        s, vram, e, s2 = struct.unpack_from(">IIII", rom, a)
        if vram != VB:
            break
        recs.append((s, e)); a += 16
    uniq = sorted(set(recs))
    return uniq, len(recs)
def split(rom, s, e):
    words = [struct.unpack_from(">I", rom, x)[0] for x in range(s, e, 4)]
    lastjr = max(i for i, w in enumerate(words) if w == 0x03E00008)
    textend_v = VB + (lastjr + 2) * 4
    hi = {}; refs = set()
    for w in words[:lastjr + 2]:
        op = w >> 26
        if op == 0x0F:
            hi[(w >> 16) & 31] = (w & 0xFFFF) << 16
        elif op in (0x09, 0x20, 0x21, 0x23, 0x24, 0x25, 0x28, 0x29, 0x2B, 0x31, 0x35, 0x39, 0x3D):
            rs = (w >> 21) & 31
            if rs in hi:
                a = (hi[rs] + ((w & 0xFFFF) ^ 0x8000) - 0x8000) & 0xFFFFFFFF
                if VB <= a < VB + (e - s):
                    refs.add(a)
    data_v = min(r for r in refs if r >= textend_v)
    return textend_v, data_v, sorted(r for r in refs if r >= data_v)
def emit(rom, s, e, out):
    tv, dv, refs = split(rom, s, e)
    end_v = VB + (e - s)
    gap = rom[s + (tv - VB):s + (dv - VB)]
    cuts = sorted(set(refs + [dv, end_v]))
    lines = [f"/* Overlay ROM {s:#x}..{e:#x} loaded at {VB:#x}; data {dv:#x}..{end_v:#x}. */", "typedef unsigned int u32;", "typedef unsigned short u16;", "typedef unsigned char u8;", ""]
    objs = []
    # objects must start 4-aligned to be separate globals; merge unaligned cuts into the previous object
    starts = [c for c in cuts[:-1] if c % 4 == 0 or c == dv]
    for a, b in zip(starts, starts[1:] + [end_v]):
        blob = rom[s + (a - VB):s + (b - VB)]
        n4 = len(blob) // 4 * 4
        parts = []
        if n4:
            parts.append(("u32 w", [f"0x{struct.unpack_from('>I', blob, i)[0]:08X}" for i in range(0, n4, 4)]))
        if len(blob) - n4:
            parts.append(("u8 b", [f"0x{x:02X}" for x in blob[n4:]]))
        name = f"D_{a:08X}"
        if len(parts) == 1 and parts[0][0] == "u32 w":
            vals = parts[0][1]
            lines.append(f"u32 {name}[{len(vals)}] = {{ " + ", ".join(vals) + " };")
        else:
            fields = " ".join(f"{t}[{len(v)}];" for t, v in parts)
            init = ", ".join("{ " + ", ".join(v) + " }" for t, v in parts)
            lines.append(f"struct {{ {fields} }} {name} = {{ {init} }};")
        objs.append((a, b - a))
    open(out, "w").write("\n".join(lines) + "\n")
    return tv, dv, end_v, gap, objs
if __name__ == "__main__":
    rom = open(sys.argv[1], "rb").read(); outdir = sys.argv[2]
    uniq, n = overlays(rom)
    print("overlay records", n, "unique", len(uniq))
    rows = []
    for s, e in uniq:
        tv, dv, ev, gap, objs = emit(rom, s, e, f"{outdir}/ovl_{s:06X}.c")
        rows.append((s, e, tv, dv, ev, len(gap), any(gap), len(objs)))
        print(f"{s:#x}-{e:#x} text_end_vram {tv:#x} data_vram {dv:#x} gap {len(gap)} nonzero_gap {any(gap)} objects {len(objs)}")
    with open(f"{outdir}/overlays.tsv", "w") as f:
        f.write("rom_start\trom_end\ttext_end_vram\tdata_vram\tdata_end_vram\tgap\tgap_nonzero\tobjects\n")
        for r in rows: f.write("\t".join(hex(x) if isinstance(x, int) and not isinstance(x, bool) else str(x) for x in r) + "\n")
