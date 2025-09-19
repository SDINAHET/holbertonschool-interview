#!/usr/bin/env bash
set -euo pipefail

F=0-merge_sort.c

[ -f "$F" ] || { echo "Missing $F"; exit 1; }

# Count malloc/free occurrences in student file (ignore comments/strings heuristically)
strip_comments() {
  sed -E 's:/\*([^*]|\*+[^*/])*\*+/::g' | sed -E 's://.*$::'
}

MALLOC_COUNT=$(strip_comments < "$F" | grep -o '\bmalloc\s*\(' | wc -l | tr -d ' ')
FREE_COUNT=$(strip_comments < "$F" | grep -o '\bfree\s*\(' | wc -l | tr -d ' ')

if [ "$MALLOC_COUNT" -ne 1 ]; then
  echo "Expected exactly 1 malloc in $F, found $MALLOC_COUNT"
  exit 1
fi

if [ "$FREE_COUNT" -ne 1 ]; then
  echo "Expected exactly 1 free in $F, found $FREE_COUNT"
  exit 1
fi

echo "Source-level alloc check passed (1 malloc / 1 free) ✅"
