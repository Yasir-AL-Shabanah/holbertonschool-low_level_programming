#include "variadic_functions.h"
#include <stdio.h>

/**
 * print_all - prints anything based on a format string
 * @format: list of types of args: c (char), i (int), f (float/double), s (char*)
 *
 * Rules:
 * - If s is NULL, print (nil)
 * - Ignore any other unrecognized specifiers
 * - No for/goto/else/do...while
 * - Max 2 while loops, Max 2 ifs, Max 9 variables
 *
 * Return: void
 */
void print_all(const char * const format, ...)
{
	unsigned int i = 0;
	char *s, *sep = "";
	va_list ap;

	va_start(ap, format);

	/* while #1: iterate over format safely even if format == NULL */
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
			if (s == 0) /* if #1 */
				s = "(nil)";
			printf("%s%s", sep, s);
			sep = ", ";
			break;
		default:
			/* ignore unrecognized specifier */
			break;
		}
		i++;
	}

	printf("\n");
	va_end(ap);
}
