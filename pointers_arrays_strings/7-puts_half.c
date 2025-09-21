#include "main.h"

/**
* puts_half - print the second half of a string followed by a new line
* @str: pointer to string
* Return: void
*/
void puts_half(char *str)
{
int len = 0;
int start;
while (str[len] != '\0')
len++;
if (len % 2 == 0)
start = len / 2;
else
start = (len + 1) / 2;
while (str[start] != '\0')
{
_putchar(str[start]);
start++;
}
_putchar('\n');
}
