#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "regex.h"

/* Helpers to build long strings/patterns cleanly */
#define REPEAT_A_10      "AAAAAAAAAA"
#define REPEAT_A_40      REPEAT_A_10 REPEAT_A_10 REPEAT_A_10 REPEAT_A_10
#define REPEAT_A_160     REPEAT_A_40 REPEAT_A_40 REPEAT_A_40 REPEAT_A_40

/* 26 letters */
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

/* 25 dots after 'A' -> total 26 chars with first 'A' */
#define A_PLUS_25_DOTS \
"A................................." /* 1 + 25 = 26 total (verify count) */

/*
 * To avoid mistakes, we generate exact dot counts below with literals:
 * - For "A + 25 dots": that's 25 '.' after the initial 'A'.
 * - For "A + 24 dots + Z": 24 '.' between A and Z so length = 26.
 * - For the "wrong length" case, we use 23 dots between A and Z.
 */
#define A_25_DOTS          "A................................." /* 1 + 25 */
#define A_24_DOTS_Z        "A................................Z" /* A + 24 + Z */
#define A_23_DOTS_Z        "A...............................Z" /* A + 23 + Z */

/* 20 dots only (length = 20) */
#define DOTS_20 "...................."

struct test {
	const char *s;
	const char *p;
	int expect;
	const char *label;
};

int main(void)
{
	int i, passed = 0, total;
	/* de-duplicated, ASCII-only, explicit expectations */
	struct test cases[] = {
		/* Basics */
		{"A", "A", 1, "regex_match(\"A\", \"A\")"},
		{"A", "", 0, "regex_match(\"A\", \"\")"},
		{"", "A", 0, "regex_match(\"\", \"A\")"},
		{"", "", 1, "regex_match(\"\", \"\")"},
		{"AA", "A", 0, "regex_match(\"AA\", \"A\")"},
		{"A", "AA", 0, "regex_match(\"A\", \"AA\")"},

		/* Star on single letter */
		{"A", "A*", 1, "regex_match(\"A\", \"A*\")"},
		{"AA", "A*", 1, "regex_match(\"AA\", \"A*\")"},
		{"AAAAA", "A*", 1, "regex_match(\"AAAAA\", \"A*\")"},
		{REPEAT_A_10, "A*", 1, "regex_match(\"AAAAAAAAAA\", \"A*\")"},
		{REPEAT_A_40, "A*", 1, "regex_match(40x\"A\", \"A*\")"},
		{REPEAT_A_160, "A*", 1, "regex_match(160x\"A\", \"A*\")"},
		{"", "A*", 1, "regex_match(\"\", \"A*\")"},
		{"B", "A*", 0, "regex_match(\"B\", \"A*\")"},
		{"AB", "A*", 0, "regex_match(\"AB\", \"A*\")"},
		{"BA", "A*", 0, "regex_match(\"BA\", \"A*\")"},

		/* Concatenation & star on second token */
		{"AB", "AB", 1, "regex_match(\"AB\", \"AB\")"},
		{"AB", "AB*", 1, "regex_match(\"AB\", \"AB*\")"},
		{"ABB", "AB*", 1, "regex_match(\"ABB\", \"AB*\")"},
		{"A", "AB*", 1, "regex_match(\"A\", \"AB*\")"},

		/* Long, deliberately failing when alphabet is enforced */
		{"A", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*", 0,
		 "regex_match(\"A\", \"ABCDEFGHIJKLMNOPQRSTUVWXYZ*\")"},
		{"AZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0,
		 "regex_match(\"AZ\", \"ABCDEFGHIJKLMNOPQRSTUVWXYZ\")"},
		{"AZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*", 0,
		 "regex_match(\"AZ\", \"ABCDEFGHIJKLMNOPQRSTUVWXYZ*\")"},
		{"AFJLOSWZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*", 0,
		 "regex_match(\"AFJLOSWZ\", \"ABCDEFGHIJKLMNOPQRSTUVWXYZ*\")"},
		{"AFJPLOSWZ", "ABCDEFGHIJKLMNOPQRSTUVWXYZ*", 0,
		 "regex_match(\"AFJPLOSWZ\", \"ABCDEFGHIJKLMNOPQRSTUVWXYZ*\")"},

		/* Dot (.) */
		{"AB", "A.", 1, "regex_match(\"AB\", \"A.\")"},
		{"ABC", "A.C", 1, "regex_match(\"ABC\", \"A.C\")"},
		{"ABC", "A..", 1, "regex_match(\"ABC\", \"A..\")"},
		{"ABC", "A.", 0, "regex_match(\"ABC\", \"A.\")"},

		/* A + many dots to fit the alphabet */
		{"ABCDEFGHIJKLMNOPQRSTUVWXYZ", A_25_DOTS, 1,
		 "regex_match(ALPHABET, \"A + 25 dots\")"},
		{"ABCDEFGHIJKLMNOPQRSTUVWXYZ", A_24_DOTS_Z, 1,
		 "regex_match(ALPHABET, \"A + 24 dots + Z\")"},
		{"ABCDEFGHIJKLMNOPQRSTUVWXYZ", A_23_DOTS_Z, 0,
		 "regex_match(ALPHABET, \"A + 23 dots + Z (should fail)\")"},

		/* Empty with dot/star */
		{"", ".", 0, "regex_match(\"\", \".\")"},
		{"", ".*", 1, "regex_match(\"\", \".*\")"},
		{"A", ".*", 1, "regex_match(\"A\", \".*\")"},
		{"AA", ".*", 1, "regex_match(\"AA\", \".*\")"},
		{"AABB", ".*", 1, "regex_match(\"AABB\", \".*\")"},
		{"Lorem ipsum dolor si amet", ".*", 1,
		 "regex_match(\"Lorem...\", \".*\")"},

		/* Leading literals that don't match */
		{"ABC", "ZA.", 0, "regex_match(\"ABC\", \"ZA.\")"},
		{"ABC", "ZAB.", 0, "regex_match(\"ABC\", \"ZAB.\")"},
		{"ABC", "ZABC.", 0, "regex_match(\"ABC\", \"ZABC.\")"},
		{"ABC", "Z.", 0, "regex_match(\"ABC\", \"Z.\")"},
		{"ABC", ".*", 1, "regex_match(\"ABC\", \".*\")"},
		{"ABC", "..", 0, "regex_match(\"ABC\", \"..\")"},
		{"ABC", DOTS_20, 0, "regex_match(\"ABC\", 20 dots)"},
		{"", DOTS_20, 0, "regex_match(\"\", 20 dots)"},

		/* Exact long sentence */
		{"Lorem ipsum dolor si amet", "Lorem ipsum dolor si amet", 1,
		 "exact long sentence"},

		/* Variants with .* around */
		{"Lorem ipsum dolor si amet", "Lor.*m ipsum dolor si amet", 1,
		 "prefix partial with .*"},
		{"Lorem ipsum dolor si amet", "Lore.*m ipsum dolor si amet", 1,
		 "prefix partial 2 with .*"},
		{"Lorem ipsum dolor si amet", ".*Lorem ipsum dolor si amet", 1,
		 "leading .*"},
		{"Lorem ipsum dolor si amet", "Lorem ipsum dolor si amet.*", 1,
		 "trailing .*"},

		/* Leading/trailing single '.' should force extra chars -> fail */
		{"Lorem ipsum dolor si amet", ".Lorem ipsum dolor si amet.", 0,
		 "both sides '.' require extra chars"},

		/* Between words: need extra chars -> fail */
		{"Lorem ipsum dolor si amet", ".Lorem..ipsum dolor si amet.*", 0,
		 "two dots require two chars between 'Lorem' and 'ipsum'"},
		{"Lorem ipsum dolor si amet", ".Lorem.ipsum dolor si amet.*", 0,
		 "one leading '.' still fails at start (needs extra char)"},

		/* Same idea: leading '.' requires one extra char -> fail */
		{"Lorem ipsum dolor si amet", ".Lorem ipsum dolor si amet.", 0,
		 "leading and trailing '.' -> need extra chars"},

		/* Adjusted ambiguous originals into valid ASCII-only cases */
		{"Lorem ipsum dolor si amet", ".Lorem .....*dolor si amet.", 0,
		 "requires leading char then >=4 chars before 'dolor'"},
		{"Lorem ipsum dolor si amet", ".Lorem ..dolor si amet.", 0,
		 "requires leading char and two chars before 'dolor'"},

		/* Dot at start can cover missing 'L' */
		{"Lorem ipsum dolor si amet", ".orem ipsum dolor si amet", 1,
		 "dot covers 'L' at start"},

		/* Dot at end covers last char */
		{"Lorem ipsum dolor si amet", "Lorem ipsum dolor si ame.", 1,
		 "dot covers final 't'"},
	};

	total = (int)(sizeof(cases) / sizeof(cases[0]));

	for (i = 0; i < total; i++)
	{
		int got = regex_match(cases[i].s, cases[i].p);
		int ok = (got == cases[i].expect);

		if (ok)
		{
			printf("[PASS] %s -> \"%s\" ~~ \"%s\" (got=%d)\n",
			       cases[i].label, cases[i].s, cases[i].p, got);
			passed++;
		}
		else
		{
			printf("[FAIL] %s -> \"%s\" ~~ \"%s\" (got=%d, expect=%d)\n",
			       cases[i].label, cases[i].s, cases[i].p,
			       got, cases[i].expect);
		}
	}

	printf("\nSummary: %d/%d passed\n", passed, total);
	return (passed == total ? EXIT_SUCCESS : EXIT_FAILURE);
}
