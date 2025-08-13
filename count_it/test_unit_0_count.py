#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Unit tests for 0-count.py (Holberton - Count it!)
Python 3.4.3 compatible.
"""
import io
import os
import sys
import unittest

try:
    # Python 3.4's stdlib
    from unittest import mock
except ImportError:
    import mock  # fallback if needed

import importlib.machinery


def load_module():
    """Load 0-count.py as a module regardless of the hyphen in its name."""
    here = os.path.dirname(os.path.abspath(__file__))
    path = os.path.join(here, '0-count.py')
    loader = importlib.machinery.SourceFileLoader('count_module', path)
    return loader.load_module()


class FakeResponse(object):
    """Minimal fake response object to mimic requests.Response."""
    def __init__(self, status_code, json_obj):
        self.status_code = status_code
        self._json = json_obj

    def json(self):
        return self._json


class TestCountWordsUnit(unittest.TestCase):

    def setUp(self):
        self.mod = load_module()

    @mock.patch('requests.get')
    def test_exact_tokens_punctuation_ignored(self, mget):
        """
        Ensure 'java.' / 'java!' / 'java_' DO NOT count as 'java'.
        """
        # Single page with titles including punctuations
        json_page = {
            "data": {
                "after": None,
                "children": [
                    {"data": {"title": "java java. java! java_ javascript"}},
                    {"data": {"title": "Python python PYTHON"}},
                    {"data": {"title": "react React REACT"}},
                    {"data": {"title": "scala scala scala,"}},
                ]
            }
        }
        mget.return_value = FakeResponse(200, json_page)

        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming",
                                 ["react", "python", "java",
                                  "javascript", "scala"])
        finally:
            sys.stdout = sys_stdout

        out = captured.getvalue().strip().splitlines()
        # Expected counts:
        # java: only the bare "java" (first token) -> 1
        # javascript: 1
        # python: 3
        # react: 3
        # scala: 2  (scala, with comma does NOT count)
        expected = [
            "python: 3",
            "react: 3",
            "javascript: 1",
            "scala: 2",
            "java: 1"
        ]
        # Sort rules: first by count desc, then alpha asc
        # => 3: python, react (alphabetical: javascript has 1), 2: scala, 1: java, javascript
        # But our function already sorts; just check exact order produced:
        self.assertEqual(out, [
            "python: 3",
            "react: 3",
            "scala: 2",
            "java: 1",
            "javascript: 1"
        ])

    @mock.patch('requests.get')
    def test_case_insensitive_keywords_and_duplicates(self, mget):
        """
        'JavA' and 'java' in word_list -> multiplicity 2, so counts are doubled.
        Titles contain 2 occurrences of 'java' -> printed total should be 4.
        """
        json_page = {
            "data": {
                "after": None,
                "children": [
                    {"data": {"title": "java javascript java"}}
                ]
            }
        }
        mget.return_value = FakeResponse(200, json_page)

        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["JavA", "java"])
        finally:
            sys.stdout = sys_stdout

        out = captured.getvalue().strip()
        self.assertEqual(out, "java: 4")  # 2 (base) * 2 (duplicates)

    @mock.patch('requests.get')
    def test_recursion_across_pages(self, mget):
        """
        Ensure we follow 'after' and aggregate counts across pages (recursive).
        """
        # First page -> after token
        json_page1 = {
            "data": {
                "after": "t3_next",
                "children": [
                    {"data": {"title": "Java python javascript"}},
                    {"data": {"title": "react React REACT"}},
                    {"data": {"title": "java."}},
                    {"data": {"title": "scala scala scala,"}},
                ]
            }
        }
        # Second page -> no after
        json_page2 = {
            "data": {
                "after": None,
                "children": [
                    {"data": {"title": "Python python python"}},
                    {"data": {"title": "Javascript javascript java"}},
                ]
            }
        }

        def side_effect(url, headers=None, params=None,
                        allow_redirects=False, timeout=10):
            if params and params.get('after') == "t3_next":
                return FakeResponse(200, json_page2)
            return FakeResponse(200, json_page1)

        mget.side_effect = side_effect

        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming",
                                 ["react", "python", "java",
                                  "javascript", "scala"])
        finally:
            sys.stdout = sys_stdout

        out = captured.getvalue().strip().splitlines()
        # Expected final sorted output:
        # python: 4
        # javascript: 3
        # react: 3
        # java: 2
        # scala: 2
        self.assertEqual(out, [
            "python: 4",
            "javascript: 3",
            "react: 3",
            "java: 2",
            "scala: 2"
        ])

    @mock.patch('requests.get')
    def test_invalid_subreddit_status_302(self, mget):
        """If subreddit invalid -> 302/404 etc., print nothing."""
        mget.return_value = FakeResponse(302, {})
        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("not_a_valid_subreddit", ["python", "java"])
        finally:
            sys.stdout = sys_stdout
        self.assertEqual(captured.getvalue(), "")

    @mock.patch('requests.get')
    def test_no_matches_prints_nothing(self, mget):
        """If no keyword occurrences -> print nothing."""
        json_page = {
            "data": {
                "after": None,
                "children": [
                    {"data": {"title": "golang rust typescript"}}
                ]
            }
        }
        mget.return_value = FakeResponse(200, json_page)
        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["python", "java"])
        finally:
            sys.stdout = sys_stdout
        self.assertEqual(captured.getvalue(), "")


if __name__ == '__main__':
    unittest.main(verbosity=2)
