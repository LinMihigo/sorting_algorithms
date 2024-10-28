#include "sort.h"

/**
* swap - Swap two integers in an array.
* @x: First integer pointer
* @y: Second integer pointer
*/
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
* lomuto_partition - Partitioning function using Lomuto's scheme with last
* element as pivot.
* @array: Array to partition
* @low: Starting index
* @high: Ending index
* @size: Size of the array
* Return: The index of the pivot element after partitioning.
*/
int lomuto_partition(int *array, int low, int high, int size)
{
	int pivot = array[high];

	int i = low - 1, j;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
* lomuto_quick_sort - Quick sort function using Lomuto partitioning.
* @array: Array to sort
* @low: Starting index
* @high: Ending index
* @size: Size of the array
*/
void lomuto_quick_sort(int *array, int low, int high, int size)
{
	int pi;

	if (low < high)
	{
		pi = lomuto_partition(array, low, high, size);

		lomuto_quick_sort(array, low, pi - 1, size);
		lomuto_quick_sort(array, pi + 1, high, size);
	}
}

/**
* quick_sort - Entry function for quick sort using last element as pivot.
* @array: Array to sort
* @size: Size of the array
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, 0, size - 1, size);
}
