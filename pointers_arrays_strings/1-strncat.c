#include "main.h"

/**
 * _strncat - concatenate at most n bytes from src to dest
 * @dest: destination buffer
 * @src: source string
 * @n: max bytes from src
 * Return: dest
 */
char *_strncat(char *dest, char *src, int n)
{
	char *d = dest;
	int i = 0;

	while (*d)
		d++;
	while (*src && i < n)
	{
		*d = *src;
		d++;
		src++;
		i++;
	}
	*d = '\0';
	return (dest);
}
