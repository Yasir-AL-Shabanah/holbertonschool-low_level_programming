#include "lists.h"
#include <stdlib.h>

/**
 * insert_dnodeint_at_index - insert a new node at given index
 * @h: address of head pointer
 * @idx: index where new node should be added (0-based)
 * @n: value to store
 *
 * Return: address of new node, or NULL on failure/invalid index
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *curr;
	unsigned int i = 0;

	if (!h)
		return (NULL);

	if (idx == 0)
		return (add_dnodeint(h, n));

	curr = *h;
	while (curr && i < idx - 1)
	{
		curr = curr->next;
		i++;
	}
	if (!curr)
		return (NULL);

	if (!curr->next)
		return (add_dnodeint_end(h, n));

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->n = n;
	node->prev = curr;
	node->next = curr->next;
	curr->next->prev = node;
	curr->next = node;

	return (node);
}
