#include "sort.h"

/**
 * insertion_sort_list - a function that sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 *
 * @list: pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *curr, *prev, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	curr = (*list)->next;
	while (curr)
	{
		prev = curr->prev;
		tmp = prev;
		while (tmp && tmp->n > curr->n)
		{
			if (curr->next != NULL)
				curr->next->prev = tmp;

			tmp->next = curr->next;
			if (tmp->prev != NULL)
				tmp->prev->next = curr;

			curr->prev = tmp->prev;
			tmp->prev = curr;
			curr->next = tmp;
			if (curr->prev == NULL)
				*list = curr;

			print_list(*list);
			tmp = curr->prev;
		}
		curr = curr->next;
	}
}
