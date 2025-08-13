#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Integration tests for 0-count.py (Holberton - Count it!)
Python 3.4.3 compatible.
"""
import io
import os
import sys
import unittest

try:
    from unittest import mock
except ImportError:
    import mock

import importlib.machinery


def load_module():
    here = os.path.dirname(os.path.abspath(__file__))
    path = os.path.join(here, '0-count.py')
    loader = importlib.machinery.SourceFileLoader('count_module', path)
    return loader.load_module()


class FakeResponse(object):
    def __init__(self, status_code, json_obj):
        self.status_code = status_code
        self._json = json_obj

    def json(self):
        return self._json


class TestCountWordsIntegration(unittest.TestCase):

    def setUp(self):
        self.mod = load_module()

    @mock.patch('requests.get')
    def test_valid_subreddit_list1(self, mget):
        """Output check: Valid Subreddit, list 1 (with pagination)."""
        page1 = {
            "data": {
                "after": "next",
                "children": [
                    {"data": {"title": "Java python javascript"}},
                    {"data": {"title": "react React REACT"}},
                    {"data": {"title": "java."}},
                    {"data": {"title": "scala scala scala,"}},
                ]
            }
        }
        page2 = {
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
            if params and params.get('after') == "next":
                return FakeResponse(200, page2)
            return FakeResponse(200, page1)

        mget.side_effect = side_effect

        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming",
                                 ["react", "python", "java",
                                  "javascript", "scala",
                                  "no_results_for_this_one"])
        finally:
            sys.stdout = sys_stdout

        out = captured.getvalue().strip().splitlines()
        self.assertEqual(out, [
            "python: 4",
            "javascript: 3",
            "react: 3",
            "java: 2",
            "scala: 2"
        ])

    @mock.patch('requests.get')
    def test_valid_subreddit_case_insensitive(self, mget):
        """Output check: Valid subreddit, case insensitive check."""
        page = {
            "data": {
                "after": None,
                "children": [
                    {"data": {"title": "Python PYTHON python"}},
                    {"data": {"title": "React"}},
                ]
            }
        }
        mget.return_value = FakeResponse(200, page)

        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["PYTHON", "react"])
        finally:
            sys.stdout = sys_stdout

        out = captured.getvalue().strip().splitlines()
        self.assertEqual(out, [
            "python: 3",
            "react: 1"
        ])

    @mock.patch('requests.get')
    def test_valid_subreddit_duplicates_in_list(self, mget):
        """Output check: Valid subreddit, duplicate items in list."""
        page = {
            "data": {
                "after": None,
                "children": [
                    {"data": {"title": "java javascript java"}},
                ]
            }
        }
        mget.return_value = FakeResponse(200, page)

        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["JavA", "java"])
        finally:
            sys.stdout = sys_stdout

        out = captured.getvalue().strip()
        self.assertEqual(out, "java: 4")  # (2 base) * (2 duplicates)

    @mock.patch('requests.get')
    def test_invalid_subreddit_list1(self, mget):
        """Output check: Invalid subreddit, list 1 (prints nothing)."""
        mget.return_value = FakeResponse(404, {})
        captured = io.StringIO()
        sys_stdout = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("not_a_valid_subreddit",
                                 ["python", "java", "javascript", "scala"])
        finally:
            sys.stdout = sys_stdout

        self.assertEqual(captured.getvalue(), "")


if __name__ == '__main__':
    unittest.main(verbosity=2)
