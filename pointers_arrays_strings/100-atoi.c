#include "main.h"
#include <limits.h>
/**
* _atoi - convert a string to an integer
* @s: input C-string
* Return: integer value, or 0 if no digits
*
* Rules:
* - Any characters may precede the number.
* - Every '-' before the first digit flips the sign; '+' is ignored.
* - Parse the first contiguous digit sequence only.
* - Clamp on overflow to INT_MAX / INT_MIN.
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
started = 1;
/* overflow-safe accumulation */
if (sign == 1)
{
if (res > (INT_MAX - d) / 10)
return (INT_MAX);
res = res * 10 + d;
}
else
{
/* allow magnitude up to INT_MAX + 1 */
if (res > (INT_MAX - d + 1) / 10)
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
