#include <criterion/criterion.h>
#include <criterion/logging.h>
#include "../binary_trees.h"

/* Helpers pour construire des arbres rapidement */
static binary_tree_t *n(binary_tree_t *parent, int v)
{
    return binary_tree_node(parent, v);
}

/* Détruit récursivement (simple clean pour tests) */
static void free_tree(binary_tree_t *t)
{
    if (!t) return;
    free_tree(t->left);
    free_tree(t->right);
    free(t);
}

/* ---------- Tests ---------- */

Test(avl_is_avl, null_tree_returns_0)
{
    cr_assert_eq(binary_tree_is_avl(NULL), 0, "NULL doit renvoyer 0");
}

Test(avl_is_avl, single_node_is_avl)
{
    binary_tree_t *root = n(NULL, 42);
    cr_assert_eq(binary_tree_is_avl(root), 1, "Un seul nœud est AVL");
    free(root);
}

Test(avl_is_avl, perfect_small_avl)
{
    /*       20
     *     /    \
     *   10      30
     *  / \    /  \
     * 5  15  25  35
     */
    binary_tree_t *r = n(NULL, 20);
    r->left  = n(r, 10);
    r->right = n(r, 30);
    r->left->left  = n(r->left, 5);
    r->left->right = n(r->left, 15);
    r->right->left  = n(r->right, 25);
    r->right->right = n(r->right, 35);

    cr_assert_eq(binary_tree_is_avl(r), 1, "Arbre parfait doit être AVL");
    free_tree(r);
}

Test(avl_is_avl, bst_violation_left_child_greater)
{
    /*    10
     *   /
     *  12   <-- violation BST (12 > 10 à gauche)
     */
    binary_tree_t *r = n(NULL, 10);
    r->left = n(r, 12);

    cr_assert_eq(binary_tree_is_avl(r), 0, "Violation BST => pas AVL");
    free_tree(r);
}

Test(avl_is_avl, unbalanced_height_violation)
{
    /*    10
     *   /
     *  5
     * /
     * 2
     */
    binary_tree_t *r = n(NULL, 10);
    r->left = n(r, 5);
    r->left->left = n(r->left, 2);

    cr_assert_eq(binary_tree_is_avl(r), 0, "Déséquilibre (2 niveaux à gauche) => pas AVL");
    free_tree(r);
}

Test(avl_is_avl, balanced_but_not_bst_on_deeper_node)
{
    /*          20
     *        /    \
     *      10      30
     *        \
     *        25   <-- 25 est à droite de 10 (ok localement),
     *                  mais 25 > 20 et se trouve dans le sous-arbre gauche => pas BST
     */
    binary_tree_t *r = n(NULL, 20);
    r->left = n(r, 10);
    r->right = n(r, 30);
    r->left->right = n(r->left, 25);

    cr_assert_eq(binary_tree_is_avl(r), 0, "Doit vérifier les bornes globales BST");
    free_tree(r);
}

Test(avl_is_avl, example_like_statement_initial_is_avl)
{
    /* Basic tree de l’énoncé (équilibré au départ) :
     *        98
     *      /    \
     *    12      128
     *     \         \
     *     54         402
     *    /
     *   10
     */
    binary_tree_t *root = n(NULL, 98);
    root->left = n(root, 12);
    root->right = n(root, 128);
    root->left->right = n(root->left, 54);
    root->right->right = n(root->right, 402);
    root->left->left = n(root->left, 10);

    cr_assert_eq(binary_tree_is_avl(root), 1, "Le basic_tree de l’énoncé commence AVL");
    free_tree(root);
}

Test(avl_is_avl, example_like_statement_after_insert_not_avl)
{
    /* Même base, on ajoute 97 sous 128->left => déséquilibre/bst ok mais pas AVL */
    binary_tree_t *root = n(NULL, 98);
    root->left = n(root, 12);
    root->right = n(root, 128);
    root->left->right = n(root->left, 54);
    root->right->right = n(root->right, 402);
    root->left->left = n(root->left, 10);

    root->right->left = n(root->right, 97); /* comme dans l’exemple */
    cr_assert_eq(binary_tree_is_avl(root), 0, "Après insertion 97, l’arbre n’est plus AVL");
    free_tree(root);
}
