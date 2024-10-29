#include "sort.h"

/**
 * swap - Swaps two integers in array.
 * @a: First integer to swap.
 * @b: Second integer to swap.
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
/**
 * partition - Lomuto partition scheme for quick sort.
 * @array: Array of integers to be sorted.
 * @low: Starting index of the partiotion to sort.
 * @high: Ending index of partition to be sorted.
 * @size: the size of array.
 *
 * Return: The array after placing pivot element in correct position.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high]; /* Pivot is the last element*/
	int j, i = low - 1; /*index of smaller element */

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{

			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size); /*Print array after each swap*/
			}
		}
	}

	/*Place pivot element in correvt position*/
	if (i + 1 != high)
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size); /*Print array after placing pivot*/
	}
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively applies quick sort to partitions
 * @array: The array of integers to sort
 * @low: Starting index of the partition to start.
 * @high: Ending index of the partition to sort.
 * @size: Size of the array
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot_index = partition(array, low, high, size); /* Partition array*/

		/*Sort elements ecursively before and after partition*/
		quick_sort_recursive(array, low, pivot_index - 1, size);
		quick_sort_recursive(array, pivot_index + 1, high, size);
	}
}

/**
 * quick_sort - Functiom that sorts integers in an ascending order
 * using quick sort algorithm.
 * @array: The pointer to the array to be sorted.
 * @size: The size of the array to be sorted.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	/*initial call to the recursive quick sort function*/
	quick_sort_recursive(array, 0, size - 1, size);
}
