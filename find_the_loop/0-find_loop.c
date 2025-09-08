#include "lists.h"

/**
 * find_listint_loop - Finds the start node of a loop in a singly linked list.
 * @head: Pointer to the head of the list.
 *
 * Return: Address of the node where the loop starts, or NULL if there is no
 * loop.
 *
 * Constraints respected:
 * - No malloc/free/arrays
 * - Max two variables
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *slow = head, *fast = head;

	/* Detect cycle using Floyd's Tortoise and Hare */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
			break;
	}

	/* No loop found */
	if (!fast || !fast->next)
		return (NULL);

	/* Find entry point of the loop */
	slow = head;
	while (slow != fast)
	{
		slow = slow->next;
		fast = fast->next;
	}

	return (slow);
}
