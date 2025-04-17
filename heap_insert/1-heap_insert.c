#include <stdlib.h>
#include "binary_trees.h"

/**
 * node_count - Counts the number of nodes in a binary tree
 * @tree: Pointer to the root node of the tree
 * Return: Number of nodes
 */
int node_count(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * ins_max_heap - Recursively inserts a new node at the correct index
 * @node: Current node
 * @new_node: New node to insert
 * @index: Current index
 * @new_node_index: Target index to insert at
 * Return: Pointer to root node
 */
heap_t *ins_max_heap(heap_t *node, heap_t *new_node,
				int index, int new_node_index)
{
	if (index > new_node_index)
		return (NULL);
	if (index == new_node_index)
		return (new_node);

	node->left = ins_max_heap(node->left, new_node, index * 2 + 1, new_node_index);
	if (node->left)
		node->left->parent = node;

	node->right = ins_max_heap(node->right, new_node, index * 2 + 2, new_node_index);
	if (node->right)
		node->right->parent = node;

	return (node);
}

/**
 * bottom_up_heapify - Restores the max heap property from bottom up
 * @node: Pointer to the newly inserted node
 * Return: Pointer to inserted node (unchanged)
 */
heap_t *bottom_up_heapify(heap_t *node)
{
	heap_t *temp = node;
	int tmp_val;

	while (temp->parent && temp->n > temp->parent->n)
	{
		tmp_val = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = tmp_val;
		temp = temp->parent;
	}
	return (node);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to root node
 * @value: Value to insert
 * Return: Pointer to inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	int size;
	heap_t *new_node = NULL;

	if (!root)
		return (NULL);

	new_node = binary_tree_node(NULL, value);
	if (!new_node)
		return (NULL);

	if (!*root)
	{
		*root = new_node;
		return (new_node);
	}

	size = node_count(*root) + 1;
	ins_max_heap(*root, new_node, 0, size - 1);
	return (bottom_up_heapify(new_node));
}
