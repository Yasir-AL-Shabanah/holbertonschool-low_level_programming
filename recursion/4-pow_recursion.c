#include "main.h"

/**
 * _pow_recursion - compute x raised to y recursively
 * @x: base
 * @y: exponent
 * Return: x^y, or -1 if y < 0
 */
int _pow_recursion(int x, int y)
{
	if (y < 0)
		return (-1);
	if (y == 0)
		return (1);
	return (x * _pow_recursion(x, y - 1));
}
