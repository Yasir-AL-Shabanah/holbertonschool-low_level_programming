#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenate two strings into new allocated memory
 * @s1: first string (NULL treated as "")
 * @s2: second string (NULL treated as "")
 * Return: pointer to concatenated string, or NULL on fail
 */
char *str_concat(char *s1, char *s2)
{
	int len1 = 0, len2 = 0, i, j;
	char *res;

	if (s1)
		while (s1[len1] != '\0')
			len1++;
	if (s2)
		while (s2[len2] != '\0')
			len2++;
	res = malloc((len1 + len2 + 1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	for (i = 0; i < len1; i++)
		res[i] = s1[i];
	for (j = 0; j < len2; j++)
		res[i + j] = s2[j];
	res[len1 + len2] = '\0';
	return (res);
}
