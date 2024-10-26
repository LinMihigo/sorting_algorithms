#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list of ints in Asc. Order using
* insertion sort algo
* @list: list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current_sorted, *next, *curr = *list, *sorted = NULL;

	while (curr)
	{
		next = curr->next;
		if (!sorted || sorted->n >= curr->n)
		{
			curr->next = sorted;
			if (sorted)
				sorted->prev = curr;
			sorted = curr;
			sorted->prev = NULL;
		}
		else
		{
			current_sorted = sorted;

			while (current_sorted->next && current_sorted->next->n < curr->n)
				current_sorted = current_sorted->next;
			curr->next = current_sorted->next;

			if (current_sorted->next)
				current_sorted->next->prev = curr;
			current_sorted->next = curr;
			curr->prev = current_sorted;
		}
		curr = next;
		*list = sorted;
		print_list(*list);
	}
}
