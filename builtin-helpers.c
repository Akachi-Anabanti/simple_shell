#include "main.h"


/**
 * isBuiltin - checks if a command is builtin
 * @arg: command arg
 * Return: 0 on success else -1;
 */
int isBuiltin(char *arg)
{
	int i;
	char *builtin_commands[] = {"exit", "cd", "env", "setenv", "unsetenv", NULL};

	for (i = 0; builtin_commands[i] != NULL; i++)
		if (strcmp(builtin_commands[i], arg) == 0)
			return (0);
	return (-1);
}
/**
 * exec_builtin - checks if a command is builtin
 * @args: command arguments vector
 */

void exec_builtin(char **args)
{
	size_t i;
	funcMapper functions[] = {

		{"exit", _stop},
		{"cd", _changedir},
		{"env", _printenv},
		{"setenv", set_env},
		{"unsetenv", un_setenv},
		{NULL, NULL},

	};

	for (i = 0; i < (sizeof(functions) / sizeof(functions[0])); i++)
	{
		if (_strcmp(args[0], functions[i].cmd) == 0)
		{
			functions[i].function(args);
			return;
		}
	}
}
