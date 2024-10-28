#include "sort.h"

/**
* swap - Swap two integers in an array.
* @x: The first integer pointer.
* @y: The second integer pointer.
*/
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
* lomuto_partition - Partitioning function using Lomuto's scheme with the last
* element as the pivot.
* @array: The array to partition.
* @low: The starting index of the subset to order.
* @high: The ending index of the subset to order.
* @size: The size of the array.
*
* Return: The final partition index.
*/
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];

	int below, above = low;

	for (below = low; below < high; below++)
	{
		if (array[below] < pivot)
		{
			if (above < below)
			{
				swap(&array[below], &array[above]);
				print_array(array, size);
			}
			above++;
		}
	}

	if (array[above] > pivot)
	{
		swap(&array[above], &array[high]);
		print_array(array, size);
	}

	return (above);
}

/**
* lomuto_quick_sort - Sorts an array of integers using Quick Sort with
* Lomuto's partition.
* @array: The array to sort.
* @low: The starting index of the subset to order.
* @high: The ending index of the subset to order.
* @size: The size of the array.
*/
void lomuto_quick_sort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int partition_index = lomuto_partition(array, low, high, size);

		lomuto_quick_sort(array, low, partition_index - 1, size);
		lomuto_quick_sort(array, partition_index + 1, high, size);
	}
}

/**
* quick_sort - Sorts an array of integers in ascending order using Quick Sort.
* @array: The array to sort.
* @size: The size of the array.
*/
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_quick_sort(array, 0, size - 1, size);
}
