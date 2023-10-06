#include "main.h"


/**
 * contains_only_spaces - checks if a string has only spaces
 *
 * @str: The string to check
 * Return: 0 if true or 1 if false
 */
int contains_only_spaces(const char *str)
{
	int i = 0;

	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
/**
 * calc_num_tokens - calculates the number of tokens in a string
 * @str: The string
 * Return: number of tokens
 */
int calc_num_tokens(char *str)
{
	int ntokens = 0;
	char *token = _strtok(str, " \n");

	while (token != NULL)
	{
		ntokens++;
		free(token);
		token = _strtok(NULL, " \n");
	}
	return (ntokens);
}
/**
 * parse_line - parses the input
 * @line: The command and args
 *
 * Return: pointer to array of command and args
 */
char **parse_line(char *line)
{
	int ntokens;
	int i = 0, j;
	char **args = NULL;
	char *token;
	char *linecpy = _strdup(line);

	if (linecpy == NULL)
	{
		perror("strdup error\n");
		return (NULL);
	}
	ntokens = calc_num_tokens(linecpy);

	args = malloc(sizeof(char *) * (ntokens + 1));
	if (args == NULL)
	{
		perror("malloc error\n");
		return (NULL);
	}
	token = _strtok(line, " \n");
	while (token != NULL)
	{
		args[i] = malloc(sizeof(char) * (_strlen(token) + 1));
		if (args[i] == NULL)
		{
			perror("malloc error\n");
			for (j = 0; j < i ; j++)
				free(args[j]);
			free(args);
			return (NULL);
		}
		_strcpy(args[i], token);
		_strcat(args[i], '\0');
		i++;
		free(token);
		token = _strtok(NULL, " \n");
	}
	args[i] = NULL;
	free(linecpy);
	return (args);
}

/**
 * getcmd - Finds the file in the current path
 * @cmd: Name of the file
 *
 * Return: full cmd path or NULL
 */
char *getcmd(char *cmd)
{
	char *path_tok, *full_path = NULL;
	char *path = _getenv("PATH");
	int path_len, cmd_len;
	struct stat cmd_stat;
	char *pathcpy = _strdup(path);

	if (path == NULL)
	{
		perror("Error: PATH variable not set");
		return (NULL);
	}
	path_tok = _strtok(pathcpy, ":");
	while (path_tok != NULL)
	{
		path_len = _strlen(path_tok);
		cmd_len = _strlen(cmd);
		full_path = (char *)malloc(path_len + cmd_len + 2);
		if (full_path == NULL)
		{
			perror("Error allocating memory");
			return (NULL);
		}
		_strcpy(full_path, path_tok);
		_strcat(full_path, "/");
		_strcat(full_path, cmd);

		if (stat(full_path, &cmd_stat) == 0)
		{
			free(pathcpy);
			free(path_tok);
			return (full_path);
		}
		free(full_path);
		free(path_tok);
		path_tok = _strtok(NULL, ":");
	}
	free(pathcpy);
	return (NULL);
}


/**
 * _realloc - Increase of decreases the size of a memory bloc
 * @ptr: pointer to memory
 * @old_size: old memory size
 * @new_size: New size to set the memory
 * Return: new memory pointer
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int i, min_size;
	void *new_ptr;

	if (new_size == old_size)
		return (ptr);
	if (ptr == NULL && new_size != 0)
	{
		new_ptr = (char *)malloc(new_size);
		if (!new_ptr)
			return (NULL);
		return (new_ptr);
	}
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	min_size = (old_size < new_size) ? old_size : new_size;
	new_ptr = malloc(new_size);
	for (i = 0; i < min_size; i++)
		((char *)new_ptr)[i] = ((char *)ptr)[i];
	free(ptr);
	return (new_ptr);
}
