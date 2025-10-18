#include "lists.h"
#include <stdio.h>

/**
 * print_list - print all elements of a list_t list
 * @h: head pointer (const)
 *
 * Return: number of nodes
 */
size_t print_list(const list_t *h)
{
	size_t count = 0;

	while (h)
	{
		if (h->str)
			printf("[%u] %s\n", h->len, h->str);
		else
			printf("[0] (nil)\n");

		h = h->next;
		count++;
	}
	return (count);
}
