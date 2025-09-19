#include <stdio.h>
#include "sort.h"

/**
 * main - Demo pour merge_sort avec sortie exacte
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    /* Tableau initial */
    print_array(array, n);
    printf("\n");

    /* Tri avec traces "Merging..." */
    merge_sort(array, n);

    printf("\n");
    /* Tableau final trié */
    print_array(array, n);

    return (0);
}
