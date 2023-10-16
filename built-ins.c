#include "main.h"

/**
 * _stop - exits the program with
 * @args: command arguments vector
 *
 * Return: 0 always
 */
int _stop(char **args)
{
	int i;
	int status;

	if (env_variable != NULL)
		free(env_variable);
	if (args[1] != NULL)
	{
		status = _atoi(args[1]);
		if (status == 0)
		{
			_perror_exit(args[1]);
			for (i = 0; args[i] != NULL; i++)
				free(args[i]);
			free(args);
			exit(EXIT_FAILURE);
		}
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
		exit(status);
	}
	else
	{
		for (i = 0; args[i] != NULL; i++)
			free(args[i]);
		free(args);
		exit(EXIT_SUCCESS);
	}
}

/**
 * _changedir - changes a directory
 * @args: argument vectors
 *
 * Return: 0 on sucess else 1
 */
int _changedir(char **args)
{
	char *newdir = args[1];
	char olddir[MAX_PATH_LENGTH];

	if (getcwd(olddir, sizeof(olddir)) == NULL)
	{
		perror("Unable to get current directory");
		return (1);
	}

	if (args[1] == NULL)
		newdir = _getenv("HOME");
	else
	{
		if (_strcmp(args[1], "-") == 0)
		{
			newdir = _getenv("HOME");
			if (newdir == NULL)
			{
				return (1);
			}
			write(STDOUT_FILENO, newdir, _strlen(newdir));
			_putchar('\n');
		}
	}
	if (access(newdir, F_OK) != 0)
	{
		_perror_file(args[0], newdir);
		return (1);
	}
	if (chdir(newdir) == 0)
	{
		if (_setenv("PWD", newdir, 1) != 0 || _setenv("OLDPWD", olddir, 1) != 0)
			perror("setenv");
	}
	else
	{
		_perror_file(args[0], newdir);
		return (1);
	}
	return (0);
}

/**
 * _printenv - prints the environment
 * @args: argument vector
 *
 * Return: 1 on success
 */
int _printenv(char __attribute__((unused)) **args)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		_putchar('\n');
		i++;
	}
	return (1);
}
