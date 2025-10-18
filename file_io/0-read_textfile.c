#include "main.h"
#include <stdlib.h>

/**
 * read_textfile - reads a text file and prints it to STDOUT
 * @filename: path to file
 * @letters: max number of letters to read & print
 *
 * Return: actual number of letters printed, or 0 on any error
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t r, w, total = 0;
	char *buf;

	if (!filename || letters == 0)
		return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);

	buf = malloc(letters);
	if (!buf)
	{
		close(fd);
		return (0);
	}

	r = read(fd, buf, letters);
	if (r <= 0)
	{
		free(buf);
		close(fd);
		return (0);
	}

	/* handle partial writes */
	while (total < r)
	{
		w = write(STDOUT_FILENO, buf + total, r - total);
		if (w <= 0)
		{
			free(buf);
			close(fd);
			return (0);
		}
		total += w;
	}

	free(buf);
	if (close(fd) == -1)
		return (0);

	return (total);
}
