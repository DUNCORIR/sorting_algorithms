#include "sort.h"

/**
 * heapify -  function to Sift-down method to maintain
 * the max-heap property.
 * @array: The array representing the heap.
 * @size: Total size of the heap.
 * @index: Index of the element to be heapified.
 */
void heapify(int *array, size_t size, size_t index)
{
	size_t left = 2 * index + 1;
	size_t largest = index;
	size_t right = 2 * index + 2;
	int temp;

	/* Check if left child is larger than root */
	if (left < size && array[left] > array[largest])
		largest = left;
	/* Check if right child is larger than largest */
	if (right < size && array[right] > array[largest])
		largest = right;
	/* Swap and continue heapifying if root is not largest */
	if (largest != index)
	{
		temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;

		/* Print the array after each swap */
		print_array(array, size);

		/* Recursively heapify the affected sub-tree */
		heapify(array, size, largest);
	}
}

/**
 * heap_sort - Sorts an array of integers in
 * ascending order using Heap sort.
 * @array: The array to be sorted.
 * @size: Number of elements in the array.
 */
void heap_sort(int *array, size_t size)
{
	ssize_t i;
	int temp;

	if (size < 2)
		return;

	/*Build a max heap*/
	for (i = (size / 2) - 1; i >= 0; i--)
		heapify(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		/*Swaps root which is largesr with last element*/
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		/*Print array after each swap*/
		print_array(array, size);

		/*heapify reduced heap*/
		heapify(array, i, 0);
	}
}
