#include "main.h"

/**
 * prime_helper - recursively test divisors up to sqrt(n)
 * @n: number to test
 * @d: current divisor
 * Return: 1 if prime, 0 otherwise
 */
static int prime_helper(int n, int d)
{
	if (d * d > n)
		return (1);
	if (n % d == 0)
		return (0);
	return (prime_helper(n, d + 1));
}

/**
 * is_prime_number - return 1 if n is prime, else 0
 * @n: input integer
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	return (prime_helper(n, 2));
}
