/* tests_radix.c (C89) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"

/* --- Helpers ----------------------------------------------------------- */

static int cmp_int(const void *a, const void *b)
{
    const int ia = *(const int *)a;
    const int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

static int is_sorted_non_decreasing(const int *arr, size_t n)
{
    size_t i;

    if (!arr || n < 2)
        return 1;

    for (i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
            return 0;
    }
    return 1;
}

/**
 * run_case - run one test case
 * @name: test name
 * @in: input array (will not be modified)
 * @n: number of elements
 * Return: 1 if PASS, 0 if FAIL
 */
static int run_case(const char *name, const int *in, size_t n)
{
    int *work = NULL, *expect = NULL;
    int pass = 0;

    /* Copy input to working buffer and expected buffer */
    if (n > 0 && in)
    {
        work = (int *)malloc(sizeof(int) * n);
        expect = (int *)malloc(sizeof(int) * n);
        if (!work || !expect)
        {
            fprintf(stderr, "[%s] ERROR: malloc failed\n", name);
            goto done;
        }
        memcpy(work, in, sizeof(int) * n);
        memcpy(expect, in, sizeof(int) * n);
    }

    /* Reference sort */
    if (n > 0 && expect)
        qsort(expect, n, sizeof(int), cmp_int);

    /* Call radix_sort (must handle NULL / size<2 safely) */
    if (n == 0)
        radix_sort(NULL, 0);
    else if (n == 1 && in)
        radix_sort(work, 1);
    else if (in)
        radix_sort(work, n);

    /* Validate */
    if (n == 0 || n == 1)
    {
        pass = 1; /* no crash => OK */
    }
    else
    {
        if (!is_sorted_non_decreasing(work, n))
        {
            fprintf(stderr, "[%s] FAIL: output not sorted non-decreasing\n", name);
            goto done;
        }
        if (memcmp(work, expect, sizeof(int) * n) != 0)
        {
            fprintf(stderr, "[%s] FAIL: content mismatch vs qsort reference\n", name);
            goto done;
        }
        pass = 1;
    }

done:
    free(work);
    free(expect);
    printf("[%s] %s\n", name, pass ? "PASS" : "FAIL");
    return pass;
}

/* Macro: passe un tableau existant (pas un littéral) */
#define RUN_CASE(NAME, ARR) do {                                             \
    total += 1;                                                              \
    passed += run_case((NAME), (ARR), sizeof(ARR) / sizeof((ARR)[0]));       \
} while (0)

int main(void)
{
    int total = 0;
    int passed = 0;

    /* Core cases from project statement */
    {
        int tmp[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
        RUN_CASE("sample-from-subject", tmp);
    }

    /* Already sorted */
    {
        int tmp[] = {7, 13, 19, 48, 52, 71, 73, 86, 96, 99};
        RUN_CASE("already-sorted", tmp);
    }

    /* Reverse order */
    {
        int tmp[] = {99, 96, 86, 73, 71, 52, 48, 19, 13, 7};
        RUN_CASE("reverse", tmp);
    }

    /* Duplicates */
    {
        int tmp[] = {5, 5, 5, 1, 1, 9, 9, 0, 0, 3, 3};
        RUN_CASE("duplicates", tmp);
    }

    /* Zeros and small values */
    {
        int tmp[] = {0, 0, 1, 2, 10, 100, 3, 30, 300};
        RUN_CASE("zeros-and-small", tmp);
    }

    /* Wide range (still non-negative) */
    {
        int tmp[] = {1, 1000000, 999, 10, 100, 0, 50000};
        RUN_CASE("wide-range", tmp);
    }

    /* Mixed sizes */
    {
        int tmp[] = {42};
        RUN_CASE("single-element", tmp);
    }

    /* Empty: handled as special case in run_case() */
    total += 1;
    passed += run_case("empty", NULL, 0);

    printf("\nSummary: %d/%d tests passed\n", passed, total);
    return (passed == total) ? 0 : 1;
}
