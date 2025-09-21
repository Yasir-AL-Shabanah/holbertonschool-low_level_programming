#include "main.h"

/**
* _atoi - convert a string to an integer
* @s: input string
* Return: converted int, or 0 if no numbers found
*/
int _atoi(char *s)
{
int i = 0;
int sign = 1;
int started = 0;
int res = 0;

while (s[i] != '\0')
{
if (s[i] == '-' && started == 0)
sign = -sign;
else if (s[i] == '+' && started == 0)
{
}
else if (s[i] >= '0' && s[i] <= '9')
{
started = 1;
res = (res * 10) + (s[i] - '0');
}
else if (started)
break;
i++;
}
return (res * sign);
}
