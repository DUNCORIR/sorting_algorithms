#include "sort.h"

/**
 * shell_sort - Function sorts array of integers in ascending order
 * using the shell sort algorithm with Knuth sequence.
 * @array: Pointer to the array of integers to be sorted.
 * @size: The number of elements in the array.
 */
void shell_sort(int *array, size_t size)
{
	size_t h = 1;
	size_t i, j;
	int temp;

	if (array == NULL || size < 2)
		return;

	/*Calculating initial gap using Knuth sequence*/
	while (h < size / 3)
		h = h * 3 + 1; /*knuth sequence*/

	/*Perform shell sort with decreasing gaps*/
	while (h >= 1)
	{
		/*Gapped inserted for this gap size */
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;

			/*Shift elements of sorted sublist to correct position*/
			while (j >= h && array[j - h] > temp)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = temp;
		}
		/*Print array after each gap reduction*/
		print_array(array, size);

		/*Reduce gap using Knuth sequence*/
		h = (h - 1) / 3;
	}
}
