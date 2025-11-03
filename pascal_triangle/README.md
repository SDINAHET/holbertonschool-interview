# Pascal's Triangle

## Tasks
0. Pascal's Triangle
mandatory
Create a function def pascal_triangle(n): that returns a list of lists of integers representing the Pascal’s triangle of n:

Returns an empty list if n <= 0
You can assume n will be always an integer
guillaume@ubuntu:~/$ cat 0-main.py
#!/usr/bin/python3
"""
0-main
"""
pascal_triangle = __import__('0-pascal_triangle').pascal_triangle

def print_triangle(triangle):
    """
    Print the triangle
    """
    for row in triangle:
        print("[{}]".format(",".join([str(x) for x in row])))


if __name__ == "__main__":
    print_triangle(pascal_triangle(5))

guillaume@ubuntu:~/$
guillaume@ubuntu:~/$ ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]
guillaume@ubuntu:~/$
Repo:

GitHub repository: holbertonschool-interview
Directory: pascal_triangle
File: 0-pascal_triangle.py

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle# ./0-main.py
[1]
[1,1]
[1,2,1]
[1,3,3,1]
[1,4,6,4,1]



root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle# python3 -m unittest discover tests
FEEEEEEEE
======================================================================
ERROR: test_01_shebang (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 41, in test_01_shebang
    with io.open(SOL_PATH, "r", encoding="utf-8") as f:
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
ERROR: test_02_no_imports (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 48, in test_02_no_imports
    source = SOL_PATH.read_text(encoding="utf-8")
  File "/usr/lib/python3.10/pathlib.py", line 1134, in read_text
    with self.open(mode='r', encoding=encoding, errors=errors) as f:
  File "/usr/lib/python3.10/pathlib.py", line 1119, in open
    return self._accessor.open(self, mode, buffering, encoding, errors,
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
ERROR: test_03_module_and_function_docstrings (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 55, in test_03_module_and_function_docstrings
    source = SOL_PATH.read_text(encoding="utf-8")
  File "/usr/lib/python3.10/pathlib.py", line 1134, in read_text
    with self.open(mode='r', encoding=encoding, errors=errors) as f:
  File "/usr/lib/python3.10/pathlib.py", line 1119, in open
    return self._accessor.open(self, mode, buffering, encoding, errors,
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
ERROR: test_10_correct_output_n5 (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 71, in test_10_correct_output_n5
    mod = load_solution_module()
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 32, in load_solution_module
    spec.loader.exec_module(mod)  # type: ignore[attr-defined]
  File "<frozen importlib._bootstrap_external>", line 879, in exec_module
  File "<frozen importlib._bootstrap_external>", line 1016, in get_code
  File "<frozen importlib._bootstrap_external>", line 1073, in get_data
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
ERROR: test_11_correct_output_n1 (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 83, in test_11_correct_output_n1
    mod = load_solution_module()
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 32, in load_solution_module
    spec.loader.exec_module(mod)  # type: ignore[attr-defined]
  File "<frozen importlib._bootstrap_external>", line 879, in exec_module
  File "<frozen importlib._bootstrap_external>", line 1016, in get_code
  File "<frozen importlib._bootstrap_external>", line 1073, in get_data
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
ERROR: test_12_correct_output_n0 (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 87, in test_12_correct_output_n0
    mod = load_solution_module()
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 32, in load_solution_module
    spec.loader.exec_module(mod)  # type: ignore[attr-defined]
  File "<frozen importlib._bootstrap_external>", line 879, in exec_module
  File "<frozen importlib._bootstrap_external>", line 1016, in get_code
  File "<frozen importlib._bootstrap_external>", line 1073, in get_data
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
ERROR: test_13_correct_output_n10 (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 92, in test_13_correct_output_n10
    mod = load_solution_module()
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 32, in load_solution_module
    spec.loader.exec_module(mod)  # type: ignore[attr-defined]
  File "<frozen importlib._bootstrap_external>", line 879, in exec_module
  File "<frozen importlib._bootstrap_external>", line 1016, in get_code
  File "<frozen importlib._bootstrap_external>", line 1073, in get_data
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
ERROR: test_14_correct_output_n100 (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 106, in test_14_correct_output_n100
    mod = load_solution_module()
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 32, in load_solution_module
    spec.loader.exec_module(mod)  # type: ignore[attr-defined]
  File "<frozen importlib._bootstrap_external>", line 879, in exec_module
  File "<frozen importlib._bootstrap_external>", line 1016, in get_code
  File "<frozen importlib._bootstrap_external>", line 1073, in get_data
FileNotFoundError: [Errno 2] No such file or directory: '/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/pascal_triangle/0-pascal_triangle.py'

======================================================================
FAIL: test_00_file_exists (test_pascal_triangle.TestPascalTriangle)
----------------------------------------------------------------------
Traceback (most recent call last):
  File "/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_triangle/tests/test_pascal_triangle.py", line 38, in test_00_file_exists
    self.assertTrue(SOL_PATH.exists(), "File does not exist")
AssertionError: False is not true : File does not exist

----------------------------------------------------------------------
Ran 9 tests in 0.028s

FAILED (failures=1, errors=8)
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle#



root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle# python3 -m unittest -v tests.test_pascal_triangle
test_pascal_triangle (unittest.loader._FailedTest) ... ERROR

======================================================================
ERROR: test_pascal_triangle (unittest.loader._FailedTest)
----------------------------------------------------------------------
ImportError: Failed to import test module: test_pascal_triangle
Traceback (most recent call last):
  File "/usr/lib/python3.10/unittest/loader.py", line 154, in loadTestsFromName
    module = __import__(module_name)
ModuleNotFoundError: No module named 'tests.test_pascal_triangle'


----------------------------------------------------------------------
Ran 1 test in 0.000s

FAILED (errors=1)
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle# python3 -m unittest discover -s tests -p "test_*.py" -v
test_00_file_exists (test_pascal_triangle.TestPascalTriangle) ... ok
test_01_shebang (test_pascal_triangle.TestPascalTriangle) ... ok
test_02_no_imports (test_pascal_triangle.TestPascalTriangle) ... ok
test_03_module_and_function_docstrings (test_pascal_triangle.TestPascalTriangle) ... ok
test_10_correct_output_n5 (test_pascal_triangle.TestPascalTriangle) ... ok
test_11_correct_output_n1 (test_pascal_triangle.TestPascalTriangle) ... ok
test_12_correct_output_n0 (test_pascal_triangle.TestPascalTriangle) ... ok
test_13_correct_output_n10 (test_pascal_triangle.TestPascalTriangle) ... ok
test_14_correct_output_n100 (test_pascal_triangle.TestPascalTriangle) ... ok

----------------------------------------------------------------------
Ran 9 tests in 0.025s

OK
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle# touch tests/__init__.py
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle# python3 -m unittest -v tests.test_pascal_triangle
test_00_file_exists (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_01_shebang (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_02_no_imports (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_03_module_and_function_docstrings (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_10_correct_output_n5 (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_11_correct_output_n1 (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_12_correct_output_n0 (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_13_correct_output_n10 (tests.test_pascal_triangle.TestPascalTriangle) ... ok
test_14_correct_output_n100 (tests.test_pascal_triangle.TestPascalTriangle) ... ok

----------------------------------------------------------------------
Ran 9 tests in 0.465s

OK
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/pascal_tr
iangle#


```
