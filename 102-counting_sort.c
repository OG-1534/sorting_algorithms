#include "sort.h"

/**
 * get_max - gets the max value integers array.
 *
 * @array: integers array.
 * @size: size of array.
 *
 * Return: max integer in the array.
 */
int get_max(int *array, int size)
{
	int max, q;

	for (max = array[0], q = 1; q < size; q++)
	{
		if (array[q] > max)
			max = array[q];
	}

	return (max);
}

/**
 * counting_sort - sorts an array of integers in
 * ascending order using the Counting sort algorithm.
 *
 * @array: integers of array.
 * @size: size of array.
 *
 * Description: print your counting array once it is set up.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *sort, max, q;

	if (array == NULL || size < 2)
		return;

	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sort);
		return;
	}

	for (q = 0; q < (max + 1); q++)
		count[q] = 0;
	for (q = 0; q < (int)size; q++)
		count[array[q]] += 1;
	for (q = 0; q < (max + 1); q++)
		count[q] += count[q - 1];
	print_array(count, max + 1);

	for (q = 0; q < (int)size; q++)
	{
		sort[count[array[q]] - 1] = array[q];
		count[array[q]] -= 1;
	}

	for (q = 0; q < (int)size; q++)
		array[q] = sort[q];

	free(sort);
	free(count);
}
