#!/usr/bin/python3
"""
More tests - Rotate 2D Matrix
"""
rotate_2d_matrix = __import__('0-rotate_2d_matrix').rotate_2d_matrix

def show(m):
    for r in m:
        print(r)
    print()

if __name__ == "__main__":
    cases = [
        [[1]],  # 1x1
        [[1, 2],
         [3, 4]],  # 2x2
        [[1, 2, 3, 4],
         [5, 6, 7, 8],
         [9, 10, 11, 12],
         [13, 14, 15, 16]],  # 4x4
        [[-1, -2, -3],
         [-4, -5, -6],
         [-7, -8, -9]],  # valeurs négatives
    ]

    for m in cases:
        rotate_2d_matrix(m)
        show(m)
