#!/usr/bin/python3
"""
Module to determine if all boxes can be opened.
"""

def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    :param boxes: List of lists containing keys for each box
    :return: True if all boxes can be opened, else False
    """
    if not isinstance(boxes, list) or not boxes:
        return False

    n = len(boxes)
    opened = set([0])  # Start with box 0 opened
    keys = set(boxes[0])  # Keys from box 0

    while keys:
        key = keys.pop()
        if 0 <= key < n and key not in opened:
            opened.add(key)
            keys.update(boxes[key])

    return len(opened) == n
