#include "lists.h"

/**
 * list_len - count elements of a list_t list
 * @h: head pointer (const)
 *
 * Return: number of nodes
 */
size_t list_len(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}
	return (count);
}
