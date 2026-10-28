#!/usr/bin/env python3
"""Konami block-LZ stream used by Nagano Winter Olympics '98 (USA).

Stream layout (big-endian):
  u32 header: bits 31..28 = interleave width W, bits 27..0 = section size (W == 0)
  if W != 0: W+1 section headers, each u32 with bits 27..0 = section size
  section size counts its own 4-byte header plus the command bytes.
Commands:
  0x00-0x7F  back-reference: 2 bytes, length (c >> 2) + 2, distance ((c << 8) | b) & 0x3FF
  0x80-0x9F  literal run of (c & 0x1F) bytes
  0xA0-0xDF  byte run: next byte repeated (c & 0x1F) + 2 times
  0xE0-0xFE  zero run of (c & 0x1F) + 2 bytes
  0xFF n     zero run of n + 2 bytes
"""
from __future__ import annotations


class LzError(ValueError):
    pass


def tokenize(data: bytes):
    """Parse a single-section stream; return (tokens, output, consumed)."""
    if len(data) < 4:
        raise LzError("truncated header")
    header = int.from_bytes(data[:4], "big")
    if header >> 28:
        raise LzError("interleaved streams are not used by this ROM")
    size = header & 0x0FFFFFFF
    if size < 4 or size > len(data):
        raise LzError(f"bad section size {size:#x}")
    src, end = 4, size
    out = bytearray()
    toks = []
    while src < end:
        c = data[src]
        src += 1
        if c < 0x80:
            if src >= end:
                raise LzError("truncated back-reference")
            dist = ((c << 8) | data[src]) & 0x3FF
            src += 1
            n = (c >> 2) + 2
            if dist == 0 or dist > len(out):
                raise LzError(f"bad distance {dist}")
            for _ in range(n):
                out.append(out[-dist])
            toks.append(("ref", n, dist))
        elif c < 0xA0:
            n = c & 0x1F
            if src + n > end:
                raise LzError("truncated literal")
            out += data[src:src + n]
            src += n
            toks.append(("lit", n))
        elif c < 0xE0:
            n = (c & 0x1F) + 2
            if src >= end:
                raise LzError("truncated byte run")
            out += bytes([data[src]]) * n
            src += 1
            toks.append(("run", n, data[src - 1], c))
        elif c < 0xFF:
            n = (c & 0x1F) + 2
            out += bytes(n)
            toks.append(("zero", n))
        else:
            if src >= end:
                raise LzError("truncated long zero run")
            n = data[src] + 2
            src += 1
            out += bytes(n)
            toks.append(("zlong", n))
    return toks, bytes(out), size


def decode(data: bytes) -> tuple[bytes, int]:
    _, out, used = tokenize(data)
    return out, used


WINDOW = 991          # farthest back-reference distance the retail encoder emits
MAX_MATCH = 33
MAX_RUN = 32          # byte-run commands 0xC0-0xDE
MAX_LONG_ZERO = 257   # 0xFF n
LOOKAHEAD_INIT = 0x421
LOOKAHEAD_STEP = 0x400


def encode(data: bytes) -> bytes:
    """Re-create the retail encoder's exact output for `data`.

    Decision order at each position (all proven against 547 retail streams):
    zero run (>= 2) if it is at least as long as the best match and byte run;
    else back-reference (>= 4, nearest of the longest) if strictly longer than
    the byte run; else byte run (>= 3, non-zero); else extend a literal run
    (flushed at 31 bytes).  Zero runs never extend past the encoder's input
    buffer end, which starts at 0x421 and grows by 0x400 whenever 33 or fewer
    bytes of lookahead remain.
    """
    n = len(data)
    out = bytearray(4)
    lit_at = -1
    lit_n = 0
    vend = LOOKAHEAD_INIT
    chains: dict[bytes, list[int]] = {}
    indexed = 0
    p = 0

    def flush():
        nonlocal lit_n
        if lit_n:
            out[lit_at] = 0x80 | lit_n
            lit_n = 0

    while p < n:
        while indexed < p:
            key = data[indexed:indexed + 4]
            if len(key) == 4:
                chains.setdefault(key, []).append(indexed)
            indexed += 1
        while vend - p <= 33:
            vend += LOOKAHEAD_STEP
        zr = 0
        lim = min(n, vend, p + MAX_LONG_ZERO)
        while p + zr < lim and data[p + zr] == 0:
            zr += 1
        br = 1
        while p + br < n and br < MAX_RUN and data[p + br] == data[p]:
            br += 1
        bm = bd = 0
        key = data[p:p + 4]
        if len(key) == 4:
            cand = chains.get(key)
            if cand:
                lo = p - WINDOW
                lim_m = min(MAX_MATCH, n - p)
                for q in reversed(cand):
                    if q < lo:
                        break
                    length = 4
                    while length < lim_m and data[q + length] == data[p + length]:
                        length += 1
                    if length > bm:
                        bm, bd = length, p - q
                        if bm == lim_m:
                            break
        zc = zr if zr >= 2 else 0
        rc = br if (br >= 3 and data[p] != 0) else 0
        if zc and zc >= bm and zc >= rc:
            flush()
            if zc <= 32:
                out.append(0xE0 | (zc - 2))
            else:
                out += bytes((0xFF, zc - 2))
            p += zc
        elif bm and bm > rc:
            flush()
            v = ((bm - 2) << 10) | bd
            out += bytes((v >> 8, v & 0xFF))
            p += bm
        elif rc:
            flush()
            out += bytes((0xC0 | (rc - 2), data[p]))
            p += rc
        else:
            if not lit_n:
                lit_at = len(out)
                out.append(0)
            out.append(data[p])
            p += 1
            lit_n += 1
            if lit_n == 31:
                flush()
    flush()
    size = len(out)
    if size > 0x0FFFFFFF:
        raise LzError("stream too large")
    out[0:4] = size.to_bytes(4, "big")
    return bytes(out)
