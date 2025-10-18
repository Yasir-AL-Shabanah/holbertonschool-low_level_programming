#include "main.h"

/**
 * _strlen - minimal strlen
 * @s: string
 * Return: length
 */
static size_t _strlen(const char *s)
{
	size_t l = 0;

	while (s && s[l])
		l++;
	return (l);
}

/**
 * append_text_to_file - append text at end of an existing file
 * @filename: path
 * @text_content: NULL-terminated text (may be NULL)
 *
 * Return: 1 on success, -1 on failure.
 *         If text_content is NULL: return 1 if file exists (open OK),
 *         else -1.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd;

	if (!filename)
		return (-1);

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		ssize_t len = (ssize_t)_strlen(text_content);
		ssize_t w = write(fd, text_content, len);

		if (w != len)
		{
			close(fd);
			return (-1);
		}
	}

	if (close(fd) == -1)
		return (-1);

	return (1);
}
