#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "substring.h"

typedef struct test_case_s
{
	const char *name;
	const char *s;
	const char *words[5];
	int nb_words;
	int expected[5];
	int expected_n;
} test_case_t;

void print_array(const int *arr, int n)
{
	int i;

	printf("[");
	for (i = 0; i < n; i++)
	{
		if (i)
			printf(", ");
		printf("%d", arr[i]);
	}
	printf("]");
}

int same_array(const int *a, int na, const int *b, int nb)
{
	int i;

	if (na != nb)
		return (0);
	for (i = 0; i < na; i++)
		if (a[i] != b[i])
			return (0);
	return (1);
}

int main(void)
{
	test_case_t tests[] = {
		{
			"barfoothefoobarman / [foo, bar]",
			"barfoothefoobarman",
			{"foo", "bar", NULL, NULL, NULL},
			2,
			{0, 9},
			2
		},
		{
			"barfoothefoobarman / [foo, bar, man]",
			"barfoothefoobarman",
			{"foo", "bar", "man", NULL, NULL},
			3,
			{9},
			1
		},
		{
			"barfoothefoobarman / [foo, bar, the]",
			"barfoothefoobarman",
			{"foo", "bar", "the", NULL, NULL},
			3,
			{0, 6},
			2
		},
		{
			"barfoothefoobarman / [the, bar, foo]",
			"barfoothefoobarman",
			{"the", "bar", "foo", NULL, NULL},
			3,
			{0, 6},
			2
		},
		{
			"barfoothefoobarman / [the]",
			"barfoothefoobarman",
			{"the", NULL, NULL, NULL, NULL},
			1,
			{6},
			1
		},
		{
			"barfoothefoobarman / [the, bar, man]",
			"barfoothefoobarman",
			{"the", "bar", "man", NULL, NULL},
			3,
			{0}, /* empty */
			0
		},
		{
			"barfoothefoobarman / [the, bar, foo, foo]",
			"barfoothefoobarman",
			{"the", "bar", "foo", "foo", NULL},
			4,
			{3},
			1
		},
		{
			"barfoothefoobarman / [the, bar, foo, foo, bar]",
			"barfoothefoobarman",
			{"the", "bar", "foo", "foo", "bar"},
			5,
			{0},
			1
		},
		{
			"barfoothefoobarman / [the, bar, foo, foo, you]",
			"barfoothefoobarman",
			{"the", "bar", "foo", "foo", "you"},
			5,
			{0},
			0
		},
		{
			"barfoothefoobarman / [you]",
			"barfoothefoobarman",
			{"you", NULL, NULL, NULL, NULL},
			1,
			{0},
			0
		},
		{
			"barfoothefoobarman / [foo, foo]",
			"barfoothefoobarman",
			{"foo", "foo", NULL, NULL, NULL},
			2,
			{0},
			0
		},

		/* s = wordgoodgoodgoodbestword */
		{
			"wordgoodgoodgoodbestword / [word, good, best, word]",
			"wordgoodgoodgoodbestword",
			{"word", "good", "best", "word", NULL},
			4,
			{0},
			0
		},
		{
			"wordgoodgoodgoodbestword / [word]",
			"wordgoodgoodgoodbestword",
			{"word", NULL, NULL, NULL, NULL},
			1,
			{0, 20},
			2
		},
		{
			"wordgoodgoodgoodbestword / [good, good]",
			"wordgoodgoodgoodbestword",
			{"good", "good", NULL, NULL, NULL},
			2,
			{4, 8},
			2
		},
		{
			"wordgoodgoodgoodbestword / [good, good, good]",
			"wordgoodgoodgoodbestword",
			{"good", "good", "good", NULL, NULL},
			3,
			{4},
			1
		},
		{
			"wordgoodgoodgoodbestword / [good, word, good, good]",
			"wordgoodgoodgoodbestword",
			{"good", "word", "good", "good", NULL},
			4,
			{0},
			1
		},
		{
			"wordgoodgoodgoodbestword / [best, good, good, good]",
			"wordgoodgoodgoodbestword",
			{"best", "good", "good", "good", NULL},
			4,
			{4},
			1
		},
		{
			"wordgoodgoodgoodbestword / [good]",
			"wordgoodgoodgoodbestword",
			{"good", NULL, NULL, NULL, NULL},
			1,
			{4, 8, 12},
			3
		},
		{
			"wordgoodgoodgoodbestword / [test]",
			"wordgoodgoodgoodbestword",
			{"test", NULL, NULL, NULL, NULL},
			1,
			{0},
			0
		},
		{
			"wordgoodgoodgoodbestword / [good, test]",
			"wordgoodgoodgoodbestword",
			{"good", "test", NULL, NULL, NULL},
			2,
			{0},
			0
		},

		/* s = lingmindraboofooowingdingbarrwingmonkeypoundcake */
		{
			"ling...cake / [fooo, barr, wing, ding, wing]",
			"lingmindraboofooowingdingbarrwingmonkeypoundcake",
			{"fooo", "barr", "wing", "ding", "wing"},
			5,
			{13},
			1
		},
		{
			"ling...cake / [ling, barr, wing, ding, wing]",
			"lingmindraboofooowingdingbarrwingmonkeypoundcake",
			{"ling", "barr", "wing", "ding", "wing"},
			5,
			{0},
			0
		},

		/* empty string */
		{
			"empty string / [test]",
			"",
			{"test", NULL, NULL, NULL, NULL},
			1,
			{0},
			0
		}
	};
	int nb_tests = sizeof(tests) / sizeof(tests[0]);
	int i, n, ok_count = 0;
	int *res;
	int ok;

	for (i = 0; i < nb_tests; i++)
	{
		printf("=== Test %d: %s ===\n", i + 1, tests[i].name);

		res = find_substring(tests[i].s,
				     tests[i].words,
				     tests[i].nb_words,
				     &n);

		printf("  Expected: ");
		print_array(tests[i].expected, tests[i].expected_n);
		printf("\n  Got     : ");
		print_array(res ? res : (int[]){0}, n);
		printf("\n");

		if (tests[i].expected_n == 0)
			ok = (res == NULL);
		else
			ok = same_array(res, n,
					tests[i].expected,
					tests[i].expected_n);

		printf("  Result  : %s\n\n", ok ? "OK" : "FAIL");

		if (res)
			free(res);

		if (ok)
			ok_count++;
	}

	printf("SUMMARY: %d/%d tests OK\n", ok_count, nb_tests);

	return (0);
}
