#include "sort.h"

/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked lists.
 * @list: Pointyer to the head of the list.
 * @left: Pointer to first node of swap.
 * @right: Pointer to second node to swap.
 */
void swap_nodes(listint_t **list, listint_t *left, listint_t *right)
{
	if (left->prev)
		left->prev->next = right;
	else
		*list = right;
	if (right->next)
		right->next->prev = left;

	left->next = right->next;
	right->prev = left->prev;
	right->next = left;
	left->prev = right;
}

/**
 * cocktail_sort_list -Function that sorts doubly linked list of
 * integers in ascending order using Cocktail shaker algorithm.
 * @list: The double pointer to the doubly
 * linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *start = NULL, *end = NULL, *current;

	if (!list || !*list || !(*list)->next)
		return;
	while (swapped)
	{
		swapped = 0;

		current = (start) ? start : *list; /*Start from beginning*/

		while (current->next != end) /* Forward Pass*/
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->next;
		}
		end = current; /* Set end boundary*/
		if (!swapped) /* Break if no swaps in the forward pass*/
			break;
		swapped = 0;
		current = end; /*Backward passed*/
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current;
	}
}
