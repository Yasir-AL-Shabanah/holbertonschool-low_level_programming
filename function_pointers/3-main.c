#include <stdio.h>
#include <stdlib.h>
#include "3-calc.h"

/**
 * main - simple calculator
 * @argc: count
 * @argv: vector (num1 op num2)
 *
 * Return: 0 on success, exits with:
 * 98 (wrong argc), 99 (bad op), 100 (div/mod by zero)
 *
 * Constraints:
 * - No loops in main
 * - Use atoi
 * - Max 3 if statements
 * - Do not call op_* directly
 */
int main(int argc, char *argv[])
{
	int a, b, res;
	int (*f)(int, int);

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	f = get_op_func(argv[2]);
	if (!f)
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((argv[2][0] == '/' || argv[2][0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	res = f(a, b);
	printf("%d\n", res);
	return (0);
}
