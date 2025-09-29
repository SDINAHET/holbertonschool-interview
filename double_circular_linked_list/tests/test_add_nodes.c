/* double_circular_linked_list/tests/test_add_nodes.c */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "../list.h"

/* ---------- Helpers ---------- */

static size_t list_len(List *head)
{
    size_t n = 0;
    List *cur;

    if (!head)
        return 0;
    cur = head;
    do {
        n++;
        cur = cur->next;
    } while (cur && cur != head);
    return n;
}

static int check_order_next(List *head, const char *exp[], size_t n)
{
    size_t i = 0;
    List *cur = head;

    if (!head && n == 0)
        return 1;
    if (!head || list_len(head) != n)
        return 0;

    for (i = 0; i < n; i++)
    {
        if (!cur || !cur->str || strcmp(cur->str, exp[i]) != 0)
            return 0;
        cur = cur->next;
    }
    return (cur == head);
}

static int check_order_prev_auto(List *head, const char *exp[], size_t n)
{
    size_t i;
    List *cur;

    if (!head && n == 0)
        return 1;
    if (!head || list_len(head) != n)
        return 0;

    cur = head->prev;
    for (i = 0; i < n; i++)
    {
        size_t idx = n - 1 - i; /* parcours inversé de exp */
        if (!cur || !cur->str || strcmp(cur->str, exp[idx]) != 0)
            return 0;
        cur = cur->prev;
    }
    return (cur == head->prev);
}

static void free_list(List *head)
{
    if (!head)
        return;

    List *cur = head->next;
    while (cur && cur != head)
    {
        List *next = cur->next;
        free(cur->str);
        free(cur);
        cur = next;
    }
    free(head->str);
    free(head);
}

/* ---------- Tests ---------- */

static int test_add_end_basic(void)
{
    List *list = NULL;
    const char *exp[] = {"Holberton", "School", "Full", "Stack", "Engineer"};
    size_t n = sizeof(exp) / sizeof(exp[0]);

    add_node_end(&list, "Holberton");
    add_node_end(&list, "School");
    add_node_end(&list, "Full");
    add_node_end(&list, "Stack");
    add_node_end(&list, "Engineer");

    int ok = check_order_next(list, exp, n);
    ok = ok && check_order_prev_auto(list, exp, n);
    ok = ok && list->prev->next == list && list->next->prev == list;

    free_list(list);
    return ok;
}

static int test_add_begin_basic(void)
{
    List *list = NULL;
    const char *exp[] = {"Engineer", "Stack", "Full", "School", "Holberton"};
    size_t n = sizeof(exp) / sizeof(exp[0]);

    add_node_begin(&list, "Holberton");
    add_node_begin(&list, "School");
    add_node_begin(&list, "Full");
    add_node_begin(&list, "Stack");
    add_node_begin(&list, "Engineer");

    int ok = check_order_next(list, exp, n);
    ok = ok && check_order_prev_auto(list, exp, n);
    ok = ok && list->prev->next == list && list->next->prev == list;

    free_list(list);
    return ok;
}

static int test_singleton(void)
{
    List *list = NULL;
    add_node_end(&list, "Solo");
    int ok = (list &&
              list->next == list &&
              list->prev == list &&
              strcmp(list->str, "Solo") == 0);
    free_list(list);

    list = NULL;
    add_node_begin(&list, "Solo");
    ok = ok && (list &&
                list->next == list &&
                list->prev == list &&
                strcmp(list->str, "Solo") == 0);
    free_list(list);
    return ok;
}

int main(void)
{
    int fails = 0;

    printf("Running tests for double circular linked list...\n");

    if (!test_add_end_basic())   { printf("[FAIL] add_node_end basic\n");   fails++; }
    else                         { printf("[ OK ] add_node_end basic\n"); }

    if (!test_add_begin_basic()) { printf("[FAIL] add_node_begin basic\n"); fails++; }
    else                         { printf("[ OK ] add_node_begin basic\n"); }

    if (!test_singleton())       { printf("[FAIL] singleton cases\n");      fails++; }
    else                         { printf("[ OK ] singleton cases\n"); }

    if (fails)
    {
        printf("=> %d test(s) failed\n", fails);
        return 1;
    }
    printf("=> All tests passed ✅\n");
    return 0;
}
