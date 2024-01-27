#include "sort.h"

int get_max(int *array, int size);
void radix_sort_count(int *array, size_t size, int sig, int *buff);
void radix_sort(int *array, size_t size);

/**
 * get_max - gets maximum integer value in an array.
 *
 * @array: array of integers.
 * @size: size of array.
 *
 * Return: maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}

/**
 * radix_sort_count - sorts the largest integer of an array
 * in ascending order using the counting sort algos.
 *
 * @array: array of integers.
 * @size: size of array.
 * @sig: largest integer to sort on.
 * @buff: buffer storing sorted array.
 */
void radix_sort_count(int *array, size_t size, int sig, int *buff)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / sig) % 10] += 1;

	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; (int)i >= 0; i--)
	{
		buff[count[(array[i] / sig) % 10] - 1] = array[i];
		count[(array[i] / sig) % 10] -= 1;
	}

	for (i = 0; i < size; i++)
		array[i] = buff[i];
}

/**
 * radix_sort - sorts an array of integers in
 * ascending order using the Radix sort algorithm.
 * 
 * @array: array of integers.
 * @size: size of array.
 *
 * Description: print the array each time
 * you increase your significant digit.
 */
void radix_sort(int *array, size_t size)
{
	int max, sig, *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	max = get_max(array, size);
	for (sig = 1; max / sig > 0; sig *= 10)
	{
		radix_sort_count(array, size, sig, buff);
		print_array(array, size);
	}

	free(buff);
}
