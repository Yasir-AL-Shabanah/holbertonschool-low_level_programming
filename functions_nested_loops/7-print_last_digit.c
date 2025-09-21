#include "main.h"

/**
* print_last_digit - print and return the last digit of an integer
* @n: input integer
* Return: last digit as positive number
*/
int print_last_digit(int n)
{
int d = n % 10;
if (d < 0)
d = -d;
_putchar(d + '0');
return (d);
}
