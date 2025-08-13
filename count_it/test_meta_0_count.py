#!/usr/bin/python3
import os
import re
import unittest

HERE = os.path.dirname(os.path.abspath(__file__))
F = os.path.join(HERE, "0-count.py")
R = os.path.join(HERE, "README.md")

class TestMeta(unittest.TestCase):
    def test_file_exists(self):
        self.assertTrue(os.path.isfile(F))

    def test_first_line_shebang(self):
        with open(F, 'r') as fd:
            self.assertTrue(fd.readline().startswith('#!/usr/bin/python3'))

    def test_imports_alpha_order(self):
        imports = []
        with open(F, 'r') as fd:
            for line in fd:
                if line.startswith('import ') or line.startswith('from '):
                    imports.append(line.strip())
        self.assertEqual(imports, sorted(imports))

    def test_readme_exists(self):
        self.assertTrue(os.path.isfile(R))

if __name__ == "__main__":
    unittest.main(verbosity=2)
