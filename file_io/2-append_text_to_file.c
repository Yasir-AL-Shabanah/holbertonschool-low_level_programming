#include "main.h"

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
 * append_text_to_file - appends text at the end of a file
 * @filename: file name
 * @text_content: text to append (may be NULL)
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;
	size_t len;
	ssize_t w, done = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	len = _len(text_content);
	while (done < (ssize_t)len)
	{
		w = write(fd, text_content + done, len - done);
		if (w <= 0)
		{
			close(fd);
			return (-1);
		}
		done += w;
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
