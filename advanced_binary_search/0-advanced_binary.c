#include "search_algos.h"
#include <stdio.h>

/**
 * print_array - Prints the elements in the current search subarray
 * @array: The array to print from
 * @left: The starting index
 * @right: The ending index
 */
void print_array(int *array, int left, int right)
{
	int i;

	printf("Searching in array: ");
	for (i = left; i <= right; i++)
	{
		printf("%d", array[i]);
		if (i < right)
			printf(", ");
	}
	printf("\n");
}

/**
 * recursive_search - Recursively searches for the first occurrence of a value
 * @array: Pointer to the array
 * @left: Left index
 * @right: Right index
 * @value: Value to search for
 * Return: Index of the first occurrence, or -1
 */
int recursive_search(int *array, int left, int right, int value)
{
	int mid;

	if (left > right)
		return (-1);

	print_array(array, left, right);

	mid = left + (right - left) / 2;

	if (array[mid] == value)
	{
		/* Check if first occurrence */
		if (mid == left || array[mid - 1] != value)
			return (mid);
		return (recursive_search(array, left, mid - 1, value));
	}
	if (array[mid] > value)
		return (recursive_search(array, left, mid - 1, value));
	return (recursive_search(array, mid + 1, right, value));
}

/**
 * advanced_binary - Searches for a value in a sorted array using recursion
 * @array: Pointer to the first element
 * @size: Number of elements
 * @value: Value to search for
 * Return: Index of the first occurrence, or -1
 */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (recursive_search(array, 0, (int)size - 1, value));
}
