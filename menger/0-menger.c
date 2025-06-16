#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * is_blank - Check if the current position should be a blank
 * @x: x coordinate
 * @y: y coordinate
 *
 * Return: 1 if position is blank, 0 otherwise
 */
int is_blank(int x, int y)
{
	while (x > 0 || y > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
			return (1);
		x /= 3;
		y /= 3;
	}
	return (0);
}

/**
 * menger - Draw a 2D Menger sponge of given level
 * @level: level of the sponge
 */
void menger(int level)
{
	int size, x, y;

	if (level < 0)
		return;

	size = pow(3, level);

	for (y = 0; y < size; y++)
	{
		for (x = 0; x < size; x++)
		{
			if (is_blank(x, y))
				printf(" ");
			else
				printf("#");
		}
		printf("\n");
	}
}
