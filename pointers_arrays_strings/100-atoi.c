#include "main.h"
#include <limits.h>

/**
 * goto_digits - skip non-digits and count sign
 * @p: input string
 * @sign: pointer to sign
 * Return: pointer to first digit or NULL
 */
static char *goto_digits(char *p, int *sign)
{
	int allow = 1;

	while (*p)
	{
		if (*p == ' ' || *p == '\t' || *p == '\n' ||
		    *p == '\r' || *p == '\v' || *p == '\f')
		{
			p++;
			continue;
		}
		if ((*p == '+' || *p == '-') && allow)
		{
			if (*p == '-')
				*sign *= -1;
			p++;
			continue;
		}
		if (*p >= '0' && *p <= '9')
			return (p);
		allow = 0;
		p++;
	}
	return (0);
}

/**
 * _atoi - convert string to int with multi-sign and overflow check
 * @s: input string
 * Return: integer result
 */
int _atoi(char *s)
{
	int sign = 1;
	int res = 0;
	char *p = goto_digits(s, &sign);

	if (!p)
		return (0);
	while (*p >= '0' && *p <= '9')
	{
		int d = *p - '0';

		if (sign == 1)
		{
			if (res > INT_MAX / 10 ||
			    (res == INT_MAX / 10 && d > INT_MAX % 10))
				return (INT_MAX);
			res = res * 10 + d;
		}
		else
		{
			if (res < INT_MIN / 10 ||
			    (res == INT_MIN / 10 && -d < INT_MIN % 10))
				return (INT_MIN);
			res = res * 10 - d;
		}
		p++;
	}
	return (res);
}
