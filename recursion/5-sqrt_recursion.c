#include "main.h"

/**
 * sqrt_helper - helper to search natural sqrt recursively
 * @n: number
 * @g: current guess
 * Return: sqrt if exists, -1 otherwise
 */
static int sqrt_helper(int n, int g)
{
	if (g * g == n)
		return (g);
	if (g * g > n)
		return (-1);
	return (sqrt_helper(n, g + 1));
}

/**
 * _sqrt_recursion - return natural square root of n
 * @n: input integer
 * Return: sqrt(n) or -1 if none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}
