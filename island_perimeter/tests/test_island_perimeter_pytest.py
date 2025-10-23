#!/usr/bin/python3
"""
Pytest suite for island_perimeter.
Run with: pytest -q
"""
import os
import sys
import importlib.util


def _load_func():
    """Load island_perimeter from 0-island_perimeter.py regardless of hyphen."""
    here = os.path.dirname(os.path.abspath(__file__))
    module_path = os.path.abspath(os.path.join(here, '..', '0-island_perimeter.py'))
    spec = importlib.util.spec_from_file_location('island_module', module_path)
    mod = importlib.util.module_from_spec(spec)
    sys.modules['island_module'] = mod
    spec.loader.exec_module(mod)
    return getattr(mod, 'island_perimeter')


island_perimeter = _load_func()


def test_project_sample():
    grid = [
        [0, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 1, 1, 1, 0, 0],
        [0, 0, 0, 0, 0, 0]
    ]
    assert island_perimeter(grid) == 12


def test_empty():
    assert island_perimeter([]) == 0


def test_all_water():
    assert island_perimeter([[0, 0], [0, 0]]) == 0


def test_single_cell():
    assert island_perimeter([[1]]) == 4


def test_L_shape():
    grid = [
        [1, 0, 0],
        [1, 1, 1],
        [0, 0, 0],
    ]
    # Manual count: cells=4 -> 16 sides, shared edges: (0,0)-(1,0); (1,0)-(1,1); (1,1)-(1,2) => 3 shared => -6
    assert island_perimeter(grid) == 10
