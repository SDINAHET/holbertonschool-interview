#!/usr/bin/env bash
set -euo pipefail

EXE=${1:-./mul}

pass=0
fail=0

nl=$'\n'

ok() { printf "✅ %s\n" "$1"; pass=$((pass+1)); }
ko() { printf "❌ %s\n" "$1"; fail=$((fail+1)); }

run_ok () {
  local a="$1" b="$2" expected="$3"
  out="$("$EXE" "$a" "$b" 2>/dev/null)" || { ko "OK $a * $b -> exécution a échoué"; return; }
  if [[ "$out" == "$expected" ]]; then
    ok "OK $a * $b == $expected"
  else
    ko "OK $a * $b -> attendu '$expected', obtenu '$out'"
  fi
}

run_err () {
  # usage: run_err "args..." expected_exit expected_stdout
  local expected_rc="$1"; shift
  local -a args=("$@")
  local out rc
  set +e
  out="$("$EXE" "${args[@]}" 2>/dev/null)"
  rc=$?
  set -e
  if [[ $rc -ne $expected_rc ]]; then
    ko "ERR ${args[*]} -> attendu rc=$expected_rc, obtenu rc=$rc (out='$out')"
    return
  fi
  if [[ "$out" == "Error" ]]; then
    ok "ERR ${args[*]} -> rc=$expected_rc et 'Error'"
  else
    ko "ERR ${args[*]} -> attendu 'Error', obtenu '$out'"
  fi
}

# --- Construction si besoin ---
if [[ ! -x "$EXE" ]]; then
  echo "Compilation de ./mul ..."
  gcc -Wall -Wextra -Werror -pedantic 0-mul.c _putchar.c -o mul
  EXE=./mul
fi

echo "=== Tests OK ==="
run_ok  "123" "456" "56088"
run_ok  "0" "0" "0"
run_ok  "000000" "42" "0"
run_ok  "98" "765" "74970"
run_ok  "123456789" "987654321" "121932631112635269"

echo "${nl}=== Tests ERREUR (rc=98) ==="
run_err 98                "abc" "123"
run_err 98                "123" "12x"
run_err 98                "123"          # pas assez d’arguments
run_err 98                               # zéro argument
# argument en trop -> l’exécutable n’accepte pas >2 opérandes
run_err 98                "1" "2" "3"

echo "${nl}=== Résumé ==="
echo "Pass: $pass / Fail: $fail"
test "$fail" -eq 0
