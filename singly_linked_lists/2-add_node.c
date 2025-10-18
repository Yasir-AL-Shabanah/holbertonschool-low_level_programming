#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: address of the head pointer
 * @str: string to duplicate
 *
 * Return: address of the new element, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
  list_t *node;
  unsigned int len = 0;

  if (head == NULL || str == NULL)
    return (NULL);

  node = malloc(sizeof(*node));
  if (node == NULL)
    return (NULL);

  /* Duplicate the input string into newly allocated memory */
  node->str = strdup(str);
  if (node->str == NULL)
  {
    free(node);
    return (NULL);
  }

  while (str[len] != '\0')
    len++;

  node->len = len;
  node->next = *head;
  *head = node;

  return (node);
}
