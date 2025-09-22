#include "3-calc.h"

/**
 * get_op_func - selects the correct operation
 * @s: operator string
 *
 * Return: pointer to function for operator, or NULL if invalid
 *
 * Constraints honored:
 *  - No switch
 *  - No for / do...while
 *  - No goto
 *  - No else
 *  - ≤ 1 if statement in this function
 *  - ≤ 1 while loop in this function
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{(char *)0, (int (*)(int, int))0}
	};
	int i = 0;

	/* الوحيدة if: تحقق من s وعدم تعدد أحرف العامل */
	if (!s || s[1] != '\0')
		return ((int (*)(int, int))0);

	while (ops[i].op && *(ops[i].op) != *s)
		i++;

	return (ops[i].f);
}
