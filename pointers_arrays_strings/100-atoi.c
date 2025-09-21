#include "main.h"
#include <limits.h>

/**
* is_space - check if char is a standard whitespace
* @c: input char
* Return: 1 if whitespace, 0 otherwise
*/
static int is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' ||
	    c == '\r' || c == '\f' || c == '\v')
		return (1);
	return (0);
}

/**
* parse_sign - parse consecutive + and - signs and advance index
* @s: input string
* @i: pointer to current index (updated)
* Return: +1 or -1
*/
static int parse_sign(const char *s, int *i)
{
	int sign = 1;

	while (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -sign;
		(*i)++;
	}
	return (sign);
}

/**
* accumulate_digits - accumulate digits with overflow handling
* @s: input string
* @i: starting index of first digit
* @sign: +1 or -1
* Return: converted integer with sign, INT_MAX/INT_MIN on overflow
*/
static int accumulate_digits(const char *s, int i, int sign)
{
	int res = 0;

	while (s[i] >= '0' && s[i] <= '9')
	{
		int d = s[i] - '0';

		if (sign == 1)
		{
			if (res > (INT_MAX - d) / 10)
				return (INT_MAX);
			res = res * 10 + d;
		}
		else
		{
			/* for negative, allow magnitude up to INT_MAX + 1 */
			if (res > (INT_MAX - d + 1) / 10)
				return (INT_MIN);
			res = res * 10 + d;
		}
		i++;
	}
	return (sign == 1 ? res : -res);
}

/**
* _atoi - convert a string to an integer
* @s: input C-string
* Return: integer value, or 0 if no digits
*/
int _atoi(char *s)
{
	int i = 0, sign, has_digit = 0, val;

	while (s[i] && is_space(s[i]))
		i++;

	sign = parse_sign(s, &i);

	if (s[i] >= '0' && s[i] <= '9')
		has_digit = 1;

	val = accumulate_digits(s, i, sign);

	if (!has_digit)
		return (0);
	return (val);
}
