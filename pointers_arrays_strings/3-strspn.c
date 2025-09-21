#include "main.h"

/**
 * _strspn - get length of prefix substring
 * @s: string to scan
 * @accept: accepted bytes
 * Return: number of bytes in initial segment of s consisting only of accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int hit;
	char *p;

	while (*s)
	{
		hit = 0;
		p = accept;
		while (*p)
		{
			if (*s == *p)
			{
				hit = 1;
				break;
			}
			p++;
		}
		if (!hit)
			break;
		count++;
		s++;
	}
	return (count);
}
