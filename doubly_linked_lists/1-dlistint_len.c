#include "lists.h"

/**
 * dlistint_len - return number of elements in a dlistint_t list
 * @h: const head pointer
 *
 * Return: number of nodes
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
