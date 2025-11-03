#!/usr/bin/python3
"""
Unit tests for 0-pascal_triangle.py

Checks:
- File exists
- First line shebang #!/usr/bin/python3
- No imports in the solution file
- Module is documented
- Function is documented
- Correct outputs for n = 5, 1, 0, 10, 100
- PEP8 validation will be handled by CI (pycodestyle)
"""
import os
import io
import ast
import math
import unittest
import importlib.util
from pathlib import Path


ROOT = Path(__file__).resolve().parent.parent
SOL_PATH = ROOT / "0-pascal_triangle.py"
MODULE_NAME = "pascal_triangle_module"


def load_solution_module():
    """Load the student's module from file path without regular import."""
    spec = importlib.util.spec_from_file_location(MODULE_NAME, SOL_PATH)
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)  # type: ignore[attr-defined]
    return mod


class TestPascalTriangle(unittest.TestCase):
    def test_00_file_exists(self):
        self.assertTrue(SOL_PATH.exists(), "File does not exist")

    def test_01_shebang(self):
        with io.open(SOL_PATH, "r", encoding="utf-8") as f:
            first = f.readline().rstrip("\n")
        self.assertEqual(first, "#!/usr/bin/python3",
                         "First line must be #!/usr/bin/python3")

    def test_02_no_imports(self):
        # Parse AST and ensure no Import / ImportFrom nodes exist
        source = SOL_PATH.read_text(encoding="utf-8")
        tree = ast.parse(source)
        for node in ast.walk(tree):
            self.assertFalse(isinstance(node, (ast.Import, ast.ImportFrom)),
                             "No 'import' statements allowed in solution file")

    def test_03_module_and_function_docstrings(self):
        source = SOL_PATH.read_text(encoding="utf-8")
        tree = ast.parse(source)
        self.assertIsNotNone(ast.get_docstring(tree),
                             "Module must be documented")
        # Find function pascal_triangle
        funcs = [n for n in tree.body if isinstance(n, ast.FunctionDef)]
        target = None
        for f in funcs:
            if f.name == "pascal_triangle":
                target = f
                break
        self.assertIsNotNone(target, "Function 'pascal_triangle' not found")
        self.assertIsNotNone(ast.get_docstring(target),
                             "Function 'pascal_triangle' must be documented")

    def test_10_correct_output_n5(self):
        mod = load_solution_module()
        res = mod.pascal_triangle(5)
        expected = [
            [1],
            [1, 1],
            [1, 2, 1],
            [1, 3, 3, 1],
            [1, 4, 6, 4, 1],
        ]
        self.assertEqual(res, expected, "Incorrect output for n = 5")

    def test_11_correct_output_n1(self):
        mod = load_solution_module()
        self.assertEqual(mod.pascal_triangle(1), [[1]], "Incorrect n=1")

    def test_12_correct_output_n0(self):
        mod = load_solution_module()
        self.assertEqual(mod.pascal_triangle(0), [], "Incorrect n=0")
        self.assertEqual(mod.pascal_triangle(-3), [], "Incorrect n<=0")

    def test_13_correct_output_n10(self):
        mod = load_solution_module()
        tri = mod.pascal_triangle(10)
        self.assertEqual(len(tri), 10, "Triangle must have 10 rows")
        # Check a few known rows
        self.assertEqual(tri[0], [1])
        self.assertEqual(tri[1], [1, 1])
        self.assertEqual(tri[2], [1, 2, 1])
        self.assertEqual(tri[4], [1, 4, 6, 4, 1])  # row index 4 (n=5)
        # Check last row values via binomial coefficients
        last = tri[-1]  # row index 9 (n=10)
        expected_last = [math.comb(9, k) for k in range(10)]
        self.assertEqual(last, expected_last, "Incorrect last row for n=10")

    def test_14_correct_output_n100(self):
        mod = load_solution_module()
        tri = mod.pascal_triangle(100)
        self.assertEqual(len(tri), 100, "Triangle must have 100 rows")

        # Basic structure checks
        self.assertEqual(tri[0], [1])
        self.assertEqual(tri[1], [1, 1])
        self.assertTrue(all(r[0] == 1 and r[-1] == 1 for r in tri),
                        "Each row must start/end with 1")

        # Spot check some binomial values in the last row (index 99)
        last = tri[-1]
        self.assertEqual(len(last), 100)
        # Middle values against math.comb (C(99,k))
        checks = [0, 1, 2, 50, 97, 98, 99]
        for k in checks:
            self.assertEqual(last[k], math.comb(99, k),
                             f"Incorrect value C(99,{k}) in last row")

        # Symmetry
        for k in range(50):
            self.assertEqual(last[k], last[-1 - k], "Row must be symmetric")

        # All positive integers
        self.assertTrue(all(isinstance(x, int) and x > 0
                            for row in tri for x in row),
                        "All coefficients must be positive integers")


if __name__ == "__main__":
    unittest.main(verbosity=2)
