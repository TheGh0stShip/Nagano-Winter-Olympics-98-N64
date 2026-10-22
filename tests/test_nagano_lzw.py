import csv
import unittest
from pathlib import Path

from tools.decode_nagano_lzw import DecodeError, decode

ROOT = Path(__file__).resolve().parents[1]


class NaganoLzwTests(unittest.TestCase):
    def test_command_families(self):
        payload = bytes((0x83,)) + b"ABC" + bytes((0xA1, ord("Z"), 0xE1, 0x00, 0x09))
        stream = (len(payload) + 4).to_bytes(4, "big") + payload
        decoded, consumed = decode(stream + b"padding")
        self.assertEqual(decoded, b"ABCZZZ\0\0\0AB")
        self.assertEqual(consumed, len(stream))

    def test_rejects_invalid_distance(self):
        with self.assertRaises(DecodeError):
            decode(bytes.fromhex("000000060001"))

    def test_inventory_music_records_decode(self):
        rom = (ROOT / "baseroms/us/baserom.z64").read_bytes()
        with (ROOT / "analysis/rom_inventory.tsv").open() as stream:
            rows = [row for row in csv.DictReader(stream, delimiter="\t")
                    if row["kind"] == "konami_lzw_sequence"]
        self.assertEqual(len(rows), 23)
        self.assertEqual(sum(int(row["size"]) for row in rows), 44_176)
        for row in rows:
            start, end = int(row["start"], 0), int(row["end"], 0)
            decoded, consumed = decode(rom[start:end])
            self.assertGreater(len(decoded), 0, row["name"])
            self.assertLessEqual(consumed, end - start, row["name"])


if __name__ == "__main__":
    unittest.main()
