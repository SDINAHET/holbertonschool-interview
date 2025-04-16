#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

int main(void)
{
    heap_t *root = NULL;
    heap_t *node;

    node = heap_insert(&root, 98);
    printf("Value inserted: %d\n", node->n);
    node = heap_insert(&root, 110);
    printf("Value inserted: %d\n", node->n);
    node = heap_insert(&root, 43);
    printf("Value inserted: %d\n", node->n);

    binary_tree_print(root);

    return (0);
}
