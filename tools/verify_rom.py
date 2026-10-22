#!/usr/bin/env python3
import hashlib
import sys
from pathlib import Path

EXPECTED_SHA1 = "eaf543e195731031a84f4136b506449209e3a8f5"
EXPECTED_SIZE = 12 * 1024 * 1024

path = Path(sys.argv[1])
data = path.read_bytes()
actual = hashlib.sha1(data).hexdigest()
if len(data) != EXPECTED_SIZE or actual != EXPECTED_SHA1:
    raise SystemExit(f"wrong ROM: size={len(data)} sha1={actual}")
if data[:4] != bytes.fromhex("80371240"):
    raise SystemExit("ROM is not big-endian z64 byte order")
print(f"verified {path}: {actual}")

