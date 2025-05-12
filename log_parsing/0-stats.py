#!/usr/bin/python3
"""Script that parses logs from stdin and computes metrics."""

import sys


def print_stats(total_size, status_counts):
    """
    Prints the collected metrics:
    - Total file size
    - Status code occurrences in ascending order
    """
    print("File size: {}".format(total_size))
    for status in sorted(status_counts.keys()):
        print("{}: {}".format(status, status_counts[status]))


if __name__ == "__main__":
    total_size = 0
    status_counts = {}
    valid_statuses = ['200', '301', '400', '401', '403', '404', '405', '500']
    line_count = 0

    try:
        for line in sys.stdin:
            line_count += 1
            try:
                parts = line.strip().split()
                if len(parts) >= 7:
                    status = parts[-2]
                    size = int(parts[-1])
                    total_size += size
                    if status in valid_statuses:
                        status_counts[status] = status_counts.get(status, 0
                                                                  ) + 1
            except (ValueError, IndexError):
                pass

            if line_count % 10 == 0:
                print_stats(total_size, status_counts)

    except KeyboardInterrupt:
        print_stats(total_size, status_counts)
        raise

    print_stats(total_size, status_counts)
