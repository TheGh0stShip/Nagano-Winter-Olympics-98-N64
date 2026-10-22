import csv
import json
import subprocess
import unittest
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
ROM_SIZE = 12_582_912


class BaselineTests(unittest.TestCase):
    def test_inventory_is_gap_free(self):
        with (ROOT / "analysis/rom_inventory.tsv").open() as stream:
            rows = list(csv.DictReader(stream, delimiter="\t"))
        cursor = 0
        for row in rows:
            start, end = int(row["start"], 0), int(row["end"], 0)
            self.assertEqual(start, cursor)
            self.assertEqual(int(row["size"]), end - start)
            cursor = end
        self.assertEqual(cursor, ROM_SIZE)

    def test_survey_totals(self):
        report = json.loads((ROOT / "analysis/survey/report.json").read_text())
        self.assertEqual(report["rom"]["size"], ROM_SIZE)
        self.assertEqual(report["functions"]["functions"], 1469)
        self.assertEqual(report["unknown_bytes"], 10_372_608)
        self.assertEqual(sum(report["ledger_totals"].values()), ROM_SIZE)

    def test_matching_manifest_shape(self):
        lines = (ROOT / "config/us/matching_kmc_as_units.tsv").read_text().splitlines()
        rows = [line for line in lines if line and not line.startswith("#")]
        ido_lines = (ROOT / "config/us/matching_ido_units.tsv").read_text().splitlines()
        all_rows = rows + [line for line in ido_lines if line and not line.startswith("#")]
        self.assertEqual(len(all_rows), 202)
        self.assertEqual(sum(int(row.split("\t")[1], 0) for row in all_rows), 4924)
        row = rows[0]
        fields = row.split("\t")
        self.assertEqual(fields[:3], ["0x27F4", "0xC", "src/game/get_global_halfword.c"])
        self.assertEqual(len(fields[4]), 64)

    def test_bytematch_domains_are_independent(self):
        subprocess.run(["python3", "tools/generate_decomp_report.py"],
                       cwd=ROOT, check=True, capture_output=True, text=True)
        report = json.loads((ROOT / "build/report.json").read_text())
        categories = {item["id"]: item["measures"] for item in report["categories"]}
        self.assertEqual(report["measures"]["matched_code"], "4924")
        self.assertEqual(report["measures"]["matched_data"], "0")
        self.assertEqual(categories["assets"]["total_code"], "12047904")
        self.assertEqual(categories["assets"]["matched_code"], "750216")
        self.assertEqual(categories["assets_audio"]["matched_code"], "750216")
        self.assertEqual(categories["assets_extracted"]["matched_code"], "0")
        self.assertEqual(categories["rom_inventory"]["matched_code"], "12582912")


if __name__ == "__main__":
    unittest.main()
