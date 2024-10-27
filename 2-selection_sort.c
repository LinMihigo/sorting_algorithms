#include "sort.h"
/**
* selection_sort - sorts an array of ints in Asc. order using selection sort
* algorithm
* @array: array to sort
* @size: size of the array
*/
void selection_sort(int *array, size_t size)
{
	size_t min_idx, i, j;
	int temp;

	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;

		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[min_idx])
				min_idx = j;
		}

		temp = array[i];
		array[i] = array[min_idx];
		array[min_idx] = temp;
		print_array(array, size);
	}
}
