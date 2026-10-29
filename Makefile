PYTHON ?= python3
ROM ?= baseroms/us/baserom.z64
N64DK_ROOT ?= ../n64-decomp-kit
N64DK_PYTHON ?= $(abspath $(N64DK_ROOT))/.venv/bin/python
N64DK_TOOLCHAIN ?= ../BattleTanx/.toolchain
N64DK := PYTHONPATH=$(abspath $(N64DK_ROOT)) N64DK_TOOLCHAIN=$(abspath $(N64DK_TOOLCHAIN)) $(N64DK_PYTHON) -m n64dk

.PHONY: audit check families similar unmatched report report-check verify-rom verify-matching survey

check: verify-rom verify-matching report-check

verify-rom:
	$(PYTHON) tools/verify_rom.py "$(ROM)"

verify-matching: verify-rom
	$(N64DK) match-batch config/us/matching_kmc_as_units.tsv=kmc+as --project . --symbols analysis/survey/symbol_addrs.txt
	$(N64DK) match-batch config/us/matching_asm_units.tsv=as --project . --symbols analysis/survey/symbol_addrs.txt
	$(N64DK) match-batch config/us/matching_ido_asm_units.tsv=ido5.3 --project . --symbols analysis/survey/symbol_addrs.txt
	$(N64DK) match-batch config/us/matching_ido_units.tsv=ido5.3 --project . --symbols analysis/survey/symbol_addrs.txt
	$(N64DK) match-batch config/us/matching_ido7_units.tsv=ido7.1 --project . --symbols analysis/survey/symbol_addrs.txt
	$(N64DK) match-batch config/us/matching_ido_data_units.tsv=ido5.3 --project . --symbols analysis/survey/symbol_addrs.txt

report:
	$(PYTHON) tools/generate_decomp_report.py

report-check:
	$(PYTHON) -m unittest discover -s tests

survey: verify-rom
	$(N64DK) survey "$(ROM)" --out analysis/survey

families: verify-rom
	$(PYTHON) tools/find_function_families.py --rom "$(ROM)" --include-unmatched

similar: verify-rom
	$(PYTHON) tools/find_function_families.py --rom "$(ROM)" --similar

unmatched:
	$(PYTHON) tools/list_unmatched_functions.py

audit: verify-rom
	$(PYTHON) tools/audit_full_rom.py --rom "$(ROM)"

