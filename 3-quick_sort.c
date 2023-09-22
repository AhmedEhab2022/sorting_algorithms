#include "sort.h"

void swap(int *x, int *y);
void quick_sort_recursion(int *array, size_t size, int low, int high);
size_t partition(int *array, size_t size, int low, int high);

/**
 * quick_sort - sorts an array of integers in ascending order
 * using the Quick sort algorithm
 *
 * @array: array of integers
 * @size: the size of array
 */
void quick_sort(int *array, size_t size)
{

	if (array == NULL || size < 2)
		return;

	quick_sort_recursion(array, size, 0, (int)size - 1);
}

/**
 * swap - swaps two elements
 *
 * @x: the first element
 * @y: the second element
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * quick_sort_recursion - implements quick sort algorthm recursivly
 *
 * @array: array of integers
 * @size: the size of array
 * @low: the start index
 * @high: the end index
 */
void quick_sort_recursion(int *array, size_t size, int low, int high)
{
	int pivot_index;

	if (low < high)
	{
		pivot_index = partition(array, size, low, high);
		quick_sort_recursion(array, size, low, pivot_index - 1);
		quick_sort_recursion(array, size, pivot_index + 1, high);
	}
}

/**
 * partition - gets the index of pivot after making required swaps
 *
 * @array: array of integers
 * @size: the size of array
 * @low: the start index
 * @high: the end index
 *
 * Return: the index of pivot
 */
size_t partition(int *array, size_t size, int low, int high)
{
	int pivot, i, j;

	pivot = *(array + high);
	i = low;
	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			if (i < j)
			{
				swap(array + i, array + j);
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] > pivot)
	{
		swap(array + i, array + high);
		print_array(array, size);
	}
	return (i);
}
