#include <stdio.h>
#include <stdlib.h>
#include "../binary_trees.h"

/* Helpers */
static binary_tree_t *n(binary_tree_t *p, int v) { return binary_tree_node(p, v); }
static void free_tree(binary_tree_t *t){ if(!t) return; free_tree(t->left); free_tree(t->right); free(t); }

static int assert_eq(const char *name, int got, int exp){
    if (got != exp){
        fprintf(stderr, "[FAIL] %s: got=%d expected=%d\n", name, got, exp);
        return 1;
    }
    printf("[OK]   %s\n", name);
    return 0;
}

int main(void)
{
    int fails = 0;

    /* NULL -> 0 */
    fails += assert_eq("null_tree_returns_0", binary_tree_is_avl(NULL), 0);

    /* single node */
    binary_tree_t *r = n(NULL, 42);
    fails += assert_eq("single_node_is_avl", binary_tree_is_avl(r), 1);
    free(r);

    /* perfect small avl */
    r = n(NULL, 20);
    r->left = n(r, 10); r->right = n(r, 30);
    r->left->left = n(r->left, 5); r->left->right = n(r->left, 15);
    r->right->left = n(r->right, 25); r->right->right = n(r->right, 35);
    fails += assert_eq("perfect_small_avl", binary_tree_is_avl(r), 1);
    free_tree(r);

    /* BST violation */
    r = n(NULL, 10);
    r->left = n(r, 12); /* >10 à gauche => pas BST */
    fails += assert_eq("bst_violation_left_child_greater", binary_tree_is_avl(r), 0);
    free_tree(r);

    /* Unbalanced */
    r = n(NULL, 10);
    r->left = n(r, 5);
    r->left->left = n(r->left, 2);
    fails += assert_eq("unbalanced_height_violation", binary_tree_is_avl(r), 0);
    free_tree(r);

    /* Global BST check in ranges */
    r = n(NULL, 20);
    r->left = n(r, 10);
    r->right = n(r, 30);
    r->left->right = n(r->left, 25); /* 25 à gauche de 20 -> violation BST globale */
    fails += assert_eq("balanced_but_not_bst_on_deeper_node", binary_tree_is_avl(r), 0);
    free_tree(r);

    /* Exemple initial (AVL) */
    r = n(NULL, 98);
    r->left = n(r, 12);
    r->right = n(r, 128);
    r->left->right = n(r->left, 54);
    r->right->right = n(r->right, 402);
    r->left->left = n(r->left, 10);
    fails += assert_eq("example_initial_is_avl", binary_tree_is_avl(r), 1);
    free_tree(r);

    /* Après insertion 97 sous 128->left (non AVL) */
    r = n(NULL, 98);
    r->left = n(r, 12);
    r->right = n(r, 128);
    r->left->right = n(r->left, 54);
    r->right->right = n(r->right, 402);
    r->left->left = n(r->left, 10);
    r->right->left = n(r->right, 97);
    fails += assert_eq("example_after_insert_not_avl", binary_tree_is_avl(r), 0);
    free_tree(r);

    if (fails) {
        fprintf(stderr, "\n%d test(s) failed ❌\n", fails);
        return 1;
    }
    printf("\nAll tests passed ✅\n");
    return 0;
}
