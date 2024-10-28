0x1B. C - Sorting algorithms & Big O
C
Algorithm
Data structure


Sorting Algorithms
0. Bubble Sort

Description: Repeatedly steps through the list, compares adjacent elements, and swaps them if they are in the wrong order. The process is repeated until the list is sorted.

1. Selection Sort

Description: Divides the list into a sorted and an unsorted part. Repeatedly finds the minimum element from the unsorted part and swaps it with the first unsorted element, moving it to the sorted part.

2. Insertion Sort

Description: Builds the final sorted array one element at a time, picking the next element from the unsorted part and inserting it into its correct position in the sorted part.

3. Merge Sort

Description: Divides the list into halves, recursively sorts each half, and then merges them back together in a sorted manner.


Big O Notation
Definition: Big O notation describes the upper limit of an algorithm’s time or space complexity, showing how it behaves as the input size 
𝑛
n grows. It helps evaluate the performance of algorithms and can identify their efficiency.


How to Select the Best Sorting Algorithm
Input Size: Smaller datasets might perform well with simple algorithms like Insertion Sort or Bubble Sort, but for larger datasets, more efficient algorithms like Merge Sort or Quick Sort are recommended.
Memory Constraints: If memory is a concern, prefer in-place algorithms like Quick Sort or Heap Sort over algorithms that require additional space (e.g., Merge Sort).
Data Characteristics: If the data is already partially sorted, algorithms like Insertion Sort perform better. For general cases, Merge Sort or Quick Sort is preferred.
Stability: If stability is required (elements with equal keys must retain their relative order), use Merge Sort, Bubble Sort, or Insertion Sort.
Stable Sorting Algorithms
Definition: A sorting algorithm is considered stable if it maintains the relative order of elements with equal keys. For instance, if two objects have the same key, they appear in the same order in the sorted output as they do in the input.
Examples of Stable Algorithms:
Bubble Sort
Insertion Sort
Merge Sort
Examples of Unstable Algorithms:
Selection Sort
Quick Sort (in most implementations)
Heap Sort
