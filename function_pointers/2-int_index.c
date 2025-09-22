#include "function_pointers.h"

/**
 * int_index - searches for an int using a comparator
 * @array: array of ints
 * @size: number of elements
 * @cmp: comparator, returns nonzero when match
 *
 * Return: index of first match, or -1 if none / invalid
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i = 0;

	if (!array || !cmp || size <= 0)
		return (-1);

	while (i < size)
	{
		if (cmp(array[i]))
			return (i);
		i++;
	}
	return (-1);
}
