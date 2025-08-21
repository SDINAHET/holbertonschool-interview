#include <stdio.h>
#include "binary_trees.h"

/* Simple pretty-printer for visualization only */
static int print_t(const binary_tree_t *tree, int is_left, int offset,
		   int depth, char s[20][255])
{
	char b[6];
	int width = 5;
	int left, right, i;

	if (!tree)
		return (0);

	sprintf(b, "(%03d)", tree->n);

	left = print_t(tree->left, 1, offset, depth + 1, s);
	right = print_t(tree->right, 0, offset + left + width, depth + 1, s);

	for (i = 0; i < width; i++)
		s[depth][offset + left + i] = b[i];

	if (depth && is_left)
	{
		for (i = 0; i < width + right; i++)
			s[depth - 1][offset + left + (width / 2) + i] = '-';
		s[depth - 1][offset + left + (width / 2)] = '.';
	}
	else if (depth && !is_left)
	{
		for (i = 0; i < left + width; i++)
			s[depth - 1][offset - (width / 2) + i] = '-';
		s[depth - 1][offset + left + (width / 2)] = '.';
	}
	return (left + width + right);
}

void binary_tree_print(const binary_tree_t *tree)
{
	char s[20][255];
	int i, j;

	if (!tree)
		return;

	for (i = 0; i < 20; i++)
	{
		for (j = 0; j < 254; j++)
			s[i][j] = ' ';
		s[i][254] = '\0';
	}

	(void)print_t(tree, 0, 0, 0, s);

	for (i = 0; i < 20; i++)
		printf("%s\n", s[i]);
}
