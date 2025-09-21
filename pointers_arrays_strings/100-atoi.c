#include "main.h"
#include <limits.h>
/**
* _atoi - convert a string to an integer
* @s: input string
* Return: converted integer, 0 if no digits
*/
int _atoi(char *s)
{
int sign = 1, started = 0, res = 0;
while (*s)
{
if (!started && (*s == '-' || *s == '+'))
{
if (*s == '-')
sign = -sign;
}
else if (*s >= '0' && *s <= '9')
{
int d = *s - '0';
int lim = INT_MAX / 10;
int limd = INT_MAX % 10;
started = 1;
if (sign == 1)
{
if (res > lim || (res == lim && d > limd))
return (INT_MAX);
res = res * 10 + d;
}
else
{
if (res > lim || (res == lim && d > limd + 1))
return (INT_MIN);
res = res * 10 + d;
}
}
else if (started)
{
break;
}
s++;
}
if (!started)
return (0);
return (sign == 1 ? res : -res);
}
