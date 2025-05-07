#include "lists.h"
#include <stdlib.h>

/**
 * reverse_list - Reverses a singly linked list
 * @head: Pointer to the head of the list
 * Return: New head of the reversed list
 */
listint_t *reverse_list(listint_t *head)
{
	listint_t *prev = NULL, *current = head, *next = NULL;

	while (current)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	return (prev);
}

/**
 * is_palindrome - Checks if a singly linked list is a palindrome
 * @head: Double pointer to the head of the list
 * Return: 1 if it is a palindrome, 0 otherwise
 */
int is_palindrome(listint_t **head)
{
	listint_t *slow, *fast, *second_half, *reversed, *copy1, *copy2;

	if (!head || !(*head) || !(*head)->next)
		return (1);

	slow = fast = *head;

	/* Find the middle (slow will point to the middle node) */
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	/* For odd number of nodes, move slow one step further */
	if (fast)
		slow = slow->next;

	/* Reverse the second half of the list */
	reversed = reverse_list(slow);
	second_half = reversed;

	/* Compare first and second half */
	copy1 = *head;
	copy2 = reversed;
	while (copy2)
	{
		if (copy1->n != copy2->n)
		{
			reverse_list(second_half); /* Restore list */
			return (0);
		}
		copy1 = copy1->next;
		copy2 = copy2->next;
	}

	reverse_list(second_half); /* Restore list */
	return (1);
}
