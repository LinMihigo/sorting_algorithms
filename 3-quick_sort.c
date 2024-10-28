#include "sort.h"

#define THRESHOLD 10

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
* insertion_sort - Sorts a small section of the array using Insertion Sort.
* @array: Array to sort
* @low: Starting index of the section
* @high: Ending index of the section
* @size: Size of the array
*/
void insertion_sort(int *array, int low, int high, int size)
{
	int i, j, key;

	for (i = low + 1; i <= high; i++)
	{
		key = array[i];
		j = i - 1;
		while (j >= low && array[j] > key)
		{
			array[j + 1] = array[j];
			j--;
			print_array(array, size);
		}
		array[j + 1] = key;
	}
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
* lomuto_quick_sort - Improved quick sort function using last element as pivot.
* @array: Array to sort
* @low: Starting index
* @high: Ending index
* @size: Size of the array
*/
void lomuto_quick_sort(int *array, int low, int high, int size)
{
	int pi;

	while (low < high)
	{
		if (high - low < THRESHOLD)
		{
			insertion_sort(array, low, high, size);
			break;
		}
		else
		{
			pi = lomuto_partition(array, low, high, size);

			if (pi - low < high - pi)
			{
				lomuto_quick_sort(array, low, pi - 1, size);
				low = pi + 1;
			}
			else
			{
				lomuto_quick_sort(array, pi + 1, high, size);
				high = pi - 1;
			}
		}
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
