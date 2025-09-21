#include "main.h"

/**
 * _strcmp - compare two strings like strcmp
 * @s1: first string
 * @s2: second string
 * Return: 0 if equal, negative or positive diff otherwise
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((int)((unsigned char)*s1) - (int)((unsigned char)*s2));
}
