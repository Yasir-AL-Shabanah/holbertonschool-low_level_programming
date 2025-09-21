#include "main.h"
#include <limits.h>

/**
 * _atoi - convert string to int (handles multiple signs and overflow)
 * @s: input string
 * Return: converted int, or 0 if no digits
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0;
	int res = 0;

	while (s[i])
	{
		if (!started)
		{
			if (s[i] == '-')
				sign *= -1;
			else if (s[i] == '+')
				;
			else if (s[i] >= '0' && s[i] <= '9')
				started = 1;
		}
		if (started)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				int d = s[i] - '0';

				if (sign == 1)
				{
					if (res > INT_MAX / 10 ||
					    (res == INT_MAX / 10 && d > INT_MAX % 10))
						return (INT_MAX);
					res = res * 10 + d;
				}
				else
				{
					if (res > 214748364 ||
					    (res == 214748364 && d > 8))
						return (INT_MIN);
					res = res * 10 + d;
				}
			}
			else
			{
				break;
			}
		}
		i++;
	}
	if (!started)
		return (0);
	return (sign == 1 ? res : -res);
}
