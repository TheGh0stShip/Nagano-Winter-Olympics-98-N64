#!/usr/bin/env python3
"""Decode the block LZ stream used by Nagano's compressed sequences."""

import argparse
from pathlib import Path


class DecodeError(ValueError):
    pass


def decode(data: bytes) -> tuple[bytes, int]:
    """Return the decoded bytes and the number of compressed bytes consumed."""
    source = 0
    output = bytearray()
    while source + 4 <= len(data):
        header = int.from_bytes(data[source:source + 4], "big")
        width = header >> 28
        source += 4
        section_count = width + 1 if width else 1
        for section in range(section_count):
            if width:
                if source + 4 > len(data):
                    raise DecodeError("truncated interleave header")
                section_size = int.from_bytes(data[source:source + 4], "big") & 0x0FFFFFFF
                source += 4
            else:
                section_size = header & 0x0FFFFFFF
            if section_size < 4:
                raise DecodeError(f"invalid section size {section_size}")
            end = source + section_size - 4
            if end > len(data):
                raise DecodeError("section extends beyond input")
            while source < end:
                command = data[source]
                source += 1
                if command < 0x80:
                    if source >= end:
                        raise DecodeError("truncated back-reference")
                    distance = ((command << 8) | data[source]) & 0x3FF
                    source += 1
                    count = (command >> 2) + 2
                    if distance == 0 or distance > len(output):
                        raise DecodeError(f"invalid back-reference distance {distance}")
                    for _ in range(count):
                        output.append(output[-distance])
                elif command < 0xA0:
                    count = command & 0x1F
                    if source + count > end:
                        raise DecodeError("truncated literal")
                    output.extend(data[source:source + count])
                    source += count
                elif command < 0xE0:
                    count = (command & 0x1F) + 2
                    if source >= end:
                        raise DecodeError("truncated byte run")
                    output.extend([data[source]] * count)
                    source += 1
                elif command < 0xFF:
                    output.extend(bytes((command & 0x1F) + 2))
                else:
                    if source >= end:
                        raise DecodeError("truncated zero run")
                    output.extend(bytes(data[source] + 2))
                    source += 1
        # Sequence records are individually bounded by the loader table. Any
        # remaining bytes are alignment padding, not another stream section.
        break
    return bytes(output), source


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("input", type=Path, help="ROM or isolated compressed stream")
    parser.add_argument("output", type=Path)
    parser.add_argument("--start", type=lambda value: int(value, 0), default=0)
    parser.add_argument("--end", type=lambda value: int(value, 0))
    args = parser.parse_args()
    source = args.input.read_bytes()
    end = len(source) if args.end is None else args.end
    decoded, consumed = decode(source[args.start:end])
    args.output.write_bytes(decoded)
    print(f"decoded {consumed} compressed bytes to {len(decoded)} bytes")


if __name__ == "__main__":
    main()
