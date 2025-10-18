#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - delete node at index
 * @head: address of head pointer
 * @index: index of node to delete (0-based)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	curr = *head;

	if (index == 0)
	{
		*head = curr->next;
		if (*head)
			(*head)->prev = NULL;
		free(curr);
		return (1);
	}

	while (curr && i < index)
	{
		curr = curr->next;
		i++;
	}

	if (!curr)
		return (-1);

	if (curr->prev)
		curr->prev->next = curr->next;
	if (curr->next)
		curr->next->prev = curr->prev;

	free(curr);
	return (1);
}
