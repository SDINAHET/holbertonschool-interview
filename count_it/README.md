root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it# python3 0-main.py programming 'react python java javascript scala no_results_for_this_one'
python: 18
java: 15
javascript: 4
react: 2
scala: 1
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it#  python3 0-main.py programming 'JavA java'
java: 54
java: 30
Command 'java:' not found, but there are 22 similar ones.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it# python3 0-main.py not_a_valid_subreddit 'python java javascript scala no_results_for_this_one'
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it# python3 0-main.py not_a_valid_subreddit 'python java'
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it#




root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it# make pep8
make test
pycodestyle   0-count.py test_unit_0_count.py test_integration_0_count.py test_meta_0_count.py
test_unit_0_count.py:88:80: E501 line too long (93 > 79 characters)
test_unit_0_count.py:101:80: E501 line too long (80 > 79 characters)
test_meta_0_count.py:10:1: E302 expected 2 blank lines, found 1
test_meta_0_count.py:29:1: E305 expected 2 blank lines after class or function definition, found 1
make: *** [Makefile:8: pep8] Error 1
python3 -m unittest -v
test_invalid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Invalid subreddit, list 1 (prints nothing). ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_case_insensitive (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, case insensitive check. ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_duplicates_in_list (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, duplicate items in list. ... ok
test_valid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid Subreddit, list 1 (with pagination). ... ok
test_file_exists (test_meta_0_count.TestMeta) ... ok
test_first_line_shebang (test_meta_0_count.TestMeta) ... ok
test_imports_alpha_order (test_meta_0_count.TestMeta) ... ok
test_readme_exists (test_meta_0_count.TestMeta) ... ok
test_case_insensitive_keywords_and_duplicates (test_unit_0_count.TestCountWordsUnit)
'JavA' and 'java' in word_list -> multiplicity 2, so counts are doubled. ... ok
test_exact_tokens_punctuation_ignored (test_unit_0_count.TestCountWordsUnit)
Ensure 'java.' / 'java!' / 'java_' DO NOT count as 'java'. ... ok
test_invalid_subreddit_status_302 (test_unit_0_count.TestCountWordsUnit)
If subreddit invalid -> 302/404 etc., print nothing. ... ok
test_no_matches_prints_nothing (test_unit_0_count.TestCountWordsUnit)
If no keyword occurrences -> print nothing. ... ok
test_recursion_across_pages (test_unit_0_count.TestCountWordsUnit)
Ensure we follow 'after' and aggregate counts across pages (recursive). ... ok

----------------------------------------------------------------------
Ran 13 tests in 0.273s

OK
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it#








root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it# make        # lance pep8 puis les tests
make pep8   # seulement PEP8
make test   # seulement tests
pycodestyle 0-count.py
python3 -m unittest -v
test_invalid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Invalid subreddit, list 1 (prints nothing). ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_case_insensitive (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, case insensitive check. ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_duplicates_in_list (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, duplicate items in list. ... ok
test_valid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid Subreddit, list 1 (with pagination). ... ok
test_file_exists (test_meta_0_count.TestMeta) ... ok
test_first_line_shebang (test_meta_0_count.TestMeta) ... ok
test_imports_alpha_order (test_meta_0_count.TestMeta) ... ok
test_readme_exists (test_meta_0_count.TestMeta) ... ok
test_case_insensitive_keywords_and_duplicates (test_unit_0_count.TestCountWordsUnit)
'JavA' and 'java' in word_list -> multiplicity 2, so counts are doubled. ... ok
test_exact_tokens_punctuation_ignored (test_unit_0_count.TestCountWordsUnit)
Ensure 'java.' / 'java!' / 'java_' DO NOT count as 'java'. ... ok
test_invalid_subreddit_status_302 (test_unit_0_count.TestCountWordsUnit)
If subreddit invalid -> 302/404 etc., print nothing. ... ok
test_no_matches_prints_nothing (test_unit_0_count.TestCountWordsUnit)
If no keyword occurrences -> print nothing. ... ok
test_recursion_across_pages (test_unit_0_count.TestCountWordsUnit)
Ensure we follow 'after' and aggregate counts across pages (recursive). ... ok

----------------------------------------------------------------------
Ran 13 tests in 0.248s

OK
pycodestyle 0-count.py
python3 -m unittest -v
test_invalid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Invalid subreddit, list 1 (prints nothing). ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_case_insensitive (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, case insensitive check. ... <frozen importlib._bootstrap>:283: DeprecationWarning: the load_module() method is deprecated and slated for removal in Python 3.12; use exec_module() instead
ok
test_valid_subreddit_duplicates_in_list (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid subreddit, duplicate items in list. ... ok
test_valid_subreddit_list1 (test_integration_0_count.TestCountWordsIntegration)
Output check: Valid Subreddit, list 1 (with pagination). ... ok
test_file_exists (test_meta_0_count.TestMeta) ... ok
test_first_line_shebang (test_meta_0_count.TestMeta) ... ok
test_imports_alpha_order (test_meta_0_count.TestMeta) ... ok
test_readme_exists (test_meta_0_count.TestMeta) ... ok
test_case_insensitive_keywords_and_duplicates (test_unit_0_count.TestCountWordsUnit)
'JavA' and 'java' in word_list -> multiplicity 2, so counts are doubled. ... ok
test_exact_tokens_punctuation_ignored (test_unit_0_count.TestCountWordsUnit)
Ensure 'java.' / 'java!' / 'java_' DO NOT count as 'java'. ... ok
test_invalid_subreddit_status_302 (test_unit_0_count.TestCountWordsUnit)
If subreddit invalid -> 302/404 etc., print nothing. ... ok
test_no_matches_prints_nothing (test_unit_0_count.TestCountWordsUnit)
If no keyword occurrences -> print nothing. ... ok
test_recursion_across_pages (test_unit_0_count.TestCountWordsUnit)
Ensure we follow 'after' and aggregate counts across pages (recursive). ... ok

----------------------------------------------------------------------
Ran 13 tests in 0.206s

OK
make: Nothing to be done for 'test'.
root@UID7E:/mnt/d/Users/steph/Documents/4ème_trimestre_speFS/algo/holbertonschool
-interview/count_it#
