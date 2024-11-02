#include "sort.h"
/**
* insertion_sort_list - Sorts a doubly linked list of ints in Asc. Order using
* insertion sort algo
* @list: list to sort
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *posn, *prev, *curr = (*list)->next;

	if (!list || !*list || !(*list)->next)
		return;

	while (curr)
	{
		posn = curr;

		while (posn->prev && posn->n < posn->prev->n)
		{
			prev = posn->prev;

			if (prev->prev)
				prev->prev->next = posn;

			posn->prev = prev->prev;
			prev->next = posn->next;

			if (posn->next)
				posn->next->prev = prev;

			posn->next = prev;
			prev->prev = posn;

			if (!posn->prev)
				*list = posn;

			print_list(*list);
		}
		curr = curr->next;
	}
}
