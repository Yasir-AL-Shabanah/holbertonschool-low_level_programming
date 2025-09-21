#include "main.h"

/**
* _strlen - return the length of a string
* @s: pointer to string
* Return: length of s
*/
int _strlen(char *s)
{
int len = 0;
while (s[len] != '\0')
len++;
return (len);
}
