#include "main.h"
#include <limits.h>

static char *goto_digits(char *p,int *sign)
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
			int nd = (INT_MAX % 10) + 1;

			if (res > INT_MAX / 10 ||
			    (res == INT_MAX / 10 && d > nd))
				return (INT_MIN);
			res = res * 10 + d;
		}
		p++;
	}
	return (sign == 1 ? res : -res);
}
