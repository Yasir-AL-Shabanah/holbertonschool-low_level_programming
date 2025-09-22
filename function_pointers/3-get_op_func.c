#include "3-calc.h"

/**
 * get_op_func - select the right op function
 * @s: operator string
 *
 * Return: pointer to function for operator, or NULL if not found
 *
 * Notes (constraints):
 * - No switch / no goto
 * - Max 1 if
 * - Max 1 while
 * - No else
 * - Only 2 declared variables in this function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add}, {"-", op_sub}, {"*", op_mul},
		{"/", op_div}, {"%", op_mod}, {0, 0}
	};
	int i;

	/* ensure single-char operator */
	if (!s || s[0] == '\0' || s[1] != '\0')
		return (0);

	i = 0;
	while (ops[i].op && *(ops[i].op) != *s)
		i++;

	return (ops[i].f);
}
