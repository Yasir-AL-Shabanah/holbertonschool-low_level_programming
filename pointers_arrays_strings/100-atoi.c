#include "main.h"
#include <limits.h>

/**
* _atoi - convert a string to an integer
* @s: input string
* Return: converted integer (handles INT_MIN correctly)
*/
int _atoi(char *s)
{
unsigned int num = 0;
int sign = 1;
int started = 0;
/* حدود آمنة مشتقة من INT_MAX و |INT_MIN| بدون أرقام صلبة */
unsigned int pos_div10 = (unsigned int)(INT_MAX / 10);
unsigned int pos_mod10 = (unsigned int)(INT_MAX % 10);
unsigned int neg_abs = (unsigned int)INT_MAX + 1U; /* 2147483648 on 32-bit int */
unsigned int neg_div10 = neg_abs / 10;
unsigned int neg_mod10 = neg_abs % 10;

while (*s != '\0')
{
if (*s == '+' || *s == '-')
{
if (started)
break;
if (*s == '-')
sign = -sign;
}
else if (*s >= '0' && *s <= '9')
{
unsigned int d = (unsigned int)(*s - '0');
started = 1;
if (sign > 0)
{
/* تحقق تجاوز الموجب */
if (num > pos_div10 || (num == pos_div10 && d > pos_mod10))
return INT_MAX;
num = (num * 10U) + d;
}
else
{
/* نسمح بالمقدار حتى 2147483648 لأجل INT_MIN */
if (num > neg_div10 || (num == neg_div10 && d > neg_mod10))
return INT_MIN;
num = (num * 10U) + d;
}
}
else if (started)
{
break;
}
s++;
}

if (!started)
return 0;

if (sign < 0)
{
/* إن كان المقدار 2147483648 نُعيد INT_MIN، وإلا السالب العادي */
if (num == neg_abs)
return INT_MIN;
return -(int)num;
}
return (int)num;
}
