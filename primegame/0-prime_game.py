#!/usr/bin/python3
"""Prime Game - determine the winner over multiple rounds."""


def isWinner(x, nums):
    """
    Determine the winner of the Prime Game.

    Args:
        x (int): number of rounds.
        nums (list): list of n values for each round.

    Returns:
        str or None: name of the player that won the most rounds
        ("Maria" or "Ben"). If there is a tie or input is invalid,
        returns None.
    """
    if x < 1 or not nums or len(nums) == 0:
        return None

    # Limit the sieve to the maximum n in nums
    max_n = max(nums)
    if max_n < 2:
        # No primes in any round, Maria never moves → Ben wins all rounds
        return "Ben"

    # Sieve of Eratosthenes to find primes up to max_n
    primes = [True] * (max_n + 1)
    primes[0] = False
    primes[1] = False

    i = 2
    while i * i <= max_n:
        if primes[i]:
            j = i * i
            while j <= max_n:
                primes[j] = False
                j += i
        i += 1

    # Build prefix sum of prime counts
    prime_count = [0] * (max_n + 1)
    count = 0
    for i in range(2, max_n + 1):
        if primes[i]:
            count += 1
        prime_count[i] = count

    maria_wins = 0
    ben_wins = 0

    # Evaluate each round
    for round_idx in range(x):
        if round_idx >= len(nums):
            break
        n = nums[round_idx]
        if n < 2:
            # No prime → Maria cannot move
            ben_wins += 1
            continue

        moves = prime_count[n]
        if moves % 2 == 1:
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return "Maria"
    if ben_wins > maria_wins:
        return "Ben"
    return None
