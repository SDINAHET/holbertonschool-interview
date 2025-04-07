# Insert in Sorted Linked List

> Technical interview preparation task from Holberton School

![Project badge](https://img.shields.io/badge/level-Novice-brightgreen)
![Language](https://img.shields.io/badge/language-C-blue)
![Weight](https://img.shields.io/badge/weight-1-lightgrey)
![Maintainer](https://img.shields.io/badge/by-Carrie%20Ybay-orange)

---

## 📚 Description

This project is designed to help you prepare for technical interviews by implementing an essential data structure algorithm in C: inserting a node into a **sorted singly linked list**.  
You will write a function that inserts a number in the correct position in a sorted linked list while maintaining the order.

---

## ✅ Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on **Ubuntu 14.04 LTS**
- Compiler: `gcc 4.8.4`
- Compilation flags: `-Wall -Werror -Wextra -pedantic`
- Your code must follow **Betty coding style**
- No global variables allowed
- Max 5 functions per file
- All files must end with a new line
- Header file: `lists.h` (must contain all function prototypes)
- All your header files must be include guarded
- You must have a `README.md` at the root of your folder
- The provided `main.c` files are only for testing and **should not be pushed**
- Evaluation will be done using different `main.c` files

---

## 📁 File Structure

```
insert_in_sorted_linked_list/
├── 0-insert_number.c       # Main implementation
├── lists.h                 # Header file with struct and prototypes
├── linked_lists.c          # Helper functions (print, add, free)
├── 0-main.c                # Test file (optional)
└── README.md               # Project documentation
```

---

## 🔧 Function Prototype

```c
listint_t *insert_node(listint_t **head, int number);
```

- Inserts a number into a sorted singly linked list
- Returns the address of the new node, or `NULL` on failure

---

## 🧠 Struct Definition

Defined in `lists.h`:

```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

---

## 🛠️ Helper Functions

From `linked_lists.c`:

- `print_listint`: Prints all elements of a `listint_t` list
- `add_nodeint_end`: Adds a node to the end of the list
- `free_listint`: Frees all nodes in the list

---

## 🧪 Example Usage

```bash
$ gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-insert_number.c -o insert
$ ./insert
```

### Output

```
0
1
2
3
4
98
402
1024
-----------------
0
1
2
3
4
27
98
402
1024
```

---

📅 Tasks

0. Insert in sorted linked list (Mandatory)

Technical interview preparation

You are not allowed to google anything

Whiteboard first

Write a function in C that inserts a number into a sorted singly linked list.

Prototype:

listint_t *insert_node(listint_t **head, int number);

Return: the address of the new node, or NULL if it failed

// Header file: lists.h
#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint(listint_t *head);

listint_t *insert_node(listint_t **head, int number);

#endif /* LISTS_H */

// linked_lists.c (helper functions)
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

size_t print_listint(const listint_t *h)
{
    const listint_t *current;
    unsigned int n;

    current = h;
    n = 0;
    while (current != NULL)
    {
        printf("%i\n", current->n);
        current = current->next;
        n++;
    }
    return (n);
}

listint_t *add_nodeint_end(listint_t **head, const int n)
{
    listint_t *new;
    listint_t *current;

    current = *head;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
        return (NULL);

    new->n = n;
    new->next = NULL;

    if (*head == NULL)
        *head = new;
    else
    {
        while (current->next != NULL)
            current = current->next;
        current->next = new;
    }
    return (new);
}

void free_listint(listint_t *head)
{
    listint_t *current;

    while (head != NULL)
    {
        current = head;
        head = head->next;
        free(current);
    }
}

// 0-main.c (test example)
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

int main(void)
{
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);

    printf("-----------------\n");

    insert_node(&head, 27);

    print_listint(head);
    free_listint(head);
    return (0);
}



## ✍️ Author

**Carrie Ybay**  
*Software Engineer at Holberton School*

---

## 📌 Notes

- This task is part of the Holberton School technical interview preparation.
- **No internet** is allowed during the test.
- Always plan on **paper or whiteboard first** before coding.

---

> 🏁 Repository: `holbertonschool-interview`  
> 📂 Directory: `insert_in_sorted_linked_list`  
> 📄 Files: `0-insert_number.c`, `lists.h`

