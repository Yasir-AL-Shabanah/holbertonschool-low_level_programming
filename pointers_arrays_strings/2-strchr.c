#include "main.h"
#include <stddef.h>

/**
 * _strchr - locate character in string
 * @s: string
 * @c: character to find
 * Return: pointer to first occurrence or NULL
 */
char *_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	if (c == '\0')
		return (s);
	return (NULL);
}
