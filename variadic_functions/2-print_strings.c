#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_strings - prints strings separated by a string, then newline
 * @separator: string printed between strings (ignored if NULL)
 * @n: count of strings to print
 *
 * Return: void
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	unsigned int i;
	char *s;
	va_list ap;

	va_start(ap, n);
	for (i = 0; i < n; i++)
	{
		s = va_arg(ap, char *);
		if (s == 0)
			printf("(nil)");
		else
			printf("%s", s);

		if (separator && i + 1 < n)
			printf("%s", separator);
	}
	printf("\n");
	va_end(ap);
}
