#include "function_pointers.h"

/**
 * print_name - prints a name using a callback
 * @name: input name (may be NULL)
 * @f: function pointer to a printer (may be NULL)
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name && f)
		f(name);
}
