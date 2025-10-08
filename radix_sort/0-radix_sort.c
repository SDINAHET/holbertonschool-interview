#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Get the maximum value in an array of integers
 * @array: Pointer to the first element of the array
 * @size: Number of elements in @array
 *
 * Return: The maximum integer in the array
 */
static int get_max(const int *array, size_t size)
{
	size_t i;
	int max;

	max = array[0];
	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort_digit - Stable counting sort by a specific decimal digit
 * @array: Pointer to the first element of the array
 * @size: Number of elements in @array
 * @exp: 10^k, the current digit significance (1, 10, 100, ...)
 * @buf: Temporary buffer of size @size used to store the sorted output
 *
 * Description: Sorts @array according to the digit indicated by @exp,
 *              keeping the sort stable.
 */
static void counting_sort_digit(int *array, size_t size, int exp, int *buf)
{
	int count[10] = {0};
	size_t i;

	/* Count digit occurrences */
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;

	/* Prefix sums -> positions */
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	/* Build output (iterate backwards to keep stability) */
	for (i = size; i > 0; i--)
	{
		int digit = (array[i - 1] / exp) % 10;

		buf[count[digit] - 1] = array[i - 1];
		count[digit]--;
	}

	/* Copy back */
	for (i = 0; i < size; i++)
		array[i] = buf[i];
}

/**
 * radix_sort - Sort an array of integers in ascending order using LSD Radix
 * @array: Pointer to the first element of the array
 * @size: Number of elements in @array
 *
 * Description: Assumes all numbers are >= 0. Prints the array after each
 *              pass over a more significant digit (as required).
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;
	int *buf;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	buf = malloc(sizeof(int) * size);
	if (buf == NULL)
		return;

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		counting_sort_digit(array, size, exp, buf);
		print_array(array, size);
	}

	free(buf);
}
