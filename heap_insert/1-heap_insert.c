#include <stdlib.h>
#include "binary_trees.h"

int node_count(const heap_t *tree);
heap_t *ins_max_heap(heap_t *node, heap_t *new_node, int index,
						 int new_node_index);
heap_t *bottom_up_heapify(heap_t *node);

/**
 * heap_insert - Insère une valeur dans un tas binaire maximum
 * @root: Double pointeur vers le nœud racine du tas où insérer la valeur
 * @value: Valeur à stocker dans le nœud à insérer
 * Return: Pointeur vers le nœud créé, ou NULL en cas d'échec
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

	size = node_count(*root) + 1;
	*root = ins_max_heap(*root, new_node, 0, size - 1);

	return (bottom_up_heapify(new_node));
}

/**
 * node_count - Compte le nombre total de nœuds dans un arbre binaire
 * @tree: Pointeur vers le nœud racine de l'arbre à compter
 * Return: Le nombre de nœuds dans l'arbre
 */
int node_count(const heap_t *tree)
{
	if (!tree)
		return (0);
	return (1 + node_count(tree->left) + node_count(tree->right));
}

/**
 * ins_max_heap - Insère une valeur dans un tas binaire maximum
 * @node: Pointeur vers le nœud racine du tas où insérer la valeur
 * @new_node: Valeur à stocker dans le nœud à insérer
 * @index: Indice du nœud actuel
 * @new_node_index: Indice du nouveau nœud
 * Return: Pointeur vers le nœud créé, ou NULL en cas d'échec
 */
heap_t *ins_max_heap(heap_t *node, heap_t *new_node,
						 int index, int new_node_index)

{
	if (index > new_node_index)
		return (NULL);
	if (index == new_node_index)
		return (new_node);

	node->left = ins_max_heap(node->left, new_node,
							  index * 2 + 1, new_node_index);
	if (node->left)
		node->left->parent = node;

	node->right = ins_max_heap(node->right, new_node,
							   index * 2 + 2, new_node_index);
	if (node->right)
		node->right->parent = node;

	return (node);
}

/**
 * bottom_up_heapify - Réorganise un tas binaire maximum de bas en haut
 * Description : Cette fonction échange la valeur d'un nœud avec la valeur de
 * son parent tant que la valeur du nœud est supérieure à celle de son
 * parent.
 *
 * @node: Pointeur vers le nœud racine du tas à réorganiser
 * Return: Pointeur vers le nœud racine du tas
 */
heap_t *bottom_up_heapify(heap_t *node)
{
	heap_t *temp = node;
	int temp_n;

	while (temp->parent && temp->n > temp->parent->n)
	{
		temp_n = temp->n;
		temp->n = temp->parent->n;
		temp->parent->n = temp_n;
		temp = temp->parent;
	}
	return (temp);
}
