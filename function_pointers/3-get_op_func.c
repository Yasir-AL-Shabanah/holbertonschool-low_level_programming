#include "3-calc.h"

/**
 * get_op_func - selects the correct operation
 * @s: operator string
 *
 * Return: pointer to function for operator, or NULL if invalid
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op && *(ops[i].op) != *s)
		i++;

	if (!ops[i].op || s[1] != '\0')
		return (NULL);

	return (ops[i].f);
}
