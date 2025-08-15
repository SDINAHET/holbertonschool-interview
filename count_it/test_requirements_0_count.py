#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Requirement-focused tests for 0-count.py (Holberton - Count it!)
- Python 3.4.3 compatible
- No network: requests.get is mocked
"""
import io
import os
import sys
import unittest

try:
    from unittest import mock
except ImportError:
    import mock  # noqa

import importlib.machinery


def load_module():
    """Load 0-count.py as a module regardless of the hyphen in its name."""
    here = os.path.dirname(os.path.abspath(__file__))
    path = os.path.join(here, '0-count.py')
    loader = importlib.machinery.SourceFileLoader('count_module', path)
    return loader.load_module()


class FakeResponse(object):
    """Minimal fake response to mimic requests.Response."""
    def __init__(self, status_code, json_obj):
        self.status_code = status_code
        self._json = json_obj

    def json(self):
        return self._json


def _page(children, after=None):
    return {"data": {"after": after, "children": children}}


def _child(title):
    return {"data": {"title": title}}


class TestRequirements(unittest.TestCase):

    def setUp(self):
        self.mod = load_module()

    @mock.patch('requests.get')
    def test_prototype_callable_two_args(self, mget):
        """Prototype callable: def count_words(subreddit, word_list)."""
        mget.return_value = FakeResponse(200, _page([], after=None))
        # Must be callable with just 2 args, no starting value
        captured = io.StringIO()
        old = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["java"])
        finally:
            sys.stdout = old
        # no crash == pass

    @mock.patch('requests.get')
    def test_duplicates_sum_multiplicity(self, mget):
        """Duplicates in word_list sum (multiplicity)."""
        mget.return_value = FakeResponse(
            200,
            _page([_child("java javascript java")], after=None)
        )
        captured = io.StringIO()
        old = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["JavA", "java"])
        finally:
            sys.stdout = old
        self.assertEqual(captured.getvalue().strip(), "java: 4")

    @mock.patch('requests.get')
    def test_desc_sort_then_alpha_ties_and_skip_zero(self, mget):
        """
        Sorted by count desc, then alpha; words with zero -> skipped;
        output words are lowercase.
        """
        # alpha x2, beta x2, gamma x0 (skip)
        titles = [
            _child("alpha alpha"),
            _child("beta beta")
        ]
        mget.return_value = FakeResponse(200, _page(titles, after=None))

        captured = io.StringIO()
        old = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words(
                "programming", ["beta", "alpha", "GAMMA"]
            )
        finally:
            sys.stdout = old

        lines = captured.getvalue().strip().splitlines()
        # both 2: alpha then beta (alphabetical)
        self.assertEqual(lines, ["alpha: 2", "beta: 2"])
        # lowercase check
        for line in lines:
            word = line.split(":")[0]
            self.assertTrue(word.islower())

    @mock.patch('requests.get')
    def test_occurrence_based_not_titles(self, mget):
        """Counts occurrences, not titles: 'java java java' -> 3."""
        mget.return_value = FakeResponse(
            200, _page([_child("java java java")], after=None)
        )
        captured = io.StringIO()
        old = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["java"])
        finally:
            sys.stdout = old
        self.assertEqual(captured.getvalue().strip(), "java: 3")

    @mock.patch('requests.get')
    def test_punctuation_not_counted(self, mget):
        """java., java!, java_ do NOT count as 'java'."""
        titles = [
            _child("java. java! java_ java,"),
            _child("java")  # only this one counts
        ]
        mget.return_value = FakeResponse(200, _page(titles, after=None))

        captured = io.StringIO()
        old = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("programming", ["java"])
        finally:
            sys.stdout = old
        self.assertEqual(captured.getvalue().strip(), "java: 1")

    @mock.patch('requests.get')
    def test_invalid_subreddit_prints_nothing(self, mget):
        """Invalid subreddit -> non-200 -> print nothing."""
        mget.return_value = FakeResponse(404, {})
        captured = io.StringIO()
        old = sys.stdout
        sys.stdout = captured
        try:
            self.mod.count_words("not_a_valid_subreddit", ["python", "java"])
        finally:
            sys.stdout = old
        self.assertEqual(captured.getvalue(), "")

    @mock.patch('requests.get')
    def test_no_redirects_flag_is_false(self, mget):
        """Ensure allow_redirects=False is passed to requests.get."""
        mget.return_value = FakeResponse(200, _page([], after=None))
        self.mod.count_words("programming", ["java"])
        # Inspect kwargs used in the last call
        args, kwargs = mget.call_args
        self.assertIn('allow_redirects', kwargs)
        self.assertFalse(kwargs['allow_redirects'])


if __name__ == '__main__':
    unittest.main(verbosity=2)
