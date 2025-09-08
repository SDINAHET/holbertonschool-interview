/* test_find_loop.c */
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lists.h"

/* Helpers de test (n’entrent pas dans la correction) */

static listint_t *make_list_from_array(const int *a, size_t n)
{
	listint_t *head = NULL, *node, *prev = NULL;
	for (size_t i = 0; i < n; i++)
	{
		node = malloc(sizeof(*node));
		assert(node && "malloc failed in test helper");
		node->n = a[i];
		node->next = NULL;
		if (!head)
			head = node;
		else
			prev->next = node;
		prev = node;
	}
	return head;
}

/* pos >= 0 : crée une boucle en reliant la queue au nœud d’index pos
 * pos == -1 : pas de boucle
 * Retourne l’adresse du nœud où commence la boucle (ou NULL) */
static listint_t *inject_loop(listint_t *head, int pos)
{
	if (pos < 0 || !head)
		return NULL;

	listint_t *loop_start = NULL, *tail = head;
	int idx = 0;

	while (tail->next)
	{
		if (idx == pos)
			loop_start = tail;
		tail = tail->next;
		idx++;
	}
	if (idx == pos) /* si la boucle doit commencer au dernier nœud */
		loop_start = tail;

	assert(loop_start && "invalid loop position in test");
	tail->next = loop_start;
	return loop_start;
}

/* Libère une liste potentiellement bouclée :
 * utilise find_listint_loop pour casser la boucle avant free */
static void free_list_safely(listint_t *head)
{
	if (!head)
		return;

	/* Essaye de détecter le départ de boucle avec la fonction à tester */
	listint_t *loop = find_listint_loop(head);
	if (loop)
	{
		/* trouve la queue de la boucle et casse-la */
		listint_t *p = loop;
		while (p->next != loop)
			p = p->next;
		p->next = NULL; /* boucle cassée */
	}

	/* free classique */
	listint_t *tmp;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/* ---------- TESTS ---------- */

static void test_empty_list(void)
{
	listint_t *head = NULL;
	assert(find_listint_loop(head) == NULL);
}

static void test_single_no_loop(void)
{
	int a[] = {42};
	listint_t *head = make_list_from_array(a, 1);
	assert(find_listint_loop(head) == NULL);
	free_list_safely(head);
}

static void test_single_self_loop(void)
{
	int a[] = {7};
	listint_t *head = make_list_from_array(a, 1);
	(void)inject_loop(head, 0);
	listint_t *res = find_listint_loop(head);
	assert(res == head);
	free_list_safely(head);
}

static void test_two_nodes_loop_to_head(void)
{
	int a[] = {1, 2};
	listint_t *head = make_list_from_array(a, 2);
	listint_t *expected = inject_loop(head, 0); /* tail -> head */
	listint_t *res = find_listint_loop(head);
	assert(res == expected);
	free_list_safely(head);
}

static void test_middle_loop(void)
{
	int a[] = {0, 1, 2, 3, 4, 5};
	listint_t *head = make_list_from_array(a, 6);
	listint_t *expected = inject_loop(head, 2); /* boucle commence sur valeur 2 */
	listint_t *res = find_listint_loop(head);
	assert(res == expected);
	free_list_safely(head);
}

static void test_loop_at_head_longer(void)
{
	int a[] = {10, 20, 30, 40, 50, 60, 70};
	listint_t *head = make_list_from_array(a, 7);
	listint_t *expected = inject_loop(head, 0);
	listint_t *res = find_listint_loop(head);
	assert(res == expected);
	free_list_safely(head);
}

static void test_no_loop_longer(void)
{
	int a[] = {5, 6, 7, 8, 9};
	listint_t *head = make_list_from_array(a, 5);
	assert(find_listint_loop(head) == NULL);
	free_list_safely(head);
}

int main(void)
{
	printf("Running unit tests for find_listint_loop...\n");

	test_empty_list();
	test_single_no_loop();
	test_single_self_loop();
	test_two_nodes_loop_to_head();
	test_middle_loop();
	test_loop_at_head_longer();
	test_no_loop_longer();

	printf("All tests passed ✅\n");
	return 0;
}
