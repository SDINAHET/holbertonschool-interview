#include "binary_trees.h"

/**
 * build_avl - Recursively builds a balanced AVL tree from a sorted array
 * @array: Pointer to the first element of the array
 * @start: Starting index
 * @end: Ending index
 * @parent: Pointer to parent node
 *
 * Return: Pointer to the created node, or NULL on failure
 */
avl_t *build_avl(int *array, int start, int end, avl_t *parent)
{
	int mid;
	avl_t *node;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;
	node = binary_tree_node(parent, array[mid]);
	if (!node)
		return (NULL);

	node->left = build_avl(array, start, mid - 1, node);
	node->right = build_avl(array, mid + 1, end, node);

	return (node);
}

/**
 * sorted_array_to_avl - Builds an AVL tree from a sorted array
 * @array: Pointer to array
 * @size: Number of elements in array
 *
 * Return: Pointer to root node of AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (!array || size == 0)
		return (NULL);
	return (build_avl(array, 0, (int)size - 1, NULL));
}
