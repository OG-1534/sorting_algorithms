#ifndef _SORT_H_
#define _SORT_H_

#include <stdio.h>
#include <stdlib.h>

/* Macros defining the direction of comparisons for bitonic sort */
#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration representing Boolean values.
 * @false: Represents the value 0.
 * @true: Represents the value 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* prototypes for 0-bubble_sort.c */
void swops_ints(int *a, int *b);
void bubble_sort(int *array, size_t size);

/* prototypes for print_array.c */
void print_array(const int *array, size_t size);

/* prototypes for print_list.c */
void print_list(const listint_t *list);

/* prototypes for 1-insertion_sort_list.c */
void insertion_sort_list(listint_t **list);
void switch_nodes(listint_t **h, listint_t **n1, listint_t *n2);

/* prototypes for 2-selection_sort.c */
void switch_ints(int *a, int *b);
void selection_sort(int *array, size_t size);

/* prototypes for 3-quick_sort.c */
int lomutoscheme_partition(int *array, size_t size, int left, int right);
void lomutoscheme_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/*protypes for 100-sell_sort.c*/
void shell_sort(int *array, size_t size);

/*101-cocktail_sort.c*/
void cocktail_sort_list(listint_t **list);

/* prototype for 102-countin_sort.c*/
void counting_sort(int *array, size_t size);

/*prototypes for 103-mere_sort.c*/
void merge_sort(int *array, size_t size);

/*104-heap_sort.c prototype*/
void heap_sort(int *array, size_t size);

/*105-radix_sort.c prototype */
void radix_sort(int *array, size_t size);

/*106-bitonic_sort.c prototype*/
void bitonic_sort(int *array, size_t size);

/*107-quick_sort_sort_oare.c prototypes*/
void quick_sort_hoare(int *array, size_t size);

#endif /* SORT_H */
