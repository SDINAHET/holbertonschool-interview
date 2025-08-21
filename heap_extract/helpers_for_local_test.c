#include <stdlib.h>
#include <stddef.h>
#include "binary_trees.h"

/* Sift-down par échange de valeurs, pour construire un max-heap */
static void sift_down_values(heap_t *node)
{
    heap_t *largest, *l, *r;
    int tmp;

    if (!node)
        return;

    while (1)
    {
        l = node->left;
        r = node->right;
        largest = node;

        if (l && l->n > largest->n)
            largest = l;
        if (r && r->n > largest->n)
            largest = r;

        if (largest == node)
            break;

        tmp = node->n;
        node->n = largest->n;
        largest->n = tmp;
        node = largest;
    }
}

/* Construit un arbre complet depuis un array puis heapify bottom-up */
heap_t *_array_to_heap(int *array, size_t size)
{
    heap_t **nodes;
    size_t i;

    if (!array || size == 0)
        return (NULL);

    nodes = malloc((size + 1) * sizeof(*nodes)); /* index 1..size */
    if (!nodes)
        return (NULL);

    for (i = 1; i <= size; i++)
    {
        nodes[i] = malloc(sizeof(*nodes[i]));
        if (!nodes[i])
            return (NULL);
        nodes[i]->n = array[i - 1];
        nodes[i]->parent = NULL;
        nodes[i]->left = NULL;
        nodes[i]->right = NULL;
    }

    /* Lier en arbre complet (indices de tas) */
    for (i = 1; i <= size; i++)
    {
        size_t li = i * 2, ri = i * 2 + 1;
        if (li <= size)
        {
            nodes[i]->left = nodes[li];
            nodes[li]->parent = nodes[i];
        }
        if (ri <= size)
        {
            nodes[i]->right = nodes[ri];
            nodes[ri]->parent = nodes[i];
        }
    }

    /* Heapify bottom-up par échanges de valeurs */
    for (i = size / 2; i >= 1; i--)
    {
        sift_down_values(nodes[i]);
        if (i == 1) /* éviter le wrap autour de size_t */
            break;
    }

    heap_t *root = nodes[1];
    free(nodes);
    return (root);
}

/* Libération post-ordre */
void _binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;
    _binary_tree_delete(tree->left);
    _binary_tree_delete(tree->right);
    free(tree);
}
