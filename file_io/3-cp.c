#include "main.h"
#include <stdlib.h>
#include <stdio.h>

#define BUF_SIZE 1024
#define ERR_USE 97
#define ERR_RD  98
#define ERR_WR  99
#define ERR_CL  100

static void die_usage(const char *prog)
{
	dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", prog);
	exit(ERR_USE);
}

static void die_read(const char *name)
{
	dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", name);
	exit(ERR_RD);
}

static void die_write(const char *name)
{
	dprintf(STDERR_FILENO, "Error: Can't write to %s\n", name);
	exit(ERR_WR);
}

static void die_close(int fd)
{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
	exit(ERR_CL);
}

/**
 * main - copy contents of one file to another (cp-like)
 * @ac: argc
 * @av: argv
 *
 * Return: 0 on success, exits with 97/98/99/100 on failure
 */
int main(int ac, char **av)
{
	int fdr, fdw;
	ssize_t r, w;
	char buf[BUF_SIZE];

	if (ac != 3)
		die_usage(av[0]);

	fdr = open(av[1], O_RDONLY);
	if (fdr == -1)
		die_read(av[1]);

	fdw = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fdw == -1)
	{
		close(fdr);
		die_write(av[2]);
	}

	while ((r = read(fdr, buf, BUF_SIZE)) > 0)
	{
		ssize_t off = 0;

		while (off < r)
		{
			w = write(fdw, buf + off, r - off);
			if (w <= 0)
			{
				close(fdr);
				close(fdw);
				die_write(av[2]);
			}
			off += w;
		}
	}
	if (r == -1)
	{
		close(fdr);
		close(fdw);
		die_read(av[1]);
	}

	if (close(fdr) == -1)
		die_close(fdr);
	if (close(fdw) == -1)
		die_close(fdw);

	return (0);
}
