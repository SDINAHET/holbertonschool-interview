#include "binary_trees.h"
#include <limits.h>

/**
 * tree_is_avl - Recursively checks if a binary tree is a valid AVL tree.
 *               In one pass, it validates BST property within (min, max),
 *               checks balance factor (|hl - hr| <= 1), and returns height.
 *
 * @node: Pointer to current node.
 * @min:  Strict lower bound allowed for node->n (all keys must be > min).
 * @max:  Strict upper bound allowed for node->n (all keys must be < max).
 * @h:    Out parameter: set to the height (in nodes) of the subtree.
 *
 * Return: 1 if subtree rooted at @node is a valid AVL tree, otherwise 0.
 */
static int tree_is_avl(const binary_tree_t *node, long min, long max, int *h)
{
	int hl = 0, hr = 0;

	if (node == NULL)
	{
		*h = 0; /* empty subtree has height 0 (in nodes) */
		return (1);
	}

	/* Strict BST range check to avoid duplicates and overflow issues */
	if ((long)node->n <= min || (long)node->n >= max)
		return (0);

	/* Left subtree must be AVL with values in (min, node->n) */
	if (!tree_is_avl(node->left, min, (long)node->n, &hl))
		return (0);

	/* Right subtree must be AVL with values in (node->n, max) */
	if (!tree_is_avl(node->right, (long)node->n, max, &hr))
		return (0);

	/* Balance factor check: difference of heights cannot exceed 1 */
	if (hl - hr > 1 || hr - hl > 1)
		return (0);

	/* Height of current node (in nodes): max(hl, hr) + 1 */
	*h = (hl >= hr ? hl : hr) + 1;
	return (1);
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if @tree is a valid AVL tree, 0 otherwise.
 *
 * Notes:
 * - An AVL tree is a strict BST (no duplicate keys).
 * - For every node, |height(left) - height(right)| <= 1.
 * - Heights here are counted in number of nodes.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int h = 0;

	if (tree == NULL)
		return (0);

	return (tree_is_avl(tree, (long)LONG_MIN, (long)LONG_MAX, &h));
}
