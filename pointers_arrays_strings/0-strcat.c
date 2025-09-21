#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: destination buffer
 * @src: source string
 * Return: dest
 */
char *_strcat(char *dest, char *src)
{
	char *d = dest;

	while (*d)
		d++;
	while (*src)
	{
		*d = *src;
		d++;
		src++;
	}
	*d = '\0';
	return (dest);
}
