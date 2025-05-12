#!/usr/bin/python3
"""Script that parses logs from stdin and computes metrics."""

import sys


# Initialize total file size and status code counters
total_size = 0
status_counts = {}
# Allowed HTTP status codes
valid_statuses = ['200', '301', '400', '401', '403', '404', '405', '500']
# Line counter to know when to print stats
line_count = 0


def print_stats():
    """
    Prints the collected metrics:
    - Total file size
    - Status code occurrences in ascending order
    """
    print("File size: {}".format(total_size))
    for status in sorted(status_counts.keys()):
        print("{}: {}".format(status, status_counts[status]))


try:
    # Read each line from stdin
    for line in sys.stdin:
        line_count += 1
        try:
            # Split line by whitespace
            parts = line.strip().split()
            # Extract status code and file size if format is valid
            if len(parts) >= 7:
                status = parts[-2]
                size = int(parts[-1])
                total_size += size
                # Count status codes if valid
                if status in valid_statuses:
                    status_counts[status] = status_counts.get(status, 0) + 1
        except (ValueError, IndexError):
            # Ignore malformed lines
            pass

        # Print stats every 10 lines
        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    # On keyboard interrupt, print stats before exiting
    print_stats()
    raise

# Print stats after reading all input
print_stats()
