#include "sort.h"

void front_node_swap(listint_t **list, listint_t **tail, listint_t **shaker);
void back_node_swap(listint_t **list, listint_t **tail, listint_t **shaker);
void cocktail_sort_list(listint_t **list);

/**
 * front_node_swap - swaps nodes in a listint_t doubly-linked list
 *                   list of integers with the node ahead of it.
 * @list: pointer to head of integers doubly-linked list.
 * @tail: pointer to tail of integers doubly-linked list.
 * @shaker: pointer to the current node to swap in the cocktail shaker algo.
 */
void front_node_swap(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->next;

	if ((*shaker)->prev != NULL)
		(*shaker)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*shaker)->prev;
	(*shaker)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *shaker;
	else
		*tail = *shaker;
	(*shaker)->prev = tmp;
	tmp->next = *shaker;
	*shaker = tmp;
}

/**
 * back_node_swap - swaps a node in a listint_t doubly-linked
 *                    list of integers with the node behind it.
 *
 * @list: pointer to head of doubly-linked list.
 * @tail: pointer to tail of doubly-linked list.
 * @shaker: pointer to the current node to swap in the cocktail shaker algo.
 */
void back_node_swap(listint_t **list, listint_t **tail, listint_t **shaker)
{
	listint_t *tmp = (*shaker)->prev;

	if ((*shaker)->next != NULL)
		(*shaker)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*shaker)->next;
	(*shaker)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *shaker;
	else
		*list = *shaker;
	(*shaker)->next = tmp;
	tmp->prev = *shaker;
	*shaker = tmp;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm.
 *
 * @list: pointer to a listint_t doubly-linked list head.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool shake_n_stir = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (shake_n_stir == false)
	{
		shake_n_stir = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				front_node_swap(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shake_n_stir = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				back_node_swap(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				shake_n_stir = false;
			}
		}
	}
}
