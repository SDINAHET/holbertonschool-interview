#!/usr/bin/python3
"""
Unit tests for 0-rotate_2d_matrix.py
Run: python3 -m unittest -v test_rotate_2d_matrix.py
"""
import unittest
import copy

rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix


def rotated_copy_cw(m):
    """Return a new matrix which is m rotated 90° clockwise (copy, not in-place)."""
    n = len(m)
    return [[m[n - 1 - j][i] for j in range(n)] for i in range(n)]


class TestRotate2DMatrix(unittest.TestCase):
    def _check_case(self, original):
        """Helper: checks in-place rotation, same object, expected values."""
        # Make a deep copy to build expected result without mutating original
        orig_copy = copy.deepcopy(original)
        expected = rotated_copy_cw(orig_copy)

        # Keep references to original container to ensure in-place
        matrix = copy.deepcopy(original)
        matrix_id_before = id(matrix)
        rows_id_before = [id(r) for r in matrix]

        ret = rotate_2d_matrix(matrix)

        # Must not return anything
        self.assertIsNone(ret, "Function must not return a value")

        # Same list object (top level)
        self.assertEqual(id(matrix), matrix_id_before, "Matrix object must be the same")

        # Inner row objects should be the same (we only swap elements)
        self.assertEqual([id(r) for r in matrix], rows_id_before,
                         "Row objects must be the same (in-place)")

        # Final content matches expected rotation
        self.assertEqual(matrix, expected, "Matrix content is not rotated correctly")

    def test_3x3(self):
        self._check_case([[1, 2, 3],
                          [4, 5, 6],
                          [7, 8, 9]])

    def test_4x4(self):
        self._check_case([[1, 11, 13, 19],
                          [41, 32, 6, 22],
                          [55, 21, 41, 66],
                          [77, 29, 78, 2]])

    def test_5x5(self):
        self._check_case([[1, 2, 3, 4, 5],
                          [6, 7, 8, 9, 10],
                          [11, 12, 13, 14, 15],
                          [16, 17, 18, 19, 20],
                          [21, 22, 23, 24, 25]])

    def test_2x2(self):
        self._check_case([[5, 6],
                          [7, 8]])

    def test_6x6(self):
        self._check_case([[5, 8, 11, 14, 17, 20],
                          [23, 26, 29, 32, 35, 38],
                          [41, 44, 47, 50, 53, 56],
                          [59, 62, 65, 68, 71, 74],
                          [77, 80, 83, 86, 89, 92],
                          [95, 98, 101, 104, 107, 110]])


if __name__ == "__main__":
    unittest.main()
