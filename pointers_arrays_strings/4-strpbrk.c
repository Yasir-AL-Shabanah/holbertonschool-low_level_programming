#include "main.h"
#include <stddef.h>

/**
 * _strpbrk - search a string for any of a set of bytes
 * @s: string to scan
 * @accept: bytes to match
 * Return: pointer to the first match in s, or NULL
 */
char *_strpbrk(char *s, char *accept)
{
	char *p;

	while (*s)
	{
		p = accept;
		while (*p)
		{
			if (*s == *p)
				return (s);
			p++;
		}
		s++;
	}
	return (NULL);
}
