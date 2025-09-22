#include "main.h"

/**
 * sqrt_helper - recursive helper to find natural square root
 * @n: number to check
 * @g: current guess
 * Return: natural sqrt if exists, -1 otherwise
 */
int sqrt_helper(int n, int g)
{
	if (g * g == n)
		return (g);
	if (g * g > n)
		return (-1);
	return (sqrt_helper(n, g + 1));
}

/**
 * _sqrt_recursion - returns natural sqrt of n
 * @n: input number
 * Return: sqrt of n or -1 if none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (sqrt_helper(n, 0));
}
