#include "main.h"
#include <stdlib.h>

/**
 * _strdup - duplicate a string into newly allocated memory
 * @str: input string
 * Return: pointer to new string, or NULL if fail
 */
char *_strdup(char *str)
{
	int len = 0, i;
	char *copy;

	if (str == NULL)
		return (NULL);
	while (str[len] != '\0')
		len++;
	copy = malloc((len + 1) * sizeof(char));
	if (copy == NULL)
		return (NULL);
	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[len] = '\0';
	return (copy);
}
