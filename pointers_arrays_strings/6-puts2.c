#include "main.h"

/**
* puts2 - print every other character of a string, starting with the first
* @str: input string
* Return: void
*/
void puts2(char *str)
{
int i;

if (str == 0)
{
_putchar('\n');
return;
}

for (i = 0; str[i] != '\0'; i++)
{
if ((i % 2) == 0)
_putchar(str[i]);
}
_putchar('\n');
}
