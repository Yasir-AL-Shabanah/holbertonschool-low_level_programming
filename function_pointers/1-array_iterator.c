#include "function_pointers.h"

/**
 * array_iterator - applies an action to each element of an int array
 * @array: pointer to the first element
 * @size: number of elements
 * @action: function pointer operating on each int
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i = 0;

	if (!array || !action)
		return;

	while (i < size)
	{
		action(array[i]);
		i++;
	}
}
