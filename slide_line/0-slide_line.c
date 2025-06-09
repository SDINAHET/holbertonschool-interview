#include "slide_line.h"

/**
 * shift_and_merge_left - Shifts and merges numbers to the left
 * @line: Array of integers
 * @size: Size of the array
 */
void shift_and_merge_left(int *line, size_t size)
{
	size_t i, j;

	/* First shift: move non-zero elements left */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}

	/* Merge identical elements */
	for (i = 0; i < size - 1; i++)
	{
		if (line[i] != 0 && line[i] == line[i + 1])
		{
			line[i] *= 2;
			line[i + 1] = 0;
		}
	}

	/* Second shift to clean up zeros created by merge */
	for (i = 0, j = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j++;
		}
	}
}

/**
 * shift_and_merge_right - Shifts and merges numbers to the right
 * @line: Array of integers
 * @size: Size of the array
 */
void shift_and_merge_right(int *line, size_t size)
{
	int i, j;

	/* First shift: move non-zero elements right */
	for (i = size - 1, j = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}

	/* Merge identical elements */
	for (i = size - 1; i > 0; i--)
	{
		if (line[i] != 0 && line[i] == line[i - 1])
		{
			line[i] *= 2;
			line[i - 1] = 0;
		}
	}

	/* Second shift to clean up zeros created by merge */
	for (i = size - 1, j = size - 1; i >= 0; i--)
	{
		if (line[i] != 0)
		{
			if (i != j)
			{
				line[j] = line[i];
				line[i] = 0;
			}
			j--;
		}
	}
}

/**
 * slide_line - Slides and merges a line of integers (like 2048 game)
 * @line: Pointer to array of integers
 * @size: Number of elements in array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (direction == SLIDE_LEFT)
		shift_and_merge_left(line, size);
	else
		shift_and_merge_right(line, size);

	return (1);
}
