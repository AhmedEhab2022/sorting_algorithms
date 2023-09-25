#include "sort.h"

void merge_sort_recursion(int *array, int *buffer, size_t low, size_t high);
void merge(int *array, int *buffer, size_t low, size_t mid, size_t high);

/**
 * merge_sort - sorts an array of integers in ascending order
 * using the Merge sort algorithm
 *
 * @array: array of integers
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *tmp;

	if (array == NULL || size < 2)
		return;

	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
		return;

	merge_sort_recursion(array, tmp, 0, size);
	free(tmp);
}

/**
 * merge_sort_recursion - implements merge sort recursion
 *
 * @array: array of integers
 * @buffer: a new empty array
 * @low: the start index
 * @high: the end index
 */
void merge_sort_recursion(int *array, int *buffer, size_t low, size_t high)
{
	size_t mid;

	if (high - low > 1)
	{
		mid = low + (high - low) / 2;
		merge_sort_recursion(array, buffer, low, mid);
		merge_sort_recursion(array, buffer, mid, high);

		merge(array, buffer, low, mid, high);
	}
}

/**
 * merge - implements merge process
 * @array: array of integers
 * @buffer: a new empty array
 * @low: the start index
 * @mid: the middel index
 * @high: the end index
 */
void merge(int *array, int *buffer, size_t low, size_t mid, size_t high)
{
	size_t i = low, j = mid, k = 0;

	printf("Merging...\n[left]: ");
	print_array(array + low, mid - low);
	printf("[right]: ");
	print_array(array + mid, high - mid);
	while (i < mid && j < high)
	{
		if (array[i] < array[j])
		{
			buffer[k] = array[i];
			i++;
		}
		else
		{
			buffer[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		buffer[k++] = array[i];
		i++;
	}
	while (j < high)
	{
		buffer[k++] = array[j];
		j++;
	}
	for (i = low, k = 0; i < high; i++)
		array[i] = buffer[k++];

	printf("[Done]: ");
	print_array(array + low, high - low);
}
