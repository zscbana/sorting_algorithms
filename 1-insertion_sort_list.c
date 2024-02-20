#include "sort.h"

/**
 * swap - Swaps two nodes in a doubly linked list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 */
void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion Sort algorithm
 * @list: Pointer to the pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *i, *j;

	if (!list || !*list || !(*list)->next)
		return;
	for (i = (*list)->next; i != NULL; i = i->next)
	{
		j = i;
		while (j && j->prev)
		{
			if (j->prev->n > j->n)
			{
				swap(j->prev, j);
				if (!j->prev)
				{
					*list = j;
				}
				print_list((const listint_t *)*list);
			}
			else
				j = j->prev;
		}
	}
}
