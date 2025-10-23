#!/usr/bin/python3
"""
Unittest suite for island_perimeter using Python's unittest.
Compatible with Python 3.4+.
"""
import os
import sys
import unittest
import importlib.util


def _load_func():
    """Load island_perimeter from 0-island_perimeter.py regardless of hyphen."""
    here = os.path.dirname(os.path.abspath(__file__))
    module_path = os.path.abspath(os.path.join(here, '..', '0-island_perimeter.py'))
    spec = importlib.util.spec_from_file_location('island_module', module_path)
    mod = importlib.util.module_from_spec(spec)
    # Ensure module can import relative if ever needed (it won't here)
    sys.modules['island_module'] = mod
    spec.loader.exec_module(mod)
    return getattr(mod, 'island_perimeter')


ISLAND_PERIMETER = _load_func()


class TestIslandPerimeter(unittest.TestCase):
    """Test cases for island_perimeter."""

    def test_sample_from_project(self):
        grid = [
            [0, 0, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0],
            [0, 1, 0, 0, 0, 0],
            [0, 1, 1, 1, 0, 0],
            [0, 0, 0, 0, 0, 0]
        ]
        self.assertEqual(ISLAND_PERIMETER(grid), 12)

    def test_empty(self):
        self.assertEqual(ISLAND_PERIMETER([]), 0)

    def test_all_water(self):
        grid = [[0, 0], [0, 0]]
        self.assertEqual(ISLAND_PERIMETER(grid), 0)

    def test_single_cell(self):
        grid = [[1]]
        self.assertEqual(ISLAND_PERIMETER(grid), 4)

    def test_line_vertical(self):
        grid = [
            [0, 1, 0],
            [0, 1, 0],
            [0, 1, 0],
        ]
        self.assertEqual(ISLAND_PERIMETER(grid), 8)

    def test_rectangle(self):
        grid = [
            [0, 0, 0, 0, 0],
            [0, 1, 1, 1, 0],
            [0, 1, 1, 1, 0],
            [0, 0, 0, 0, 0]
        ]
        # 2x3 block => perimeter 2*(2+3)=10, but surrounded by water padding
        self.assertEqual(ISLAND_PERIMETER(grid), 10)


if __name__ == '__main__':
    unittest.main()
