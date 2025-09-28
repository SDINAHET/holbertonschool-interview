#!/usr/bin/python3
"""
0-making_change.py

Determine the fewest number of coins needed to meet a given amount total.
Compatible with Python 3.4.3 (Ubuntu 14.04) and PEP 8 (1.7.x).
"""


def makeChange(coins, total):
    """
    Returns the minimum number of coins needed to make `total` using
    unlimited coins from the denominations in `coins`.

    Args:
        coins (list): List of positive integer coin values.
        total (int): Target amount.

    Returns:
        int: Fewest number of coins needed to meet `total`,
             0 if total <= 0,
             -1 if total cannot be formed.
    """
    # Trivial cases
    if total <= 0:
        return 0
    if not coins:
        return -1

    # Filter invalid entries (safety) and deduplicate
    coins = [c for c in set(coins) if isinstance(c, int) and c > 0]
    if not coins:
        return -1

    # If a coin equals total, answer is 1
    if total in coins:
        return 1

    # DP array where dp[t] = min coins to make amount t
    # Initialize with a sentinel larger than any possible solution
    INF = total + 1
    dp = [0] + [INF] * total

    # Compute bottom-up
    for c in coins:
        # For unbounded knapsack, iterate forward so each coin can be reused
        for t in range(c, total + 1):
            # If we can make (t - c), try using coin c to improve dp[t]
            if dp[t - c] + 1 < dp[t]:
                dp[t] = dp[t - c] + 1

    return dp[total] if dp[total] != INF else -1
