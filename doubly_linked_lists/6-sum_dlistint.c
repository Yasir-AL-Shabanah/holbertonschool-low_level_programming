#include "lists.h"

/**
 * sum_dlistint - sum all data (n) of a dlistint_t list
 * @head: head pointer
 *
 * Return: sum (0 if list is empty)
 */
int sum_dlistint(dlistint_t *head)
{
	long sum = 0;

	while (head)
	{
		sum += head->n;
		head = head->next;
	}
	return ((int)sum);
}
