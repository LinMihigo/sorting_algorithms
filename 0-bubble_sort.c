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
* bubble_sort - sorts an array of ints in ascending order using bubble sort
* @array: array to sort
* @size: size of the array
* Return: void
*/
void bubble_sort(int *array, size_t size)
{
	size_t i, j, k;

	print_array(array, size);
	if (sizeof(array) > 1)
	{
		for (i = 0; i < size - 1; i++)
		{
			k = 1;
			for (j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					swap(&array[j], &array[j + 1]);
					print_array(array, size);
					k = 1;
				}
			}
			if (k == 0)
				break;
		}
	}
}
