#!/usr/bin/python3
"""
Checker-like tests:
- Fichier présent, shebang exact
- Pas d'import
- Docstrings module et fonction
- Jeux de grilles supplémentaires (ceux du checker)
"""
import os
import re
import unittest
import importlib.util


def _module_path():
    here = os.path.dirname(os.path.abspath(__file__))
    return os.path.abspath(os.path.join(here, '..', '0-island_perimeter.py'))


def _load_func():
    p = _module_path()
    spec = importlib.util.spec_from_file_location('island_module', p)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod, getattr(mod, 'island_perimeter')


class TestCheckerLike(unittest.TestCase):
    def test_file_exists(self):
        self.assertTrue(os.path.isfile(_module_path()))

    def test_shebang_exact(self):
        with open(_module_path(), 'r') as f:
            first = f.readline().rstrip('\n')
        self.assertEqual(first, '#!/usr/bin/python3')

    def test_no_imports(self):
        with open(_module_path(), 'r') as f:
            src = f.read()
        self.assertIsNone(re.search(r'^\s*(from|import)\s+', src, re.M),
                          msg="No imports allowed in 0-island_perimeter.py")

    def test_docstrings(self):
        mod, func = _load_func()
        self.assertTrue((mod.__doc__ or '').strip(), "Module must have docstring")
        self.assertTrue(callable(func), "Function island_perimeter missing")
        self.assertTrue((func.__doc__ or '').strip(), "Function must have docstring")

    def test_grids_from_checker(self):
        _, island_perimeter = _load_func()

        cases = [
            # Sample 1
            (
                [[0,0,0,0,0,0],
                 [0,1,0,0,0,0],
                 [0,1,0,0,0,0],
                 [0,1,1,1,0,0],
                 [0,0,0,0,0,0]],
                12
            ),
            # Single column of water
            ([[0],[0],[0]], 0),
            # Full 3x5 of land
            (
                [[1,1,1,1,1],
                 [1,1,1,1,1],
                 [1,1,1,1,1]],
                16  # 2 * (3 + 5)
            ),
            # Combinaisons
            (
                [[0,0,0,0,0,0],
                 [0,1,1,0,0,0],
                 [1,1,1,0,0,0],
                 [0,1,1,1,0,0],
                 [0,0,0,1,1,1]],
                20  # corrigé
            ),
            (
                [[0,1,0,0,0,1],
                 [1,1,0,0,0,1],
                 [1,1,0,1,1,1],
                 [0,1,1,1,0,0],
                 [0,0,1,1,0,0]],
                28  # corrigé
            ),
            # Autres de ton message
            (
                [[0,0,0,0,0,0],
                 [0,1,0,0,0,0],
                 [0,0,0,0,0,0]],
                4
            ),
            (
                [[0,0,0,0,0,0],
                 [0,1,1,1,0,0],
                 [0,1,1,1,0,0],
                 [0,1,1,1,0,0]],
                12  # 3x3 block, corrigé
            ),
        ]

        for grid, expected in cases:
            self.assertEqual(
                island_perimeter(grid), expected,
                msg="Bad perimeter for grid: {}".format(grid)
            )


if __name__ == '__main__':
    unittest.main()
