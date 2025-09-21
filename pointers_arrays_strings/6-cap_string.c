#include "main.h"

/**
 * cap_string - capitalize all words of a string
 * @s: string
 * Return: s
 */
char *cap_string(char *s)
{
	char sep[] = " \t\n,;.!?\"(){}";
	int i = 0, j;

	if (s[0] >= 'a' && s[0] <= 'z')
		s[0] = s[0] - ('a' - 'A');
	while (s[i] != '\0')
	{
		if (s[i] >= 'a' && s[i] <= 'z')
		{
			j = 0;
			while (sep[j] != '\0')
			{
				if (s[i - 1] == sep[j])
				{
					s[i] = s[i] - ('a' - 'A');
					break;
				}
				j++;
			}
		}
		i++;
	}
	return (s);
}
