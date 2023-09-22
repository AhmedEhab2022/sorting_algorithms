#include "sort.h"

#define getParent(i) (((i) - 1) / 2)
#define getLeft(i) (2 * (i) + 1)
#define getRight(i) (2 * (i) + 2)

/**
 * sift_down - Maintains the heap property of a binary heap
 * starting from a given index
 *
 * @array: The array containing the binary heap
 * @size: Number of elements in @array
 * @parent: The index of the parent node to start from
 * @last: The index of the last node in the heap to examine
 */
void sift_down(int *array, size_t size, size_t parent, size_t last)
{
	size_t largest_child, left_child, right_child;
	int tmp;

	do {
		left_child = getLeft(parent);
		right_child = getRight(parent);
		largest_child = parent;

		if (right_child <= last && array[right_child] > array[largest_child])
			largest_child = right_child;

		if (array[left_child] > array[largest_child])
			largest_child = left_child;

		if (parent == largest_child)
			return;

		tmp = array[parent];
		array[parent] = array[largest_child];
		array[largest_child] = tmp;
		print_array(array, size);

		parent = largest_child;
	} while (getLeft(parent) <= last);
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
	size_t i;
	int tmp;

	if (array == NULL || size < 2)
		return;

	for (i = getParent(size - 1); i != SIZE_MAX; i--)
		sift_down(array, size, i, size - 1);

	for (i = size - 1; i > 0; i--)
	{
		tmp = array[0];
		array[0] = array[i];
		array[i] = tmp;
		print_array(array, size);
		sift_down(array, i, 0, i - 1);
	}

	print_array(array, size);
}
