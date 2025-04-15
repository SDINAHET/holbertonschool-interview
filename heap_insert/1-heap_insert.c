#include "binary_trees.h"

/**
 * swap_nodes - Swap values of two nodes
 * @a: First node
 * @b: Second node
 */
static void swap_nodes(heap_t *a, heap_t *b)
{
	int tmp = a->n;

	a->n = b->n;
	b->n = tmp;
}

/**
 * heapify_up - Maintains Max Heap order from inserted node
 * @node: Newly inserted node
 */
static void heapify_up(heap_t *node)
{
	while (node->parent && node->n > node->parent->n)
	{
		swap_nodes(node, node->parent);
		node = node->parent;
	}
}

/**
 * find_insertion_point - Finds the first available position in level order
 * @root: Root of the heap
 *
 * Return: Pointer to the parent node for the new insertion
 */
static heap_t *find_insertion_point(heap_t *root)
{
	heap_t *queue[1024];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear)
	{
		heap_t *node = queue[front++];

		if (!node->left || !node->right)
			return (node);

		queue[rear++] = node->left;
		queue[rear++] = node->right;
	}
	return (NULL);
}

/**
 * heap_insert - Inserts a value into a Max Binary Heap
 * @root: Double pointer to the root node
 * @value: Value to insert
 *
 * Return: Pointer to the inserted node or NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}

	parent = find_insertion_point(*root);

	if (!parent)
		return (NULL);

	if (!parent->left)
		parent->left = binary_tree_node(parent, value);
	else
		parent->right = binary_tree_node(parent, value);

	new_node = parent->left ? parent->left : parent->right;

	heapify_up(new_node);

	return (new_node);
}
