#ifndef BINARY_TREES_H
#define BINARY_TREES_H

#include <stddef.h>
#include <stdlib.h>

/**
 * struct binary_tree_s - Node of binary tree
 * @n: Value stored
 * @parent: Pointer to parent node
 * @left: Pointer to left child
 * @right: Pointer to right child
 */
struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s avl_t;

binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);

#endif /* BINARY_TREES_H */
