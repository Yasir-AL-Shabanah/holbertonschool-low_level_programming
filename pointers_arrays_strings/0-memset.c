#include "main.h"

/**
 * _memset - fill memory with a constant byte
 * @s: pointer to memory area
 * @b: byte value
 * @n: number of bytes to fill
 * Return: pointer to s
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;

	while (i < n)
	{
		s[i] = b;
		i++;
	}
	return (s);
}
