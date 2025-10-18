#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node_end - add a new node at the end
 * @head: address of head pointer
 * @str: string to duplicate (must be duplicated)
 *
 * Return: address of new element, or NULL on failure
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *node, *tmp;
	unsigned int len = 0;

	if (!head || !str)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}

	while (str[len])
		len++;

	node->len = len;
	node->next = NULL;

	if (!*head)
	{
		*head = node;
		return (node);
	}

	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	tmp->next = node;
	return (node);
}
