#include <stdio.h>
/**
* main - Print single digit numbers from 0 to 9 using putchar
* Return: 0 on success
*/
int main(void)
{
int n;
for (n = 0; n < 10; n++)
putchar(n + '0');
putchar('\n');
return (0);
}
