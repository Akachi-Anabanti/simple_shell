#include "main.h"

/**
 * prompt - displays prompt
 */
void prompt(void)
{
	char *str = "root@hshell$ ";

	write(STDOUT_FILENO, str, _strlen(str));
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _strlen - length of a string
 *
 * @str: pointer to string
 * Return: str length
 */
size_t _strlen(const char *str)
{
	size_t len = 0;

	if (str == NULL)
	{
		return (0);
	}
	while (str[len] != '\0')
		len++;
	return (len);
}
