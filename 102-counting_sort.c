#include "sort.h"

/**
 * get_max - get the maximum value in an array of integers
 * @array: An array of integers
 * @size: The size of the array
 *
 * Return: The maximum integer in the array
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
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting sort algorithm
 *
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
    int *count_array, *output_array, max_value, current_value;
    size_t i;

    if (array == NULL || size < 2)
        return;

    max_value = get_max(array, size);
    count_array = malloc(sizeof(int) * (max_value + 1));
    output_array = malloc(sizeof(int) * size);

    for (i = 0; i <= (size_t)max_value; i++)
        count_array[i] = 0;

    for (i = 0; i < size; i++)
        count_array[array[i]]++;

    for (i = 1; i <= (size_t)max_value; i++)
        count_array[i] += count_array[i - 1];

    print_array(count_array, max_value + 1);

    for (i = 0; i < size; i++)
    {
        current_value = array[i];
        output_array[count_array[current_value] - 1] = current_value;
        count_array[current_value]--;
    }

    for (i = 0; i < size; i++)
        array[i] = output_array[i];

    free(output_array);
    free(count_array);
}
