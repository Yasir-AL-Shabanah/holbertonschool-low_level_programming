#include "main.h"

/**
 * print_alphabet_x10 - prints 10 times the alphabet in lowercase
 * Return: void
 */
void print_alphabet_x10(void)
{
int line, c;
for (line = 0; line < 10; line++)
{
for (c = 'a'; c <= 'z'; c++)
_putchar(c);
_putchar('\n');
}
}
