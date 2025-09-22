#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_numbers - prints numbers separated by a string, then newline
 * @separator: string printed between numbers (ignored if NULL)
 * @n: count of numbers to print
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	va_list ap;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator && i + 1 < n)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
