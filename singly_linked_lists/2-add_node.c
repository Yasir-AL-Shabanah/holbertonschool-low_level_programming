#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a new node at the beginning
 * @head: address of head pointer
 * @str: string to duplicate
 *
 * Return: address of new element, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	unsigned int len = 0;

	if (!head || !str)
		return (NULL);

	node = malloc(sizeof(*node));
	if (!node)
		return (NULL);

	/* Duplicate string into newly allocated memory */
	node->str = strdup(str);
	if (!node->str)
	{
		free(node);
		return (NULL);
	}

	while (str[len])
		len++;

	node->len = len;
	node->next = *head;
	*head = node;

	return (node);
}
