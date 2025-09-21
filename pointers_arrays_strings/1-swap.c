#include "main.h"

/**
* swap_int - swap the values of two integers
* @a: pointer to first int
* @b: pointer to second int
* Return: void
*/
void swap_int(int *a, int *b)
{
int tmp = *a;
*a = *b;
*b = tmp;
}
