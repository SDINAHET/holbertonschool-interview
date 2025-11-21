#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "substring.h"

typedef struct test_case_s
{
	const char *s;
	const char *words[10];
	int nb_words;
	const int expected[10];
	int expected_n;
	const char *name;
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

int compare_arrays(const int *a, int na, const int *b, int nb)
{
	int i;

	if (na != nb)
		return (0);
	for (i = 0; i < na; i++)
	{
		if (a[i] != b[i])
			return (0);
	}
	return (1);
}

int main(void)
{
	test_case_t tests[] = {
		{
			.s = "barfoothefoobarman",
			.words = {"foo", "bar"},
			.nb_words = 2,
			.expected = {0, 9},
			.expected_n = 2,
			.name = "simple foo/bar"
		},
		{
			.s = "wordgoodgoodgoodbestword",
			.words = {"word", "good", "best", "word"},
			.nb_words = 4,
			.expected = { },
			.expected_n = 0,
			.name = "exemple fourni Holberton"
		},
		{
			.s = "",
			.words = {"test"},
			.nb_words = 1,
			.expected = { },
			.expected_n = 0,
			.name = "chaine vide"
		},
	};
	int nb_tests = sizeof(tests) / sizeof(tests[0]);
	int i, n, ok_count = 0;
	int *indices;

	for (i = 0; i < nb_tests; i++)
	{
		printf("Test %d: %s\n", i + 1, tests[i].name);

		indices = find_substring(tests[i].s,
					 tests[i].words,
					 tests[i].nb_words,
					 &n);

		printf("  attendu : ");
		print_array(tests[i].expected, tests[i].expected_n);
		printf("\n  obtenu  : ");
		print_array(indices ? indices : (int[]){}, n);
		printf("\n");

		if ((indices == NULL && tests[i].expected_n == 0) ||
		    (indices && compare_arrays(indices, n,
					       tests[i].expected,
					       tests[i].expected_n)))
		{
			printf("  => OK ✅\n\n");
			ok_count++;
		}
		else
		{
			printf("  => FAIL ❌\n\n");
		}

		free(indices);
	}

	printf("Résultat global : %d/%d tests OK\n", ok_count, nb_tests);
	return (0);
}
