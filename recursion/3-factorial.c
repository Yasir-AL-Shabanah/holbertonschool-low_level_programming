#include "main.h"

/**
 * factorial - compute factorial of n recursively
 * @n: input integer
 * Return: n!, or -1 if n < 0
 */
int factorial(int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	return (n * factorial(n - 1));
}
