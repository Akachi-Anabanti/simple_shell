#include "main.h"

/**
 * _getline_helper - Helper function to read line from input stream
 * @buffer: Buffer to store read data
 * @bufsize: Size of buffer
 * @stream: Input stream
 *
 * Return: number of characters read
 */
ssize_t _getline_helper(char *buffer, size_t bufsize, FILE *stream)
{
	char *new_buffer, c;
	ssize_t chars_read = 0, bytes_read;
	size_t new_size;

	while (1)
	{
		bytes_read = read(fileno(stream), &c, 1);
		if (bytes_read <= 0)
		{
			if (chars_read == 0)
				return (-1);
			break;
		}
		if (chars_read >= (ssize_t)(bufsize - 1))
		{
			new_size = bufsize * 2;
			new_buffer = (char *)_realloc(buffer, bufsize, new_size);
			if (new_buffer == NULL)
				return (-1);
			buffer = new_buffer;
			bufsize = new_size;
		}
		buffer[chars_read++] = c;
		if (c == '\n')
			break;
	}
	buffer[chars_read] = '\0';
	return (chars_read);
}

/**
 * _getline - Reads line from input stream
 * @lineptr: Buffer to store read data
 * @n: size of buffer
 * @stream: input stream
 * Return: number of characters read;
 */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	char *buffer = NULL;
	size_t bufsize = *n;
	ssize_t chars_read = 0;

	if (lineptr == NULL || n == NULL || stream == NULL)
		return (-1);
	buffer = *lineptr;
	if (buffer == NULL || bufsize == 0)
	{
		bufsize = 120;
		buffer = (char *)malloc(bufsize);
		if (buffer == NULL)
			return (-1);
	}
	chars_read = _getline_helper(buffer, bufsize, stream);

	if (chars_read == -1)
	{
		free(buffer);
		return (-1);
	}
	if (*n != 0)
		*n = bufsize - 1;
	*lineptr = buffer;
	return (chars_read);
}
