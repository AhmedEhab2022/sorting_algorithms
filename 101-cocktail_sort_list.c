#include "sort.h"

/**
 * swap_nodes - swaps two nodes of doubly linked list
 *
 * @list: pointer to list
 * @curr: the current node
 * @next: the next node
 */
void swap_nodes(listint_t **list, listint_t **curr, listint_t **next)
{
	if ((*next)->next != NULL)
		(*next)->next->prev = *curr;

	(*curr)->next = (*next)->next;
	if ((*curr)->prev != NULL)
		(*curr)->prev->next = *next;
	else
		*list = *next;

	(*next)->prev = (*curr)->prev;
	(*curr)->prev = *next;
	(*next)->next = *curr;
	*curr = *next;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 *
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *curr, *next;
	int swap_flag = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	while (swap_flag)
	{
		swap_flag = 0;
		curr = *list;
		while (curr->next)
		{
			next = curr->next;
			if (curr->n > next->n)
			{
				swap_flag = 1;
				swap_nodes(list, &curr, &next);
				print_list(*list);
			}
			curr = curr->next;
		}
		if (swap_flag == 0)
			return;

		swap_flag = 0;
		curr = curr->prev;
		while (curr->prev)
		{
			next = curr->next;
			if (curr->n > next->n)
			{
				swap_flag = 1;
				swap_nodes(list, &curr, &next);
				print_list(*list);
			}
			curr = curr->prev;
		}
	}
}
