#include <stddef.h>   /* pour size_t */
#include <stdlib.h>
#include "binary_trees.h"

/* ======== Helpers prototypes (file-local) ======== */
static size_t binary_tree_size(const heap_t *tree);
static heap_t *node_at_index(heap_t *root, size_t index);
static void heap_sift_down(heap_t *node);

/**
 * heap_extract - Extracts the root value of a Max Binary Heap
 * @root: Double pointer to root node of the heap
 *
 * Return: Value stored in the root node on success, 0 on failure
 */
int heap_extract(heap_t **root)
{
	int value;
	size_t size;
	heap_t *last, *parent;

	if (!root || !*root)
		return (0);

	value = (*root)->n;

	/* If only one node, free it and reset root */
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		return (value);
	}

	/* Find last node (deepest, rightmost) using 1-based index == size */
	size = binary_tree_size(*root);
	last = node_at_index(*root, size);
	if (!last)
		return (0);

	/* Move last's value to root, detach last from its parent, free last */
	(*root)->n = last->n;
	parent = last->parent;
	if (parent->left == last)
		parent->left = NULL;
	else
		parent->right = NULL;
	free(last);

	/* Restore heap property by sifting down from new root value */
	heap_sift_down(*root);

	return (value);
}

/**
 * binary_tree_size - Computes size (number of nodes) of a binary tree
 * @tree: Pointer to tree root
 *
 * Return: Size of the tree
 */
static size_t binary_tree_size(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + binary_tree_size(tree->left) + binary_tree_size(tree->right));
}

/**
 * node_at_index - Returns the node at a given 1-based index in a complete tree
 *                 following array-heap indexing, using the path from root
 * @root: Pointer to root
 * @index: 1-based index of desired node
 *
 * Return: Pointer to node at index, or NULL on failure
 */
static heap_t *node_at_index(heap_t *root, size_t index)
{
	size_t mask;
	heap_t *curr = root;

	if (!root || index == 0)
		return (NULL);

	/* Build a mask for the highest bit below the MSB of index */
	for (mask = 1; mask <= index; mask <<= 1)
		;
	/* mask is now first power of two > index; we want bit below MSB */
	mask >>= 2;

	/* Traverse bits (0 => left, 1 => right) excluding MSB */
	while (mask > 0 && curr)
	{
		if (index & mask)
			curr = curr->right;
		else
			curr = curr->left;
		mask >>= 1;
	}

	return (curr);
}

/**
 * heap_sift_down - Restores Max Heap property by sifting a node downwards
 * @node: Pointer to starting node
 */
static void heap_sift_down(heap_t *node)
{
	heap_t *largest, *left, *right;
	int tmp;

	if (!node)
		return;

	while (1)
	{
		left = node->left;
		right = node->right;
		largest = node;

		if (left && left->n > largest->n)
			largest = left;
		if (right && right->n > largest->n)
			largest = right;

		if (largest == node)
			break;

		/* Swap values with the larger child */
		tmp = node->n;
		node->n = largest->n;
		largest->n = tmp;

		node = largest;
	}
}
