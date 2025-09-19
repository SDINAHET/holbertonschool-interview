#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/* Forward decls */
static void merge_recursive(int *array, int *buf, size_t left, size_t right);
static void print_subarray(const int *array, size_t start, size_t end);

/**
 * merge_sort - Sorts an array of integers using top-down Merge Sort
 * @array: Pointer to the array
 * @size: Number of elements in @array
 */
void merge_sort(int *array, size_t size)
{
	int *buf;

	if (!array || size < 2)
		return;

	/* Single allocation for the entire sort */
	buf = malloc(sizeof(int) * size);
	if (!buf)
		return;

	merge_recursive(array, buf, 0, size);

	free(buf);
}

/**
 * merge_recursive - Recursively sorts subarray [left, right) and merges
 * @array: The array being sorted (in-place)
 * @buf:   Auxiliary buffer (same size as array)
 * @left:  Inclusive start index
 * @right: Exclusive end index
 */
static void merge_recursive(int *array, int *buf, size_t left, size_t right)
{
	size_t mid, i, j, k;

	if (right - left < 2)
		return;

	/* Split with left size <= right size */
	mid = (left + right) / 2;

	/* Sort left first, then right */
	merge_recursive(array, buf, left, mid);
	merge_recursive(array, buf, mid, right);

	/* Print before merging this level */
	printf("Merging...\n");
	printf("[left]: ");
	print_subarray(array, left, mid);
	printf("[right]: ");
	print_subarray(array, mid, right);

	/* Merge into buffer */
	i = left;
	j = mid;
	k = left;
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
			buf[k++] = array[i++];
		else
			buf[k++] = array[j++];
	}
	while (i < mid)
		buf[k++] = array[i++];
	while (j < right)
		buf[k++] = array[j++];

	/* Copy merged back to array */
	for (k = left; k < right; k++)
		array[k] = buf[k];

	/* Print result */
	printf("[Done]: ");
	print_subarray(array, left, right);
}

/**
 * print_subarray - Prints array elements in range [start, end)
 * @array: The array
 * @start: Inclusive start index
 * @end:   Exclusive end index
 */
static void print_subarray(const int *array, size_t start, size_t end)
{
	size_t i;

	for (i = start; i < end; i++)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
	}
	printf("\n");
}
