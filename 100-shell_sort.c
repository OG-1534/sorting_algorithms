#include "sort.h"

/**
 * switch_ints - Switches 2 ints in an array.
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
 * shell_sort - sorts an array of integers in ascending order
 * using the Shell sort algorithm, using the Knuth sequence.
 *
 * @array: array of integers.
 * @size: array size.
 *
 * Description: print the array each time interval decreases.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, m, n;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (m = gap; m < size; m++)
		{
			n = m;
			while (n >= gap && array[n - gap] > array[n])
			{
				switch_ints(array + n, array + (n - gap));
				n -= gap;
			}
		}
		print_array(array, size);
	}
}
