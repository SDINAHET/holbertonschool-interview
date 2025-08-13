.PHONY: test pep8 all
PY = python3
# Utilise pycodestyle si dispo, sinon pep8
PEP8 ?= $(shell command -v pycodestyle >/dev/null 2>&1 && echo pycodestyle || echo pep8)

all: pep8 test

pep8:
	$(PEP8) 0-count.py
	$(PY) -m unittest -v
