#include "main.h"
/**
 * _getenv - retreives the value of an en
 *
 * @name: Name of the envrionment
 * Return: pointer to value
 */
char *_getenv(const char *name)
{
	int i = 0;
	size_t name_len = _strlen(name);

	if (name == NULL)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (_strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (&environ[i][name_len + 1]);
		}
	}
	return (NULL);
}

/**
 * _setenv - set a environment variable of the form 'name=value'
 *
 * @name: name of the variable
 * @value: value of the variable
 * @overwrite: boolean t overwrite 0 false 1m true
 *
 * Return: 0
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	size_t name_len = _strlen(name);
	size_t value_len = _strlen(value);

	if (name == NULL || value == NULL)
		return (-1);
	if (overwrite == 0 && _getenv(name))
	{
		return (-1);
	}
	/*env_variable is defined in main.h as global variable*/
	env_variable = malloc(sizeof(char) * (name_len + value_len + 2));

	if (env_variable == NULL)
	{
		return (-1);
	}

	_strcpy(env_variable, name);
	_strcat(env_variable, "=");
	_strcat(env_variable, value);

	if (putenv(env_variable) != 0)
	{
		free(env_variable);
		return (-1);
	}
	return (0);
}

/**
 * set_env - Sets the environment variable
 * @args: Argument vector
 *
 * Return: 1 on success else 0
 */
int set_env(char **args)
{
	if (_setenv(args[1], args[2], 1) != 0)
	{
		perror("setenv");
		return (0);
	}
	return (1);
}
/**
 * _unsetenv - removes an environment variable
 * @name: Name of variable
 * Return: 0 on success else -1
 */

int _unsetenv(char *name)
{
	char *value;

	if (name == NULL)
		return (0);
	if (_strchr(name, '=') != NULL)
	{
		return (-1);
	}
	value = _getenv(name);
	if (value == NULL)
	{
		return (0);
	}
	if (putenv(name) != 0)
	{
		perror("failed to unset variable");
		return (-1);
	}
	return (0);
}

/**
 * un_setenv - unsets an environment variable
 * @args: argument vectors
 *
 * Return: 1 on success else 0
 *
 */
int un_setenv(char **args)
{
	if (_unsetenv(args[1]) != 0)
	{
		perror("unsetenv Error");
		return (0);
	}
	return (1);
}
