#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "lists.h"

/* Helpers for checker-like scenarios */

static listint_t *make_list_ascending(size_t n)
{
	listint_t *head = NULL, *prev = NULL, *node = NULL;
	for (size_t i = 0; i < n; i++)
	{
		node = malloc(sizeof(*node));
		assert(node && "malloc failed");
		node->n = (int)i;
		node->next = NULL;
		if (!head)
			head = node;
		else
			prev->next = node;
		prev = node;
	}
	return head;
}

static listint_t *get_at(listint_t *head, size_t idx)
{
	while (head && idx--)
		head = head->next;
	return head;
}

static void break_loop_if_any(listint_t *head)
{
	listint_t *loop = find_listint_loop(head);
	if (!loop)
		return;
	/* Find the tail of the loop and break it */
	listint_t *p = loop;
	while (p->next != loop)
		p = p->next;
	p->next = NULL;
}

static void free_list(listint_t *head)
{
	listint_t *tmp;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

/* ----- Tests ----- */

static void case_two_nodes_last_to_first(void)
{
	listint_t *head = make_list_ascending(2);
	/* tail -> head */
	listint_t *tail = get_at(head, 1);
	tail->next = head;
	listint_t *res = find_listint_loop(head);
	assert(res == head);
	break_loop_if_any(head);
	free_list(head);
	printf("OK - two nodes loop to first\n");
}

static void case_single_self(void)
{
	listint_t *head = make_list_ascending(1);
	head->next = head;
	listint_t *res = find_listint_loop(head);
	assert(res == head);
	/* break loop and free */
	head->next = NULL;
	free_list(head);
	printf("OK - single node self-loop\n");
}

static void case_150_last_to_121st(void)
{
	const size_t N = 150;
	const size_t START = 120; /* 121st (0-based index) */
	listint_t *head = make_list_ascending(N);
	listint_t *start = get_at(head, START);
	assert(start && "bad index");
	/* tail -> node 120 (121st element) */
	listint_t *tail = get_at(head, N - 1);
	tail->next = start;

	listint_t *res = find_listint_loop(head);
	assert(res == start);

	/* break & free */
	break_loop_if_any(head);
	free_list(head);
	printf("OK - 150 nodes, tail->121st\n");
}

static void case_150_no_loop(void)
{
	const size_t N = 150;
	listint_t *head = make_list_ascending(N);
	assert(find_listint_loop(head) == NULL);
	free_list(head);
	printf("OK - 150 nodes, no loop\n");
}

static void case_null(void)
{
	assert(find_listint_loop(NULL) == NULL);
	printf("OK - NULL input\n");
}

static void case_150_no_loop_bis(void)
{
	const size_t N = 150;
	listint_t *head = make_list_ascending(N);
	assert(find_listint_loop(head) == NULL);
	free_list(head);
	printf("OK - 150 nodes, no loop (bis)\n");
}

int main(void)
{
	printf("Running checker-like tests...\n");
	case_two_nodes_last_to_first();
	case_single_self();
	case_150_last_to_121st();
	case_150_no_loop();
	case_null();
	case_150_no_loop_bis();
	printf("All checker-like tests passed ✅\n");
	return 0;
}
