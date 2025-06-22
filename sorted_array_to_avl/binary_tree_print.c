#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/* Base buffer size */
#define SPACE 10

/* Prototypes */
void binary_tree_print(const binary_tree_t *tree);
static void print_tree(const binary_tree_t *tree, int space);

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree to print
 *
 * Return: void
 */
void binary_tree_print(const binary_tree_t *tree)
{
    if (!tree)
        return;
    print_tree(tree, 0);
}

/**
 * print_tree - Recursive helper to print tree structure
 * @tree: Pointer to current node
 * @space: Current indentation level
 */
static void print_tree(const binary_tree_t *tree, int space)
{
    int i;

    if (!tree)
        return;

    space += SPACE;

    print_tree(tree->right, space);

    printf("\n");
    for (i = SPACE; i < space; i++)
        printf(" ");
    printf("(%03d)\n", tree->n);

    print_tree(tree->left, space);
}
