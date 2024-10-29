#include "sort.h"

/**
 * selection_sort- Function that sorts an array in ascending order
 * using the selection sort algorithm.
 * @array: The pointer to the array to be sorted.
 * @size: The size of array.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;
	int temp;

	/*Return if array is NULL or less than 2*/
	if (array == NULL || size < 2)
		return;
	/*Traverse through all elements in the array*/
	for (i = 0; i < size - 1; i++)
	{
		min_index = i;

		/* Find minimum element in the unsorted part of array*/
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		/* Swap found minimum element with first unsorted element*/
		if (min_index != i)
		{
			temp = array[i];
			array[i] = array[min_index];
			array[min_index] = temp;

			/*print array after each swap*/
			print_array(array, size);
		}
	}
}
