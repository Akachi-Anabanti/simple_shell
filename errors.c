#include "main.h"
/*====================ERROR PRINTS=======================*/

/**
 * command_not_found - prints command not found error
 * @arg: The commnad
 */
void command_not_found(char *arg)
{
	int i;
	char **buffer;
	char *message = ": command not found\n";

	buffer = malloc(sizeof(char *) * 2);
	buffer[0] = malloc(sizeof(char) * (_strlen(arg) + 1));
	buffer[1] = malloc(sizeof(char) * (_strlen(message) + 1));

	_strcpy(buffer[0], arg);
	_strcpy(buffer[1], message);
	for (i = 0; i <= 1; i++)
	{
		write(STDOUT_FILENO, buffer[i], _strlen(buffer[i]));
		free(buffer[i]);
	}
	free(buffer);
}

/**
 * _perror_file - prints error for path not found
 * @arg: path argument
 * @str: options
 */
void _perror_file(char *arg, char *str)
{
	char message[100] = "-hsh: ";

	_strcat(message, arg);

	if (str != NULL)
	{
		_strcat(message, ": ");
		_strcat(message, str);
	}

	/**
	 * should display "-hsh: {arg}: No such file or directory"
	 */
	perror(message);
}
/**
 * _perror_exit - prints error message for exit
 * @arg: error argument
 */
void _perror_exit(char *arg)
{
	char *message;
	char *start = "-hsh: exit: ";
	char *end = ": numeric argument required";

	message = malloc(sizeof(char) * (_strlen(start) +
				_strlen(end) + _strlen(arg) + 3));
	if (message == NULL)
	{
		perror("Memory allocation failure");
		return;
	}
	_strcpy(message, start);
	_strcat(message, arg);
	_strcat(message, end);
	_strcat(message, "\n");

	write(STDERR_FILENO, message, _strlen(message));

	free(message);
}

