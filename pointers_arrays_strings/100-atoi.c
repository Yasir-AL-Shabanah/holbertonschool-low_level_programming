#include "main.h"
#include <limits.h>
/**
* acc_pos - accumulate positive with overflow guard
* @res: current value (>=0)
* @d: digit 0..9
* Return: INT_MAX if overflow else new value
*/
static int acc_pos(int res,int d)
{
int lim=INT_MAX/10,limd=INT_MAX%10;
if(res>lim||(res==lim&&d>limd))return(INT_MAX);
return(res*10+d);
}
/**
* acc_neg - accumulate negative magnitude with overflow guard
* @res: current magnitude (>=0)
* @d: digit 0..9
* Return: INT_MIN if overflow else new magnitude
*/
static int acc_neg(int res,int d)
{
int lim=INT_MAX/10,limd=INT_MAX%10;
if(res>lim||(res==lim&&d>limd+1))return(INT_MIN);
return(res*10+d);
}
/**
* _atoi - convert string to int (handles +/- and overflow)
* @s: input string
* Return: number, 0 if no digits
*/
int _atoi(char *s)
{
int sign=1,started=0,res=0;
if(!s)return(0);
while(*s)
{
if(!started&&(*s=='-'||*s=='+'))
{if(*s=='-')sign=-sign;}
else if(*s>='0'&&*s<='9')
{
int d=*s-'0',t;
started=1;
if(sign==1){t=acc_pos(res,d);if(t==INT_MAX)return(INT_MAX);res=t;}
else{t=acc_neg(res,d);if(t==INT_MIN)return(INT_MIN);res=t;}
}
else if(started){break;}
s++;
}
if(!started)return(0);
return(sign==1?res:-res);
}
