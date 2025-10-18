#include "lists.h"

/**
 * get_dnodeint_at_index - get the nth node of a dlistint_t list
 * @head: head pointer
 * @index: index starting from 0
 *
 * Return: pointer to node at index, or NULL if not found
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i = 0;

	while (head)
	{
		if (i == index)
			return (head);
		head = head->next;
		i++;
	}
	return (NULL);
}
