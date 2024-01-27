#include "sort.h"

/**
 * switch_ints - switch the values of two integers in an array.
 * @a: first integer to switch.
 * @b: second integer to switch.
 */
void switch_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * selection_sort - sorts an array of integers in ascending
 * order using the Selection sort algorithm
 *
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: print array each time you swap two elements.
 */
void selection_sort(int *array, size_t size)
{
	int *min;
	size_t n, m;

	if (array == NULL || size < 2)
		return;

	for (n = 0; n < size - 1; n++)
	{
		min = array + n;
		for (m = n + 1; m < size; m++)
			min = (array[m] < *min) ? (array + m) : min;

		if ((array + n) != min)
		{
			switch_ints(array + n, min);
			print_array(array, size);
		}
	}
}
