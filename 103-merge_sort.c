#include "sort.h"

void join_sub_arr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back);
void join_org_recursive(int *subarr, int *buff, size_t front, size_t back);
void merge_sort(int *array, size_t size);

/**
 * join_sub_arr - join sub array of integers.
 *
 * @subarr: subarray of an array of ints to be sorted.
 * @buff: location of te buff to store the sorted subarray.
 * @front: front index of the array.
 * @mid: middle index of the array.
 * @back: back index of the array.
 */
void join_sub_arr(int *subarr, int *buff, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buff[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buff[k++] = subarr[i];
	for (; j < back; j++)
		buff[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buff[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}

/**
 * join_org_recursive - Executes the merge sort
 * algos by recursion.
 *
 * @subarr: subarray of an intgers array.
 * @buff: buff storing sorted results
 * @front: front index of the subarray.
 * @back: back index of the subarray.
 */
void join_org_recursive(int *subarr, int *buff, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		join_org_recursive(subarr, buff, front, mid);
		join_org_recursive(subarr, buff, mid, back);
		join_sub_arr(subarr, buff, front, mid, back);
	}
}

/**
 * merge_sort - sorts an array of integers in
 * ascending order using the Merge sort algorithm.
 *
 * @array: array of integers.
 * @size: array size.
 *
 * Description: Implements top-down merge sort algorithm.
 */
void merge_sort(int *array, size_t size)
{
	int *buff;

	if (array == NULL || size < 2)
		return;

	buff = malloc(sizeof(int) * size);
	if (buff == NULL)
		return;

	join_org_recursive(array, buff, 0, size);

	free(buff);
}
