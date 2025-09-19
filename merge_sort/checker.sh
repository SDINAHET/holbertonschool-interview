#!/usr/bin/env bash
set -euo pipefail

echo "== Build =="
make clean >/dev/null
make test

echo "== Run unit tests =="
./tests_runner

echo "== Check 0-O =="
make check-o

echo "== Betty =="
make betty

echo "== ltrace best-effort (malloc/free) =="
make ltracecheck || true

echo "All checks passed ✅"
