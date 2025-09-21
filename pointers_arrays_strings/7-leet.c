#include "main.h"

/**
 * leet - encode string to 1337
 * @s: string
 * Return: s
 */
char *leet(char *s)
{
	char a[] = "aAeEoOtTlL";
	char b[] = "4433007711";
	int i = 0, j;

	while (s[i] != '\0')
	{
		j = 0;
		while (a[j] != '\0')
		{
			if (s[i] == a[j])
			{
				s[i] = b[j];
				break;
			}
			j++;
		}
		i++;
	}
	return (s);
}
