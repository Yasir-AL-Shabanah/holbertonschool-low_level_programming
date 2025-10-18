#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - read a text file and print to POSIX stdout
 * @filename: path to file
 * @letters: max bytes to read and print
 *
 * Return: actual number of bytes printed,
 *         or 0 on any error (open/read/write).
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread, nwritten, total = 0;
	char *buf;

	if (!filename || letters == 0)
		return (0);

	buf = malloc(letters);
	if (!buf)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free(buf);
		return (0);
	}

	nread = read(fd, buf, letters);
	if (nread <= 0)
	{
		close(fd);
		free(buf);
		return (0);
	}

	/* اكتب كل ما قُرئ حتى لو write كتب جزئياً */
	while (total < nread)
	{
		nwritten = write(STDOUT_FILENO, buf + total, nread - total);
		if (nwritten <= 0)
		{
			total = 0;
			break;
		}
		total += nwritten;
	}

	close(fd);
	free(buf);
	return (total);
}
