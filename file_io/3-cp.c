#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

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
 * same_file - Checks if two paths refer to the same underlying file.
 * @a: path A
 * @b: path B
 * Return: 1 if same (same dev+ino), else 0. On any stat error, returns 0.
 */
static int same_file(const char *a, const char *b)
{
	struct stat sa, sb;

	if (!a || !b)
		return (0);
	if (stat(a, &sa) == -1 || stat(b, &sb) == -1)
		return (0);
	return (sa.st_ino == sb.st_ino && sa.st_dev == sb.st_dev);
}

/**
 * main - Copies content of file_from to file_to (buffer = 1024).
 * @ac: argc
 * @av: argv (file_from, file_to)
 *
 * Return: 0 on success; exits with 97/98/99/100 on failure.
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;
	ssize_t n, w, off;
	char *buf;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", av[0]);
		exit(97);
	}

	/* POSIX: إذا كان المصدر والوجهة نفس الملف لا تفعل شيئاً (بدون ضوضاء) */
	if (same_file(av[1], av[2]))
		return (0);

	buf = malloc(BUF_SIZE);
	if (!buf)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		exit(99);
	}

	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		free(buf), exit(98);
	}

	fd_to = open(av[2], O_WRONLY | O_CREAT | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		free(buf), safe_close(fd_from), exit(99);
	}

	/* read exactly 1024 bytes at a time (except the final chunk) */
	while ((n = read(fd_from, buf, BUF_SIZE)) > 0)
	{
		off = 0;
		while (off < n)
		{
			w = write(fd_to, buf + off, n - off);
			if (w == -1)
			{
				dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
				free(buf), safe_close(fd_from), safe_close(fd_to), exit(99);
			}
			off += w;
		}
	}
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		free(buf), safe_close(fd_from), safe_close(fd_to), exit(98);
	}

	free(buf);
	safe_close(fd_from);
	safe_close(fd_to);
	return (0);
}
