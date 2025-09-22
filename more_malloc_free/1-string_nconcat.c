#include "main.h"
#include <stdlib.h>

/**
 * _len - compute C-string length (NULL safe -> 0)
 * @s: string
 * Return: length
 */
static unsigned int _len(char *s)
{
	unsigned int n = 0;

	if (!s)
		return (0);
	while (s[n] != '\0')
		n++;
	return (n);
}

/**
 * string_nconcat - concatenate s1 with first n bytes of s2
 * @s1: first string (NULL treated as "")
 * @s2: second string (NULL treated as "")
 * @n: max bytes from s2
 * Return: newly allocated "s1 + s2[0..n-1]" NUL-terminated, or NULL on fail
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int l1 = _len(s1), l2 = _len(s2), i, j, take;
	char *res;

	take = (n >= l2) ? l2 : n;
	res = malloc(l1 + take + 1);
	if (res == NULL)
		return (NULL);

	for (i = 0; i < l1; i++)
		res[i] = s1 ? s1[i] : '\0';
	for (j = 0; j < take; j++)
		res[i + j] = s2 ? s2[j] : '\0';
	res[l1 + take] = '\0';
	return (res);
}
