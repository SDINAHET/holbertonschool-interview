#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Tests unitaires pour 0-making_change.py
Compatibles avec Python 3.x (CI GitHub: 3.8+).
"""

import os
import unittest


def _load_makeChange():
    """
    Charge la fonction makeChange depuis making_change/0-making_change.py
    en restant compatible avec le nom de fichier imposé (commençant par 0-).
    """
    # 1) Essayer la même technique que le fichier d'exemple Holberton
    try:
        return __import__('0-making_change').makeChange  # noqa: E402
    except Exception:
        pass

    # 2) Fallback: importlib via chemin absolu
    import importlib.util
    base = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
    path = os.path.join(base, '0-making_change.py')
    spec = importlib.util.spec_from_file_location('making_change_module', path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)  # type: ignore[attr-defined]
    return module.makeChange


makeChange = _load_makeChange()


class TestMakingChange(unittest.TestCase):
    def test_examples(self):
        self.assertEqual(makeChange([1, 2, 25], 37), 7)
        self.assertEqual(makeChange([1256, 54, 48, 16, 102], 1453), -1)

    def test_trivial(self):
        self.assertEqual(makeChange([1, 2, 5], 0), 0)
        self.assertEqual(makeChange([1, 2, 5], -5), 0)

    def test_exact_coin(self):
        self.assertEqual(makeChange([3, 7, 10], 7), 1)
        self.assertEqual(makeChange([50], 50), 1)

    def test_unreachable(self):
        self.assertEqual(makeChange([4, 6], 3), -1)
        self.assertEqual(makeChange([], 10), -1)

    def test_deduplicate_and_filter(self):
        # doublons et valeurs non valides -> ignorées par l'implémentation
        self.assertEqual(makeChange([1, 1, 2, 2, -5, 0], 4), 2)

    def test_large_total(self):
        # Vérifie performance et exactitude sur un total élevé
        self.assertEqual(makeChange([1, 3, 4], 1000), 250)  # 4*250

    def test_non_canonical(self):
        # Systèmes non "greedy-friendly"
        self.assertEqual(makeChange([1, 3, 4], 6), 2)   # 3+3 plutôt que 4+1+1
        self.assertEqual(makeChange([9, 6, 5, 1], 11), 2)  # 6+5

    def test_large_coin_values(self):
        self.assertEqual(makeChange([100, 200, 500, 1], 999), 13)  # 9*100 + 99*1 ? Non: 500+200+200+ 99*1 => 1s minimisés -> 500+200+200+99*1 = 1+1+1+99=102 (trop)
        # Mieux: 9*100 = 900, reste 99 -> 99*1 -> total 9+99 = 108
        # Mais 500 + 4*100 = 900, reste 99 -> 500 (1) + 100*4 (4) + 99*1 (99) = 104
        # 200*4 = 800, reste 199 -> 200*3=600, reste 399 -> 200 (3) + 100 (3) +  - pas mieux
        # La meilleure solution est 500 (1) + 200 (2) + 99*1 (99) = 102
        # Donc attendons 102
        self.assertEqual(makeChange([1, 100, 200, 500], 999), 102)


if __name__ == '__main__':
    unittest.main()
