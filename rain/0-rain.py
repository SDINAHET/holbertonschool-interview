#!/usr/bin/python3
"""
Module to calculate the total amount of rainwater retained
after it rains, given the elevation map (walls).
"""


def rain(walls):
    """
    Calculate how much water is retained after it rains.

    Args:
        walls (list): List of non-negative integers representing wall heights.

    Returns:
        int: Total units of water retained.
    """
    if not walls or len(walls) < 3:
        return 0

    n = len(walls)
    left = 0
    right = n - 1
    left_max = right_max = 0
    water = 0

    while left < right:
        if walls[left] < walls[right]:
            if walls[left] >= left_max:
                left_max = walls[left]
            else:
                water += left_max - walls[left]
            left += 1
        else:
            if walls[right] >= right_max:
                right_max = walls[right]
            else:
                water += right_max - walls[right]
            right -= 1

    return water
