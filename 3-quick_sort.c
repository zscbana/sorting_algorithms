#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap_ints(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition - Partition the array around a pivot element.
 * @array: The array to partition.
 * @low: The lowest index of the partition.
 * @high: The highest index of the partition.
 * @size: The size of the array.
 * Return: The index of the pivot element after partitioning.
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;

	for (int j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap_ints(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap_ints(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quick_sort_recursive - Recursive function to perform quick sort.
 * @array: The array to sort.
 * @low: The lowest index of the partition.
 * @high: The highest index of the partition.
 * @size: The size of the array.
 */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = partition(array, low, high, size);

		quick_sort_recursive(array, low, pi - 1, size);
		quick_sort_recursive(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array of integers in ascending order
 * using the Quick Sort algorithm.
 * @array: Pointer to the array to sort.
 * @size: Number of elements in the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
