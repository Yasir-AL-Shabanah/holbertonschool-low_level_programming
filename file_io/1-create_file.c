#include "main.h"

/**
 * _strlen - minimal strlen (لا يُسمح باستخدام libc المعتادة هنا)
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
 * create_file - create/overwrite file with mode 0600
 * @filename: path
 * @text_content: NULL-terminated text (may be NULL)
 *
 * Return: 1 on success, -1 on failure.
 */
int create_file(const char *filename, char *text_content)
{
	int fd;
	ssize_t len, w = 0;

	if (!filename)
		return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, 0600);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		len = (ssize_t)_strlen(text_content);
		w = write(fd, text_content, len);
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
