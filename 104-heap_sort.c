#include "sort.h"

/**
 * sift_down - Maintains the heap property of a binary heap
 * starting from a given index
 *
 * @array: The array containing the binary heap
 * @size: Number of elements in @array
 * @base: The index of the base row of the tree.
 * @root: The index of the parent node to start from
 */
void sift_down(int *array, size_t size, size_t base, size_t root)
{
	size_t largest = root;
	size_t left = 2 * root + 1;
	size_t right = 2 * root + 2;

	if (left < base && array[left] > array[largest])
		largest = left;

	if (right < base && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		int temp = array[root];

		array[root] = array[largest];
		array[largest] = temp;

		print_array(array, size);

		sift_down(array, size, base, largest);
	}
}


/**
 * heap_sort - Sorts an array of integers in ascending order
 * using the Heap sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void heap_sort(int *array, size_t size)
{
	int i, tmp;

	if (array == NULL || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		sift_down(array, size, size, i);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;

		print_array(array, size);

		sift_down(array, size, i, 0);
	}
}
