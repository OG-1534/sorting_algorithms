#include "sort.h"

/**
 * swops_ints - swaps two integers in an array.
 *
 * @a: 1st integer pointer.
 * @b: 2nd integer pointer.
 */
void swops_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * bubble_sort - sorts an array of integers in ascending
 * order using the bubble sort algorithm.
 *
 * @array: array of integers to be sorted.
 * @size: size of array
 *
 * Description: prints the array each time you swap two elements.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, len = size;
	bool bubbly = false;

	if (array == NULL || size < 2)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (i = 0; i < len - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swops_ints(array + i, array + i + 1);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}
