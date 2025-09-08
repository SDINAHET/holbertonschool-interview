#include <stdio.h>
#include "lists.h"

int main(void)
{
	/* Two static nodes: last points to first (loop) */
	listint_t a, b;
	a.n = 1; a.next = &b;
	b.n = 7; b.next = &a;

	listint_t *loop = find_listint_loop(&a);
	if (loop)
		printf("Loop starts at [%p] %d\n", (void *)loop, loop->n);

	/* Single node self-loop */
	listint_t single;
	single.n = 42; single.next = &single;
	loop = find_listint_loop(&single);
	if (loop)
		printf("Loop starts at [%p] %d\n", (void *)loop, loop->n);

	/* NULL case */
	if (find_listint_loop(NULL) == NULL)
		printf("NULL case OK\n");

	return 0;
}
