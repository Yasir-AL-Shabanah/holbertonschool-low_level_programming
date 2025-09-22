#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints values based on a format string
 * @format: list of arg types:
 *          c (char), i (int), f (float/double), s (char *)
 *
 * Notes:
 * - If a string is NULL, print "(nil)".
 * - Unrecognized specifiers are ignored.
 * - No for/goto/else/do...while; max 2 while; max 2 if; max 9 vars.
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	char *s;
	char *sep = "";
	va_list ap;

	va_start(ap, format);

	while (format && format[i])
	{
		switch (format[i])
		{
		case 'c':
			printf("%s%c", sep, (char)va_arg(ap, int));
			sep = ", ";
			break;
		case 'i':
			printf("%s%d", sep, va_arg(ap, int));
			sep = ", ";
			break;
		case 'f':
			printf("%s%f", sep, va_arg(ap, double));
			sep = ", ";
			break;
		case 's':
			s = va_arg(ap, char *);
			if (s == NULL)
				s = "(nil)";
			printf("%s%s", sep, s);
			sep = ", ";
			break;
		default:
			break;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
