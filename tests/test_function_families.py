import struct
import unittest

from tools.find_function_families import (
    fingerprint,
    instruction_token,
    ngrams,
    normalize_instruction,
    shape_instruction,
    token_stream,
)


class FunctionFamilyTests(unittest.TestCase):
    def test_masks_targets_and_immediates(self):
        self.assertEqual(normalize_instruction(0x0C123456), 0x0C000000)
        self.assertEqual(normalize_instruction(0x8C820010), 0x8C820000)
        self.assertEqual(normalize_instruction(0x24420004), 0x24420000)

    def test_preserves_register_shape(self):
        self.assertNotEqual(normalize_instruction(0x8C820010),
                            normalize_instruction(0x8C830010))

    def test_fingerprint_ignores_relocations(self):
        first = struct.pack(">II", 0x3C028001, 0x0C123456)
        second = struct.pack(">II", 0x3C028019, 0x0C654321)
        self.assertEqual(fingerprint(first), fingerprint(second))

    def test_relaxed_shape_ignores_register_allocation(self):
        self.assertEqual(shape_instruction(0x8C820010), shape_instruction(0x8C830020))
        self.assertEqual(fingerprint(struct.pack(">I", 0x8C820010), relaxed=True),
                         fingerprint(struct.pack(">I", 0x8C830020), relaxed=True))

    def test_similarity_tokens_retain_small_immediates(self):
        self.assertNotEqual(instruction_token(0x8C820010, 0x80001000, {}),
                            instruction_token(0x8C820014, 0x80001000, {}))

    def test_similarity_tokens_name_direct_callees(self):
        target = 0x80002000
        jal = 0x0C000000 | ((target >> 2) & 0x03FFFFFF)
        self.assertIn("load_record", instruction_token(
            jal, 0x80001000, {target: "load_record"}))

    def test_token_stream_and_grams(self):
        data = struct.pack(">III", 0x24020001, 0x24420002, 0x03E00008)
        tokens = token_stream(data, 0x80001000, {})
        self.assertEqual(len(tokens), 3)
        self.assertEqual(ngrams(tokens), {tuple(tokens)})


if __name__ == "__main__":
    unittest.main()
