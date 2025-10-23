#!/usr/bin/python3
"""
Compute the perimeter of an island in a rectangular grid.

The grid is a list of lists of integers:
- 0 = water
- 1 = land
Cells are squares of side length 1 and only connect 4-directionally.

No imports are used, code is PEP 8 compliant, and fully documented.
"""


def island_perimeter(grid):
    """
    Return the perimeter of the island described in `grid`.

    Args:
        grid (list[list[int]]): Rectangular 2D grid of 0s (water) and 1s (land)

    Returns:
        int: The perimeter length.

    Notes:
        - Only one island or nothing exists.
        - Cells connect 4-directionally (no diagonals).
        - Grid is completely surrounded by water (per project spec).
    """
    if not grid or not isinstance(grid, list):
        return 0

    rows = len(grid)
    cols = len(grid[0]) if rows > 0 and isinstance(grid[0], list) else 0

    perim = 0

    r = 0
    while r < rows:
        row = grid[r]
        c = 0
        while c < cols:
            if row[c] == 1:
                # Start with 4 sides for a lone cell
                perim += 4

                # Subtract sides shared with an upper neighbor
                if r > 0 and grid[r - 1][c] == 1:
                    perim -= 2  # shared edge counted twice otherwise

                # Subtract sides shared with a left neighbor
                if c > 0 and row[c - 1] == 1:
                    perim -= 2
            c += 1
        r += 1

    return perim
