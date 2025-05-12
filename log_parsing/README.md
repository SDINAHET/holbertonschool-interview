# 0x03. Log Parsing

## Description

This project is about writing a Python script that reads `stdin` line by line and computes specific metrics:

* Total file size
* Number of occurrences for each status code (200, 301, 400, 401, 403, 404, 405, and 500)

The script prints the statistics every 10 lines and upon receiving a keyboard interruption (`CTRL + C`).

## Files

* `0-stats.py` - Main script that reads from standard input and computes metrics.

## Usage

```bash
$ ./0-generator.py | ./0-stats.py
```

## Input Format

Lines are expected in the following format:

```
<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>
```

Invalid lines are silently ignored.

## Example Output

```
File size: 5213
200: 2
401: 1
403: 2
404: 1
405: 1
500: 3
```

## Script Explanation

### Header

```python
#!/usr/bin/python3
"""Script that parses logs from stdin and computes metrics."""
```

* Shebang line ensures execution with Python 3.
* Module docstring is required by Holberton checker.

### Function: `print_stats()`

Prints:

* Total file size
* Status codes (if present), in ascending order

### Main Execution Block

```python
if __name__ == "__main__":
```

* Ensures the script does not auto-execute on import
* Prevents checker timeout on import test

### Input Reading & Parsing

* Reads from `stdin` line by line
* Validates format: at least 7 parts
* Extracts status code and file size

### Metrics Handling

* Only valid codes (200, 301, etc.) are counted
* File size is accumulated
* Stats are printed every 10 lines and on CTRL+C

### Final Print

* At end of input or interruption

## Requirements

* Python 3.4+
* PEP8 compliant (`pycodestyle`)
* Ubuntu 14.04 compatibility

## Author

Written by **Alexa Orrico**, Software Engineer at Holberton School.
