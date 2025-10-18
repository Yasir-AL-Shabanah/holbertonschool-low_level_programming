#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint - add a new node at the beginning
 * @head: address of head pointer
 * @n: value to store
 *
 * Return: address of new element or NULL on failure
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	if (!head)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->n = n;
	node->prev = NULL;
	node->next = *head;

	if (*head)
		(*head)->prev = node;

	*head = node;
	return (node);
}
