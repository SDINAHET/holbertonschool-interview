#!/usr/bin/python3
"""Generate Pascal's triangle up to n rows."""


def pascal_triangle(n):
    """
    Return a list of lists of integers representing Pascal’s triangle of n.

    Args:
        n (int): Number of rows to generate.

    Returns:
        list[list[int]]: The triangle as a list of rows.
                         Returns [] if n <= 0.
    """
    if n <= 0:
        return []

    triangle = [[1]]
    for _ in range(1, n):
        prev = triangle[-1]
        # Middle values are sums of adjacent pairs from the previous row
        middle = [prev[i - 1] + prev[i] for i in range(1, len(prev))]
        triangle.append([1] + middle + [1])

    return triangle
