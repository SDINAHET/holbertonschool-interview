#!/usr/bin/python3
"""Solves the N-Queens problem using backtracking."""
import sys


def is_safe(queen, queens):
    """Check if a queen can be placed at this position."""
    for row, col in enumerate(queens):
        if col == queen or \
           col - row == queen - len(queens) or \
           col + row == queen + len(queens):
            return False
    return True


def solve(n, queens=[]):
    """Recursively solve the N-Queens problem."""
    if len(queens) == n:
        print([[i, q] for i, q in enumerate(queens)])
        return
    for i in range(n):
        if is_safe(i, queens):
            solve(n, queens + [i])


def validate_args():
    """Validates command-line arguments."""
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)
    try:
        n = int(sys.argv[1])
    except ValueError:
        print("N must be a number")
        sys.exit(1)
    if n < 4:
        print("N must be at least 4")
        sys.exit(1)
    return n


if __name__ == "__main__":
    n = validate_args()
    solve(n)
