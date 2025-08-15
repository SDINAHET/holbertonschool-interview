.PHONY: all pep8 test test-unit test-integration test-requirements test-meta help
PY   = python3
# Utilise pycodestyle si dispo, sinon pep8
PEP8 ?= $(shell command -v pycodestyle >/dev/null 2>&1 && echo pycodestyle || echo pep8)

all: pep8 test

## ---- Qualité ----
pep8:
	$(PEP8) 0-count.py

## ---- Tests ----
test:
	$(PY) -m unittest -v

test-unit:
	$(PY) -m unittest -v test_unit_0_count.py

test-integration:
	$(PY) -m unittest -v test_integration_0_count.py

test-requirements:
	$(PY) -m unittest -v test_requirements_0_count.py

test-meta:
	$(PY) -m unittest -v test_meta_0_count.py

help:
	@echo "make            -> pep8 + tous les tests"
	@echo "make pep8       -> PEP8 sur 0-count.py"
	@echo "make test       -> tous les tests (découverte unittest)"
	@echo "make test-unit  -> tests unitaires"
	@echo "make test-integration -> tests d'intégration"
	@echo "make test-requirements -> tests des exigences"
	@echo "make test-meta  -> tests méta (shebang, README, imports)"
