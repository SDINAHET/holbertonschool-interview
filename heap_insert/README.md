# 📚 Heap Insert

**Project badge:** 71.43%  
**Level:** Amateur  
**By:** Alexa Orrico, Software Engineer at Holberton School  
**Weight:** 1  
**Directory:** `heap_insert`

---

## 🧠 Description

This project involves implementing a function to insert a value into a **Max Binary Heap**, ensuring proper ordering. You will work with binary tree structures and respect the properties of a heap.

---

## ✅ Requirements

- Allowed editors: `vi`, `vim`, `emacs`
- All your files will be compiled on **Ubuntu 14.04 LTS**
- Programs compiled with:  
  `gcc 4.8.4 -Wall -Werror -Wextra -pedantic`
- No global variables allowed
- Max 5 functions per file
- All files should end with a new line
- Code must follow **Betty** style:  
  Checked with `betty-style.pl` and `betty-doc.pl`
- Use of the standard C library is allowed
- A file `README.md` is mandatory
- All prototypes should be in the file `binary_trees.h`
- Header files must be include guarded

---

## 🧩 Data Structures

```c
/**
 * struct binary_tree_s - Binary tree node
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
struct binary_tree_s
{
    int n;
    struct binary_tree_s *parent;
    struct binary_tree_s *left;
    struct binary_tree_s *right;
};

typedef struct binary_tree_s binary_tree_t;
typedef struct binary_tree_s heap_t;
```

---

## 🧪 Tasks

### 0. New Node

**File:** `0-binary_tree_node.c`  
**Prototype:**

```c
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
```

- Create a binary tree node
- Return NULL on failure

### 1. Heap Insert

**File:** `1-heap_insert.c`  
**Prototype:**

```c
heap_t *heap_insert(heap_t **root, int value);
```

- Inserts a value in a Max Binary Heap
- Must preserve Max Heap ordering
- Returns the newly inserted node

---

## 🛠️ Compilation

```bash
gcc -Wall -Wextra -Werror -pedantic binary_tree_print.c 1-main.c \
    1-heap_insert.c 0-binary_tree_node.c -o 1-heap_insert
./1-heap_insert
```

---

## 📸 Sample Output

```text
Inserted: 98
(098)

Inserted: 402
  .--(402)
(098)

Inserted: 12
  .--(402)--.
(098)     (012)

...
```

---

## 👤 Author

**Stéphane Dinahet**  
[GitHub Profile](https://github.com/SDINAHET)  
LinkedIn: [linkedin.com/in/stéphane-dinahet-3b363189](https://linkedin.com/in/stéphane-dinahet-3b363189)

---