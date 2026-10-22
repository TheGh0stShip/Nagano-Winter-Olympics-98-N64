import struct
import unittest

from tools.audit_full_rom import entropy, scan_function, size_bucket


class FullRomAuditTests(unittest.TestCase):
    def test_entropy_extremes(self):
        self.assertEqual(entropy(bytes(32)), 0.0)
        self.assertEqual(entropy(bytes(range(256))), 8.0)

    def test_size_buckets(self):
        self.assertEqual(size_bucket(0x10), "<=0x10")
        self.assertEqual(size_bucket(0x11), "<=0x20")
        self.assertEqual(size_bucket(0x900), ">0x800")

    def test_function_scan_resolves_direct_call(self):
        target = 0x80002000
        jal = 0x0C000000 | ((target >> 2) & 0x03FFFFFF)
        data = struct.pack(">II", jal, 0)
        result = scan_function(data, 0x80001000, {target: "callee"})
        self.assertEqual(result["direct_calls"][0]["name"], "callee")
        self.assertEqual(result["trailing_nops"], 1)


if __name__ == "__main__":
    unittest.main()
