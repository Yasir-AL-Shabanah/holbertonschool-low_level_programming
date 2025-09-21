#include "main.h"

/**
 * _isalpha - Check if character is alphabetic
 * @c: The character code to check
 *
 * Return: 1 if letter (lowercase or uppercase), 0 otherwise
 */
int _isalpha(int c)
{
if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
return (1);
else
return (0);
}
