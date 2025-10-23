# island_perimeter

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/island_perimeter# ./0-main.py
12
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/island_perimeter#
```

test unittest
```bash
python3 -m unittest tests.test_island_perimeter_unittest
# ou en verbeux
python3 -m unittest -v tests.test_island_perimeter_unittest
```

```bash
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/island_perimeter# python3 -m unittest tests.test_island_perimeter_unittest
# ou en verbeux
python3 -m unittest -v tests.test_island_perimeter_unittest
......
----------------------------------------------------------------------
Ran 6 tests in 0.001s

OK
test_all_water (tests.test_island_perimeter_unittest.TestIslandPerimeter) ... ok
test_empty (tests.test_island_perimeter_unittest.TestIslandPerimeter) ... ok
test_line_vertical (tests.test_island_perimeter_unittest.TestIslandPerimeter) ... ok
test_rectangle (tests.test_island_perimeter_unittest.TestIslandPerimeter) ... ok
test_sample_from_project (tests.test_island_perimeter_unittest.TestIslandPerimeter) ... ok
test_single_cell (tests.test_island_perimeter_unittest.TestIslandPerimeter) ... ok

----------------------------------------------------------------------
Ran 6 tests in 0.001s

OK
```

test pytest
```bash
pytest -q tests/test_island_perimeter_pytest.py
```

```bash
pytest -q tests
pytest -v tests

...........                                                                                                     [100%]
11 passed in 0.11s
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/island_perimeter# pytest -v tests
================================================= test session starts =================================================
platform linux -- Python 3.10.12, pytest-7.3.1, pluggy-1.5.0 -- /usr/bin/python3
cachedir: .pytest_cache
rootdir: /mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/island_perimeter
plugins: flask-1.2.0, allure-pytest-2.10.0, mock-3.11.1, cov-4.1.0, anyio-4.8.0
collected 11 items

tests/test_island_perimeter_pytest.py::test_project_sample PASSED                                               [  9%]
tests/test_island_perimeter_pytest.py::test_empty PASSED                                                        [ 18%]
tests/test_island_perimeter_pytest.py::test_all_water PASSED                                                    [ 27%]
tests/test_island_perimeter_pytest.py::test_single_cell PASSED                                                  [ 36%]
tests/test_island_perimeter_pytest.py::test_L_shape PASSED                                                      [ 45%]
tests/test_island_perimeter_unittest.py::TestIslandPerimeter::test_all_water PASSED                             [ 54%]
tests/test_island_perimeter_unittest.py::TestIslandPerimeter::test_empty PASSED                                 [ 63%]
tests/test_island_perimeter_unittest.py::TestIslandPerimeter::test_line_vertical PASSED                         [ 72%]
tests/test_island_perimeter_unittest.py::TestIslandPerimeter::test_rectangle PASSED                             [ 81%]
tests/test_island_perimeter_unittest.py::TestIslandPerimeter::test_sample_from_project PASSED                   [ 90%]
tests/test_island_perimeter_unittest.py::TestIslandPerimeter::test_single_cell PASSED                           [100%]

================================================= 11 passed in 0.14s ==================================================
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool-interview/island_perimeter#
```
