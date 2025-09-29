#include <stdlib.h>
#include <string.h>
#include "list.h"

/**
 * create_node - allocate and initialize a new list node
 * @str: string to duplicate into the node
 *
 * Return: pointer to the new node, or NULL on failure
 */
static List *create_node(char *str)
{
	List *node;
	char *dup;

	if (!str)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	dup = strdup(str);
	if (!dup)
	{
		free(node);
		return (NULL);
	}

	node->str = dup;
	node->prev = node;
	node->next = node;

	return (node);
}

/**
 * add_node_end - add a new node to the end of a double circular linked list
 * @list: address of the head pointer of the list
 * @str: string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_end(List **list, char *str)
{
	List *new, *tail;

	if (!list)
		return (NULL);

	new = create_node(str);
	if (!new)
		return (NULL);

	if (!*list) /* empty list -> new node points to itself */
	{
		*list = new;
		return (new);
	}

	/* Non-empty: insert between tail and head */
	tail = (*list)->prev;

	new->next = *list;
	new->prev = tail;

	tail->next = new;
	(*list)->prev = new;

	return (new);
}

/**
 * add_node_begin - add a new node to the beginning of a double circular list
 * @list: address of the head pointer of the list
 * @str: string to copy into the new node
 *
 * Return: address of the new node, or NULL on failure
 */
List *add_node_begin(List **list, char *str)
{
	List *new;

	if (!list)
		return (NULL);

	new = add_node_end(list, str);
	if (!new)
		return (NULL);

	/* Move head to the newly inserted node */
	*list = new;

	return (new);
}
