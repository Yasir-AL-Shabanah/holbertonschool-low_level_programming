#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - add a new node at the end
 * @head: address of head pointer
 * @n: value to store
 *
 * Return: address of new element or NULL on failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *tmp;

	if (!head)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	if (!*head)
	{
		*head = node;
		return (node);
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = node;
	node->prev = tmp;

	return (node);
}
