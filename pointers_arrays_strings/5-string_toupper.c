#include "main.h"

/**
 * string_toupper - change all lowercase letters to uppercase
 * @s: string
 * Return: s
 */
char *string_toupper(char *s)
{
	char *p = s;

	while (*p)
	{
		if (*p >= 'a' && *p <= 'z')
			*p = *p - ('a' - 'A');
		p++;
	}
	return (s);
}
