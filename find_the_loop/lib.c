#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: pointer to the first node
 * @n: integer value to store
 *
 * Return: address of the new element, or NULL on failure
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
    listint_t *new;

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);
    new->n = n;
    new->next = *head;
    *head = new;
    return (new);
}

/**
 * print_listint_safe - prints a listint_t linked list (handles loops)
 * @head: pointer to the first node
 *
 * Return: number of nodes printed
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *slow = head, *fast = head;
    size_t count = 0, loop_found = 0;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            loop_found = 1;
            break;
        }
    }

    while (head)
    {
        printf("[%p] %d\n", (void *)head, head->n);
        count++;
        if (loop_found && head == slow)
        {
            printf("-> [%p] %d\n", (void *)head, head->n);
            break;
        }
        head = head->next;
    }
    return (count);
}

/**
 * free_listint_safe - frees a listint_t list even if it has a loop
 * @h: pointer to the first node
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
    listint_t *tmp;
    size_t count = 0;
    listint_t *slow = *h, *fast = *h;
    int loop_found = 0;

    if (!h || !*h)
        return (0);

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            loop_found = 1;
            break;
        }
    }

    while (*h)
    {
        tmp = *h;
        *h = (*h)->next;
        free(tmp);
        count++;
        if (loop_found && tmp == slow)
            break;
    }

    *h = NULL;
    return (count);
}
