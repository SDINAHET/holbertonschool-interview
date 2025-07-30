#include "sort.h"
#include <unistd.h>  /* pour ssize_t */


/**
 * swap - Swaps two integers in an array
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * sift_down - Maintains the max-heap property between root and end
 * @array: The array to be sorted
 * @start: The index of the root node
 * @end: The last index of the heap
 * @size: The size of the array (for print_array)
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
	size_t root = start;
	size_t child, swap_idx;

	while ((child = 2 * root + 1) <= end)
	{
		swap_idx = root;

		if (array[swap_idx] < array[child])
			swap_idx = child;

		if (child + 1 <= end && array[swap_idx] < array[child + 1])
			swap_idx = child + 1;

		if (swap_idx == root)
			return;

		swap(&array[root], &array[swap_idx]);
		print_array(array, size);

		root = swap_idx;
	}
}

/**
 * heap_sort - Sorts an array using the Heap sort algorithm
 * @array: The array to sort
 * @size: The size of the array
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;

	if (array == NULL || size < 2)
		return;

	/* Build max heap */
	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, i, size - 1, size);

	/* Perform heap sort */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		sift_down(array, 0, i - 1, size);
	}
}
