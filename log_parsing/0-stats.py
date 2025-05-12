#!/usr/bin/python3
"""Log parsing script"""
import sys
import signal

# Track total file size and count of status codes
total_size = 0
status_counts = {}
valid_statuses = ['200', '301', '400', '401', '403', '404', '405', '500']
line_count = 0


def print_stats():
    """Print accumulated statistics"""
    print("File size: {}".format(total_size))
    for status in sorted(status_counts.keys()):
        print("{}: {}".format(status, status_counts[status]))


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
                    status_counts[status] = status_counts.get(status, 0) + 1
        except (ValueError, IndexError):
            pass

        if line_count % 10 == 0:
            print_stats()

except KeyboardInterrupt:
    print_stats()
    raise

# Final print after stdin ends
print_stats()
