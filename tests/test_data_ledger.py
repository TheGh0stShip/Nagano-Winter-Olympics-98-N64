"""Tests for the physical data ledger, LZ codec, libaudio serializer and ROM checks.

Synthetic tests always run; ROM-backed tests run only when the user-supplied
retail ROM is present at baseroms/us/baserom.z64.
"""
import hashlib
import struct
import sys
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
sys.path.insert(0, str(ROOT / "tools"))

import konami_lz  # noqa: E402
import nagano_audio  # noqa: E402
import nagano_data  # noqa: E402
import rom_header  # noqa: E402

ROM_PATH = ROOT / "baseroms/us/baserom.z64"
HAVE_ROM = ROM_PATH.exists() and hashlib.sha1(ROM_PATH.read_bytes()).hexdigest() == nagano_data.ROM_SHA1


def row(start, end, cat="padding"):
    return {"start": start, "end": end, "size": end - start, "category": cat}


class EndianTests(unittest.TestCase):
    def test_be32_reads_big_endian(self):
        self.assertEqual(nagano_data.be32(b"\x12\x34\x56\x78", 0), 0x12345678)

    def test_be32_bounds(self):
        with self.assertRaises(nagano_data.DataError):
            nagano_data.be32(b"\x00\x01\x02", 0)

    def test_normalize_byte_orders(self):
        z64 = b"\x80\x37\x12\x40" + bytes(range(4, 16))
        v64 = bytes(x for i in range(0, 16, 2) for x in (z64[i + 1], z64[i]))
        n64 = b"".join(z64[i:i + 4][::-1] for i in range(0, 16, 4))
        self.assertEqual(nagano_data.normalize(v64), z64)
        self.assertEqual(nagano_data.normalize(n64), z64)
        with self.assertRaises(nagano_data.DataError):
            nagano_data.normalize(b"junkjunk")

    def test_rom_hash_and_size_rejection(self):
        bad = ROOT / "build" / "bad_rom.z64"
        bad.parent.mkdir(exist_ok=True)
        bad.write_bytes(b"\x80\x37\x12\x40" + bytes(16))
        with self.assertRaises(nagano_data.DataError):
            nagano_data.load_rom(bad)
        bad.write_bytes(b"\x80\x37\x12\x40" + bytes(nagano_data.ROM_SIZE - 4))
        with self.assertRaises(nagano_data.DataError):
            nagano_data.load_rom(bad)
        bad.unlink()


class MapValidationTests(unittest.TestCase):
    def setUp(self):
        self.size = nagano_data.ROM_SIZE

    def test_valid_map(self):
        cats = nagano_data.validate([row(0, 0x100), row(0x100, self.size, "unknown")])
        self.assertEqual(sum(cats.values()), self.size)

    def test_gap_detected(self):
        with self.assertRaisesRegex(nagano_data.DataError, "gap"):
            nagano_data.validate([row(0, 0x100), row(0x200, self.size)])

    def test_overlap_detected(self):
        with self.assertRaisesRegex(nagano_data.DataError, "overlap"):
            nagano_data.validate([row(0, 0x200), row(0x100, self.size)])

    def test_must_start_at_zero_and_end_at_rom_size(self):
        with self.assertRaises(nagano_data.DataError):
            nagano_data.validate([row(4, self.size)])
        with self.assertRaises(nagano_data.DataError):
            nagano_data.validate([row(0, self.size - 4)])

    def test_ledger_rejects_unknown_category_and_stage(self):
        led = nagano_data.Ledger()
        with self.assertRaises(nagano_data.DataError):
            led.add(0, 4, "blob", "x")
        with self.assertRaises(nagano_data.DataError):
            led.add(0, 4, "padding", "x", stage="done")


class LzTests(unittest.TestCase):
    SAMPLES = [b"", b"A", bytes(600), b"ABCD" * 300, bytes(range(256)) * 9,
               b"\x01\x01\x01\x01\x02" * 77 + bytes(1100) + b"tail", bytes(2000) + b"\xff" * 40 + bytes(5)]

    def test_round_trip(self):
        for data in self.SAMPLES:
            enc = konami_lz.encode(data)
            out, used = konami_lz.decode(enc)
            self.assertEqual(out, data)
            self.assertEqual(used, len(enc))

    def test_window_and_run_limits(self):
        toks, _, _ = konami_lz.tokenize(konami_lz.encode(b"XYZW" + bytes(2000) + b"XYZW" + b"\x07" * 100))
        for t in toks:
            if t[0] == "ref":
                self.assertLessEqual(t[2], konami_lz.WINDOW)
                self.assertGreaterEqual(t[1], 4)
            if t[0] == "run":
                self.assertLessEqual(t[1], konami_lz.MAX_RUN)

    def test_malformed_streams(self):
        for bad in (b"\x00\x00", b"\x00\x00\x00\x02", b"\x00\x00\x00\x06\x00\x05", b"\x10\x00\x00\x08aaaa",
                    b"\x00\x00\x00\x06\x85a"):
            with self.assertRaises(konami_lz.LzError):
                konami_lz.decode(bad)


class AudioTests(unittest.TestCase):
    def test_bad_revision(self):
        with self.assertRaises(nagano_audio.AudioError):
            nagano_audio.parse_ctl(b"XX\x00\x01\x00\x00\x00\x08")

    def test_sample_bounds(self):
        with self.assertRaises(nagano_audio.AudioError):
            nagano_audio.tbl_samples([{"base": 0x10, "len": 0x20}], 0x20)


@unittest.skipUnless(HAVE_ROM, "retail ROM not present")
class RomTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.rom = nagano_data.load_rom(ROM_PATH)
        cls.rows, cls.cats, *_ = nagano_data.build_map(cls.rom)

    def test_map_covers_rom(self):
        self.assertEqual(self.rows[0]["start"], 0)
        self.assertEqual(self.rows[-1]["end"], nagano_data.ROM_SIZE)
        self.assertEqual(sum(self.cats.values()), nagano_data.ROM_SIZE)
        self.assertEqual(self.cats.get("unknown", 0), 0)

    def test_nested_containers_do_not_inflate_physical_coverage(self):
        comp = sum(r["size"] for r in self.rows if r["compression"] != "none")
        logical = sum(r["decoded_size"] or 0 for r in self.rows if r["compression"] != "none")
        self.assertLess(comp, logical)
        self.assertEqual(sum(r["size"] for r in self.rows), nagano_data.ROM_SIZE)

    def test_header_crc_reconstruction(self):
        fields = rom_header.parse_header(self.rom)
        self.assertEqual(rom_header.build_header(fields, self.rom), self.rom[:0x40])

    def test_file_table(self):
        ents = nagano_data.file_table(self.rom)
        self.assertEqual(len(ents), 538)
        self.assertEqual(ents[0]["start"], 0x3FC620)
        self.assertEqual(ents[-1]["end"], 0xBB0A20)

    def test_representative_lz_files_reencode_exactly(self):
        for f in nagano_data.file_table(self.rom)[::61]:
            if f["compressed"] and f["end"] > f["start"]:
                out, used = konami_lz.decode(self.rom[f["start"]:f["end"]])
                self.assertEqual(konami_lz.encode(out), self.rom[f["start"]:f["start"] + used])

    def test_audio_banks_reserialize(self):
        for cs, ce, ts, te in nagano_audio.bank_table(self.rom):
            objs, waves = nagano_audio.parse_ctl(self.rom[cs:ce])
            self.assertEqual(nagano_audio.serialize_ctl(objs, ce - cs), self.rom[cs:ce])

    def test_raw_record_streams(self):
        for f in nagano_data.file_table(self.rom):
            if not f["compressed"] and f["end"] > f["start"]:
                blob = self.rom[f["start"]:f["end"]]
                vals = struct.unpack(">%dh" % (len(blob) // 2), blob)
                self.assertEqual(struct.pack(">%dh" % len(vals), *vals), blob)


if __name__ == "__main__":
    unittest.main()


class AssetDecodeTests(unittest.TestCase):
    def _model(self):
        import struct as S
        vtx = b"".join(S.pack(">hhhHhhBBBB", i, -i, 2 * i, 0, i * 4, i * 8, 255, 128, 0, 255) for i in range(3))
        tex = bytes(range(64)) * 2                     # 128 bytes = 64 RGBA16 texels
        dl_off = 0x10 + len(vtx) + len(tex)
        dl = S.pack(">II", 0x04000000 | (3 << 10) | (3 * 16 - 1), 0x06000010)
        dl += S.pack(">II", 0xFD100000, 0x06000000 + 0x10 + len(vtx))
        dl += S.pack(">II", 0xF3000000, (63 << 12) | 0x800)
        dl += S.pack(">II", 0xBF000000, 0x00000204)
        dl += S.pack(">II", 0xB8000000, 0)
        head = S.pack(">II", 0x06000000 + dl_off, 0x06000000 + dl_off) + bytes(8)
        return head + vtx + tex + dl

    def test_synthetic_model_fully_decoded(self):
        import asset_decode
        blob = self._model()
        counts, regions = asset_decode.decode_any(blob)
        self.assertEqual(counts["unknown"], 0)
        kinds = {r.kind for r in regions}
        self.assertTrue({"dl", "vtx", "tex", "ptrtab"} <= kinds)
        for r in regions:
            if r.kind == "vtx":
                self.assertTrue(asset_decode.vtx_roundtrip(blob, r.start, r.end))
            if r.kind == "dl":
                self.assertTrue(asset_decode.dl_roundtrip(blob, r.start, r.end))

    def test_record_stream_detection(self):
        import asset_decode
        import struct as S
        recs = b"".join(S.pack(">6h", 1000 + i, -500 + 2 * i, 30 + i, -9000 + 3 * i, 7, 4000 - i) for i in range(200))
        blob = recs + bytes(16 - len(recs) % 16 if len(recs) % 16 else 0)
        self.assertEqual(asset_decode.record_stream(blob), 200)
        self.assertIsNone(asset_decode.record_stream(bytes(range(256)) * 10))
