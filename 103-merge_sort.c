#include "sort.h"

/**
 * merge - function that merges sorted subarrays from recursive merge_sort
 * calls
 * @array: the array to sort
 * @l: left starting index
 * @m: mid index
 * @r: right ending index
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
    size_t i, j, k;
    size_t n1 = mid - left + 1;
    size_t n2 = right - mid;

    int *L = malloc(n1 * sizeof(int));
    int *R = malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL)
    {
        free(L);
        free(R);
        return;
    }

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[mid + 1 + j];

    i = 0, j = 0, k = left;

    printf("Merging...\n");
    printf("[left]: ");
    print_array(L, n1);
    printf("[right]: ");
    print_array(R, n2);

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            array[k++] = L[i++];
        else
            array[k++] = R[j++];
    }

    while (i < n1)
        array[k++] = L[i++];

    while (j < n2)
        array[k++] = R[j++]; 

    printf("[Done]: ");
    print_array(array + left, right - left + 1);

    free(L);
    free(R);
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
