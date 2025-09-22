#include <stdio.h>
#include <stdlib.h>

/**
 * is_number - check if a C-string contains only decimal digits
 * @s: input string
 * Return: 1 if all digits, 0 otherwise
 */
int is_number(const char *s)
{
	if (*s == '\0')
		return (0);
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}

/**
 * main - add positive numbers passed as arguments
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 1 if any arg is not a positive integer
 */
int main(int argc, char *argv[])
{
	int i = 1;
	int sum = 0;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}
	while (i < argc)
	{
		if (!is_number(argv[i]))
		{
			printf("Error\n");
			return (1);
		}
		sum += atoi(argv[i]);
		i++;
	}
	printf("%d\n", sum);
	return (0);
}
