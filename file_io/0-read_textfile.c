#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - Reads a text file and prints it to POSIX stdout.
 * @filename: Path to file (must not be NULL).
 * @letters: Max number of bytes to read and print.
 *
 * Return: Actual number of bytes printed on success,
 *         or 0 if @filename is NULL, or open/read/write fails.
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

	/* handle partial writes until all nread bytes are printed */
	while (total < nread)
	{
		nwritten = write(STDOUT_FILENO, buf + total, nread - total);
		if (nwritten <= 0)
		{
			total = 0; /* spec: return 0 on write failure */
			break;
		}
		total += nwritten;
	}

	close(fd);
	free(buf);
	return (total);
}
