#include "sort.h"

void switch_ints(int *a, int *b);
void large_heapify(int *array, size_t size, size_t base, size_t root);
void heap_sort(int *array, size_t size);

/**
 * switch_ints - switches two integers in an array.
 * @a: First integer to switch.
 * @b: Second integer to switch.
 */
void switch_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * tree_2_heap - turns a binary tree to a complete binary heap.
 *
 * @array: array of integers representing a binary tree.
 * @size: size of binary.
 * @base: index of the tree base row.
 * @root: binary tree root node.
 */
void tree_2_heap(int *array, size_t size, size_t base, size_t root)
{
	size_t left, right, large;

	left = 2 * root + 1;
	right = 2 * root + 2;
	large = root;

	if (left < base && array[left] > array[large])
		large = left;
	if (right < base && array[right] > array[large])
		large = right;

	if (large != root)
	{
		switch_ints(array + root, array + large);
		print_array(array, size);
		tree_2_heap(array, size, base, large);
	}
}

/**
 * heap_sort - sorts an array of integers
 * in ascending order using the Heap sort algorithm.
 *
 * @array: array of integer.
 * @size: size of array.
 *
 * Description: Implements the sift-down heap sort
 * algorithm. Swaps two elements and prints it out.
 */
void heap_sort(int *array, size_t size)
{
	int y;

	if (array == NULL || size < 2)
		return;

	for (y = (size / 2) - 1; y >= 0; y--)
		tree_2_heap(array, size, size, y);

	for (y = size - 1; y > 0; y--)
	{
		switch_ints(array, array + y);
		print_array(array, size);
		tree_2_heap(array, size, y, 0);
	}
}
