#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Checks 'style Holberton' exécutés en CI:
- Fichier présent
- Première ligne == shebang attendu
- Module documenté (__doc__ non vide)
- Exécution de quelques cas de test 'sanity'
- Test « performance » simple (borne haute de temps)
"""

import os
import re
import time
import importlib.util
import unittest


ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
TARGET = os.path.join(ROOT, '0-making_change.py')


def load_makeChange():
    try:
        return __import__('0-making_change').makeChange
    except Exception:
        spec = importlib.util.spec_from_file_location('mc_mod', TARGET)
        mod = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(mod)  # type: ignore
        return getattr(mod, 'makeChange')


class TestHbtnSpec(unittest.TestCase):
    def test_file_exists(self):
        self.assertTrue(os.path.isfile(TARGET), "0-making_change.py manquant")

    def test_shebang(self):
        with open(TARGET, 'r', encoding='utf-8') as f:
            first = f.readline().rstrip('\n')
        self.assertEqual(first, "#!/usr/bin/python3",
                         "La première ligne doit être exactement #!/usr/bin/python3")

    def test_module_docstring(self):
        spec = importlib.util.spec_from_file_location('mc_mod', TARGET)
        mod = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(mod)  # type: ignore
        self.assertTrue((mod.__doc__ or "").strip(),
                        "Le module doit contenir une docstring non vide")

    def test_small_total_possible(self):
        makeChange = load_makeChange()
        self.assertEqual(makeChange([1, 2, 25], 37), 7)

    def test_small_total_impossible(self):
        makeChange = load_makeChange()
        self.assertEqual(makeChange([4, 6], 3), -1)

    def test_zero_and_negative(self):
        makeChange = load_makeChange()
        self.assertEqual(makeChange([1, 2, 5], 0), 0)
        self.assertEqual(makeChange([1, 2, 5], -7), 0)

    def test_large_total_possible(self):
        makeChange = load_makeChange()
        # cas volumineux mais calculable rapidement
        self.assertEqual(makeChange([1, 3, 4], 1000), 250)

    def test_large_total_impossible(self):
        makeChange = load_makeChange()
        # 999998 est pair -> combinaison 4/6 possible ? Ici on utilise [5,7] => 999998 est non atteignable
        self.assertEqual(makeChange([5, 7], 999_998), -1)

    def test_perf_guard(self):
        makeChange = load_makeChange()
        start = time.time()
        res = makeChange([1, 7, 10, 25], 20000)
        elapsed = time.time() - start
        # 25 * 800 = 20000 -> 800 pièces attendues
        self.assertEqual(res, 800)
        # Garde-fou perf: ~0.8s est large pour du CI, ajuste si besoin
        self.assertLess(elapsed, 1.5, "Calcul trop lent (>1.5s)")

    def test_non_canonical(self):
        makeChange = load_makeChange()
        self.assertEqual(makeChange([1, 3, 4], 6), 2)   # 3+3
        self.assertEqual(makeChange([9, 6, 5, 1], 11), 2)  # 6+5

    def test_large_coin_values(self):
        makeChange = load_makeChange()
        # Correction: le minimum est 102 (reste 99 => 99 pièces de 1 au minimum)
        self.assertEqual(makeChange([100, 200, 500, 1], 999), 102)
        self.assertEqual(makeChange([1, 100, 200, 500], 999), 102)


if __name__ == "__main__":
    unittest.main()
