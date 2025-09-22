#include "main.h"
#include <stdlib.h>

/**
 * create_array - create char array initialized with a given char
 * @size: size of the array
 * @c: char to fill
 * Return: pointer to array, or NULL on fail/size=0
 */
char *create_array(unsigned int size, char c)
{
	char *arr;
	unsigned int i;

	if (size == 0)
		return (NULL);
	arr = malloc(size * sizeof(char));
	if (arr == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		arr[i] = c;
	return (arr);
}
