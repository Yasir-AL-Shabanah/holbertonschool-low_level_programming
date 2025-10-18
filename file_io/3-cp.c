#include "main.h"
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 1024

static void safe_close(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * main - copy content of file_from to file_to
 * @ac: argc
 * @av: argv (file_from, file_to)
 *
 * Return: 0 on success; exits with 97/98/99/100 on failure.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t n, w;
	char buf[BUF_SIZE];

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		safe_close(fd_from);
		exit(99);
	}

	while ((n = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		ssize_t off = 0;

		while (off < n)
		{
			w = write(fd_to, buf + off, n - off);
			if (w == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
				safe_close(fd_from);
				safe_close(fd_to);
				exit(99);
			}
			off += w;
		}
	}
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		safe_close(fd_from);
		safe_close(fd_to);
		exit(98);
	}

	safe_close(fd_from);
	safe_close(fd_to);
	return (0);
}
