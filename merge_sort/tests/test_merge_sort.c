#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "sort.h"

/* Helpers */
static int cmp_int(const void *a, const void *b) {
    int ia = *(const int *)a, ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

static void copy(int *dst, const int *src, size_t n) {
    if (!dst || !src) return;
    memcpy(dst, src, n * sizeof(int));
}

static int is_sorted_nondec(const int *a, size_t n) {
    if (!a || n < 2) return 1;
    for (size_t i = 1; i < n; ++i)
        if (a[i-1] > a[i]) return 0;
    return 1;
}

static void run_case(const char *title, const int *in, size_t n)
{
    int *got = NULL, *exp = NULL;

    printf(">> %s\n", title);

    if (n > 0 && in) {
        got = malloc(n * sizeof(int));
        exp = malloc(n * sizeof(int));
        assert(got && exp);
        copy(got, in, n);
        copy(exp, in, n);
    }

    /* NULL/0 must not crash */
    if (in == NULL && n == 0) {
        merge_sort(NULL, 0);
        printf("   OK (NULL,0 no crash)\n");
        return;
    }

    /* Expected via qsort (test side can use stdlib) */
    qsort(exp, n, sizeof(int), cmp_int);

    /* Run student's merge_sort */
    merge_sort(got, n);

    /* Check */
    assert(is_sorted_nondec(got, n) && "array not sorted non-decreasing");
    assert(memcmp(got, exp, n * sizeof(int)) == 0 && "result differs from qsort");

    printf("   OK (sorted & matches qsort)\n");
    free(got);
    free(exp);
}

int main(void)
{
    /* 20 random */
    int a1[] = {19,48,99,71,13,52,96,73,86,7,5,42,31,11,2,88,67,77,15,62};
    /* almost sorted (one swap) */
    int a2[] = {1,2,3,4,5,6,7,8,9,10,12,11,13,14,15,16,17,18,19,20};
    /* descending 20 */
    int a3[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    /* random 100 (deterministic) */
    int a4[100];
    /* 2 elements disordered */
    int a5[] = {2,1};
    /* already sorted 20 */
    int a6[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    /* single element */
    int a7[] = {42};
    /* 20 identical */
    int a8[] = {7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7,7};

    unsigned seed = 1337U;
    for (size_t i = 0; i < 100; i++) { seed = 1103515245U*seed + 12345U; a4[i] = (int)(seed % 1000); }

    run_case("20 elements, random", a1, sizeof(a1)/sizeof(a1[0]));
    run_case("20 elements, almost sorted", a2, sizeof(a2)/sizeof(a2[0]));
    run_case("20 elements, descending", a3, sizeof(a3)/sizeof(a3[0]));
    run_case("100 elements, random", a4, sizeof(a4)/sizeof(a4[0]));
    run_case("2 elements, disordered", a5, sizeof(a5)/sizeof(a5[0]));
    run_case("20 elements, already sorted", a6, sizeof(a6)/sizeof(a6[0]));
    run_case("1 element", a7, sizeof(a7)/sizeof(a7[0]));
    run_case("NULL/0 edge case", NULL, 0);
    run_case("20 identical elements", a8, sizeof(a8)/sizeof(a8[0]));

    puts("\nAll tests passed ✅");
    return 0;
}
