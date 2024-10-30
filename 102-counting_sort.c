#include "sort.h"

/**
 * find_maximum - Finds max number of integers in array.
 * @array: Arrays of integers.
 * @size: The size of array.
 *
 * Return: Maximum integer in array.
 */
int find_maximum(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * print_count_array - Prints the count array for visualization.
 * @count: The count array
 * @max_val: Maximum value in the array.
 */
void print_count_array(int *count, int max_val)
{
	int i;

	for (i = 0; i <= max_val; i++)
		printf("%d%s", count[i], i == max_val ? "\n" : ", ");

}

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using Counting sort.
 * @array: The array of integers.
 * @size: The size of array.
 */
void counting_sort(int *array, size_t size)
{
	int max_val, *count, *output;
	size_t i;

	if (size < 2)
		return;
	/*Max value in the array*/
	max_val = find_maximum(array, size);

	count = malloc((max_val + 1) * sizeof(int)); /*allocate-initialize array*/
	if (!count)
		return;
	for (i = 0; i <= (size_t)max_val; i++) /*Populate the count array*/
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[array[i]]++;
	print_count_array(count, max_val);
	for (i = 1; i <= (size_t)max_val; i++) /*Accumulate counts*/
		count[i] += count[i - 1];
	output = malloc(size * sizeof(int)); /* Build output array using count*/
	if (!output)
	{
		free(count);
		return;
	}
	for (i = size; i > 0; i--)
	{
		output[count[array[i - 1]] - 1] = array[i - 1];
		count[array[i - 1]]--;
	}
	for (i = 0; i < size; i++) /*copy sorted otput array to original*/
		array[i] = output[i];
	free(count); /*Free allocated memory*/
	free(output);
}
