#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order
 * using the Shell sort algorithm with the Knuth sequence
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int tmp;

	if (array == NULL)
		return;

	for (gap = 1; gap < size / 3; gap = gap * 3 + 1)
		;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			for (j = i; j >= gap && array[j - gap] > array[j]; j -= gap)
			{
				tmp = array[j];
				array[j] = array[j - gap];
				array[j - gap] = tmp;
			}
		}

		print_array(array, size);
	}
}
