#include "sort.h"

/**
 * bubble_sort - The function sorts an array of integers in ascending order
 * using the bubble sort algorithm.
 * @array: The pointer to the array to be sorted.
 * @size: The size of the array.
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, swapped;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j]; /* Swap elements */
				array[j] = array[j + 1];
				array[j + 1] = temp;

				/* Print array after each swap */
				print_array(array, size);

				swapped = 1;
			}
		}
		/*if no elements were swapped, the array is sorted already*/
		if (swapped == 0)
			break;
	}
}
