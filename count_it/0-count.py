#!/usr/bin/python3
"""
Recursive Reddit hot titles keyword counter.

- Uses Reddit public API without following redirects.
- Counts occurrences of exact space-delimited tokens (case-insensitive).
- Handles duplicates in word_list by summing their weights.
- Prints results sorted by descending count, then alphabetically.
- Prints nothing for invalid subreddit or when all counts are zero.
"""

import requests


def count_words(
    subreddit,
    word_list,
    after=None,
    base_counts=None,
    weights=None
        ):
    """
    Queries the Reddit API recursively and prints a sorted count of given
    keywords.

    Args:
        subreddit (str): subreddit name (e.g. "programming")
        word_list (list): list of keywords (strings)
        after (str): pagination token (used internally for recursion)
        base_counts (dict): counts per unique word (used internally)
        weights (dict): multiplicity of each word in the input (used
        internally)
    """

    # Initialize on first call
    if base_counts is None or weights is None:
        # Normalize to lowercase and build weight map for duplicates
        weights = {}
        for w in word_list or []:
            lw = w.lower()
            if lw in weights:
                weights[lw] += 1
            else:
                weights[lw] = 1

        # Base counts for unique words (all start at 0)
        base_counts = dict((w, 0) for w in weights.keys())

    # If subreddit missing, nothing to do
    if not subreddit:
        _final_print(base_counts, weights)
        return

    # Build request
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {"User-Agent": "holberton_count_it/1.0"}
    params = {"limit": 100}
    if after:
        params["after"] = after

    try:
        resp = requests.get(
            url,
            headers=headers,
            params=params,
            allow_redirects=False,
            timeout=10
        )
    except Exception:
        # On network error, behave like invalid subreddit per spec: print
        # nothing
        return

    # Invalid subreddit often returns 302 redirect or non-200
    if resp.status_code != 200:
        return

    payload = resp.json()
    data = payload.get("data")
    if not data:
        # No data: finish
        _final_print(base_counts, weights)
        return

    children = data.get("children") or []
    # Count words in each title (exact token matches only; punctuation
    # attached ≠ match)
    for child in children:
        post = child.get("data") or {}
        title = post.get("title") or ""
        tokens = [t.lower() for t in title.split()]
        if not tokens:
            continue

        # For each unique tracked word, count exact token matches in this title
        # (Exact token match ensures "java" does NOT match "javascript" or
        # "java.")
        for w in base_counts.keys():
            # Count occurrences of the exact token in this title
            c = 0
            for t in tokens:
                if t == w:
                    c += 1
            if c:
                base_counts[w] += c

    # Recurse to next page if present
    next_after = data.get("after")
    if next_after:
        count_words(subreddit, word_list, after=next_after,
                    base_counts=base_counts, weights=weights)
        return

    # No more pages: print final result
    _final_print(base_counts, weights)


def _final_print(base_counts, weights):
    """
    Combine base counts with input weights (for duplicates) and print as
    required.
    """
    # Apply weights (duplicate words in input multiply the counts)
    results = []
    for w in base_counts.keys():
        total = base_counts[w] * (weights.get(w, 0) or 0)
        if total > 0:
            results.append((w, total))

    if not results:
        # Print nothing if no matches
        return

    # Sort: descending by count, then alphabetically ascending
    results.sort(key=lambda x: (-x[1], x[0]))

    for w, c in results:
        # Words must be printed in lowercase
        print("{}: {}".format(w, c))
