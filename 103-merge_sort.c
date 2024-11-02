#include "sort.h"

/**
 * merge - function that merges sorted subarrays from recursive merge_sort
 * calls
 * @array: the array to sort
 * @l: left starting index
 * @m: mid index
 * @r: right ending index
 */
void merge(int array[], int l, int m, int r)
{
	int i, j, k = l;
	int l_size = m - l + 1;
	int r_size = r - m;
	int *l_arr = malloc(l_size * sizeof(int));
	int *r_arr = malloc(r_size * sizeof(int));

	if (!l_arr || !r_arr)
		return;

	for (i = 0; i < l_size; i++)
		l_arr[i] = array[l + i];
	for (j = 0; j < r_size; j++)
		r_arr[j] = array[m + 1 + j];

	printf("Merging...\n[left]: ");
	print_array(l_arr, l_size);
	printf("[right]: ");
	print_array(r_arr, r_size);

	i = 0, j = 0;

	while (i < l_size && j < r_size)
	{
		if (l_arr[i] <= r_arr[j])
			array[k++] = l_arr[i++];
		else
			array[k++] = r_arr[j++];
	}

	while (i < l_size)
		array[k++] = l_arr[i++];
	while (j < r_size)
		array[k++] = r_arr[j++];

	printf("[Done]: ");
	print_array(array + l, r - l + 1);

	free(l_arr);
	free(r_arr);
}

/**
 * merge_sort_helper - recursive helper function for merge_sort
 * @array: the array to sort
 * @l: left starting index
 * @r: right ending index
 */
void merge_sort_helper(int array[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		merge_sort_helper(array, l, m);
		merge_sort_helper(array, m + 1, r);
		merge(array, l, m, r);
	}
}

/**
 * merge_sort - the merge sort function
 * @array: the array to sort
 * @size: size of the array
 */
void merge_sort(int array[], size_t size)
{
	if (!array || size < 2)
		return;

	if (size > 0)
		merge_sort_helper(array, 0, size - 1);
}
