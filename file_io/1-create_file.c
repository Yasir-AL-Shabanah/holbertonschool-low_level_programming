#include "main.h"
#include <stdlib.h>

/**
 * _len - local strlen replacement (no stdlib)
 * @s: string (may be NULL)
 * Return: length (0 if NULL)
 */
static size_t _len(const char *s)
{
	size_t n = 0;

	if (!s)
		return (0);
	while (s[n])
		n++;
	return (n);
}

/**
 * create_file - creates a file with mode 0600 and writes text
 * @filename: name of file to create
 * @text_content: NULL-terminated string to write (may be NULL)
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	size_t len;
	ssize_t w, total = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	len = _len(text_content);
	while (total < (ssize_t)len)
	{
		w = write(fd, text_content + total, len - total);
		if (w <= 0)
		{
			close(fd);
			return (-1);
		}
		total += w;
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
