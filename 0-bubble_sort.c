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
	size_t i, j;
	bool swapped;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		swapped = false;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				swapped = true;
			}
		}
		if (swapped == false)
			break;
	}
}
