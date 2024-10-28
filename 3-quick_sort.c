#include "sort.h"
/**
* swap - swap two points
* @x: 1st pointer
* @y: 2nd pointer
*/
void swap(int *x, int *y)
{
	int temp = *x;

	*x = *y;
	*y = temp;
}

/**
* lomuto_partition - partitioning function
* @array: array
* @low: lower bound index
* @high: Upper bound index (pivot)
* Return: i + 1
*/
int lomuto_partition(int *array, int low, int high)
{

	int pivot = array[high];
	int j, i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
* lomuto_quick_sort - sorts an arr. of ints in Asc. order using Quick sort
* @array: array to sort
* @low: Lower bound
* @high: higher bound
* @size: size of the array
*/
void lomuto_quick_sort(int *array, int low, int high, int size)
{
	int pi;

	while (low < high)
	{
		pi = lomuto_partition(array, low, high);

		print_array(array, size);

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

/**
* quick_sort - sorts an arr. of ints in Asc. order using Quick sort
* @array: array to sort
* @size: size of the array
*/
void quick_sort(int *array, size_t size)
{
	lomuto_quick_sort(array, 0, size - 1, size);
}
