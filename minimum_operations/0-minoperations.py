#!/usr/bin/python3
"""
Calculates the fewest number of operations needed
to result in exactly n H characters using only
Copy All and Paste operations.
"""


def minOperations(n):
    """
    Returns the minimum number of operations
    needed to get exactly n Hs in a file.
    """
    if n < 2:
        return 0

    operations = 0
    factor = 2

    while n > 1:
        while n % factor == 0:
            operations += factor
            n //= factor
        factor += 1

    return operations
