#include "3-calc.h"

/**
 * op_add - sum
 * @a: left
 * @b: right
 * Return: a + b
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - difference
 * @a: left
 * @b: right
 * Return: a - b
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - product
 * @a: left
 * @b: right
 * Return: a * b
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - quotient (assumes b != 0)
 * @a: left
 * @b: right
 * Return: a / b
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - remainder (assumes b != 0)
 * @a: left
 * @b: right
 * Return: a % b
 */
int op_mod(int a, int b)
{
	return (a % b);
}
