#include "sort.h"

/**
 * selection_sort - Sorts an array of integers in ascending order
 *                  using the Selection Sort algorithm
 * @array: Pointer to the array to sort
 * @size: Number of elements in the array
 */
void selection_sort(int *array, size_t size)
{
	int temp, minIndex;
	size_t i, j;

	if (!array || !size)
		return;
	for (i = 0; i < size - 1; i++)
	{
		minIndex = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[minIndex])
				minIndex = j;
			temp = array[j];
			array[j] = array[minIndex];
			array[minIndex] = temp;
			print_array(array, size);
		}
	}
}
