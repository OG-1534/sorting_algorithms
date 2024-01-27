#include "sort.h"

void swops_ints(int *a, int *b);
int lomutoscheme_partition(int *array, size_t size, int left, int right);
void lomutoscheme_sort(int *array, size_t size, int left, int right);
void quick_sort(int *array, size_t size);

/**
 * swops_ints -switches the positions of two integers in an array.
 * @a: first integer to be switched.
 * @b: second integer to be switched.
 */
void swops_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomutoscheme_partition - sorts an array of integers in
 * ascending order using the Quick sort algorithm implementing
 * the Lomuto partition scheme.
 *
 * @array: array of ints.
 * @size: size of array.
 * @left: initiating index of the ordered subset.
 * @right: final index of the ordered subset.
 * Return: final partition index.
 */
int lomutoscheme_partition(int *array, size_t size, int left, int right)
{
	int *pivot, above, below;

	pivot = array + right;
	for (above = below = left; below < right; below++)
	{
		if (array[below] < *pivot)
		{
			if (above < below)
			{
				swops_ints(array + below, array + above);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > *pivot)
	{
		swops_ints(array + above, pivot);
		print_array(array, size);
	}

	return (above);
}

/**
 * lomutoscheme_sort - quick sorts algo recursively.
 *
 * @array: array of integers to be sorted.
 * @size: size of the array.
 * @left: starting index of the partition to be sorted.
 * @right: ending index of the partition to be sorted.
 *
 * Description: Uses the Lomuto partition scheme.
 */
void lomutoscheme_sort(int *array, size_t size, int left, int right)
{
	int part;

	if (right - left > 0)
	{
		part = lomutoscheme_partition(array, size, left, right);
		lomutoscheme_sort(array, size, left, part - 1);
		lomutoscheme_sort(array, size, part + 1, right);
	}
}

/**
 * quick_sort - function that sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * implement the Lomuto partition scheme.
 *
 * @array: array of integers.
 * @size: array size.
 *
 * Description: quicksort algorithm implementing
 * Lomuto partition scheme. Print the array each
 * time you swap twoo elements.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomutoscheme_sort(array, size, 0, size - 1);
}
