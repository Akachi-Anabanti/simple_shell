#include "main.h"

/**
 * _exec - tests and execute both builtin function and execve functions
 * @line: pointer to line
 * Return: 1 always
 */
int _exec(char *line)
{
	char **cmd_args;
	int j;

	if (contains_only_spaces(line) == 0)
		return (0);
	cmd_args = parse_line(line); /*parse the command*/
	if (isBuiltin(cmd_args[0]) == 0)
	{
		if (_strcmp(cmd_args[0], "exit") == 0)
			free(line);
		exec_builtin(cmd_args); /*execute builtin*/
	}
	else
	{
		execmd(cmd_args); /*execute the command*/
	}
	for (j = 0; cmd_args[j] != NULL; j++)
		free(cmd_args[j]);
	free(cmd_args);

	return (1);
}
/**
 * interactive_mode - The interactive mode handler
 */
void interactive_mode(void)
{
	char *line = NULL;
	size_t n = 0;
	ssize_t nchars;

	signal(SIGINT, sigint_handler);
	signal(SIGTERM, sigterm_handler);
	while (!terminate_prog)
	{
		prompt();
		nchars = _getline(&line, &n, stdin);
		if (nchars == -1)
		{
			_putchar('\n');
			break;
		}
		if (nchars > 0 && line[nchars - 1] == '\n')
		{
			line[nchars - 1] = '\0';
		}
		_exec(line);
		/*Remember to free line*/
		free(line);
	}
}

/**
 * handle_command_line_args - commandline mode handler
 * @av: argument vector
 */
void handle_command_line_args(char **av)
{
	ssize_t nchars;
	size_t n = 0;
	char *line = NULL, path[1024];
	FILE *stream;

	if (getcwd(path, sizeof(path)) == NULL)
		return;
	_strcat(path, "/");
	_strcat(path, av[0]);
	if (access(path, R_OK) == 0 && !_strchr(av[0], '/'))
	{
		stream = fopen(av[0], "r");
		if (stream == NULL)
		{
			perror("fopen");
			exit(EXIT_FAILURE);
		}
		while ((nchars = _getline(&line, &n, stream)) != -1)
		{
			if (nchars > 0 && line[nchars - 1] == '\n')
			{
				line[nchars - 1] = '\0';
			}
			_exec(line);
			free(line);
		}
		fclose(stream);
		exit(EXIT_SUCCESS);
	}
	else
		execmd(av);
	/*Handle File as input*/
}

/**
 * handle_pipe_or_redirection - PIPE and Redirection mode
 *
 */
void handle_pipe_or_redirection(void)
{
	struct stat stdin_stat;
	size_t n = 0;
	char *line = NULL;
	ssize_t nchars;

	if (fstat(STDIN_FILENO, &stdin_stat) == -1)
	{
		perror("Failed to get standard input file status");
		return;
	}
	if (S_ISREG(stdin_stat.st_mode) || S_ISFIFO(stdin_stat.st_mode))
	{
		while ((nchars = _getline(&line, &n, stdin)) != -1)
		{
			if (nchars > 0 && line[nchars - 1] == '\n')
			{
				line[nchars - 1] = '\0';
			}
			_exec(line);
			free(line);
		}
		return;
	}
	else
	{
		perror("Unknown source");

	}
}


/**
 * main - entry point
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 always
 */
int main(int ac, char **av)
{
	if (ac > 1)
	{
		av++; /*increment av to skip the executable as arg*/
		handle_command_line_args(av);
	}
	else if (isatty(STDIN_FILENO))
	{
		interactive_mode();
	}
	else
	{
		handle_pipe_or_redirection();
	}
	return (0);
}
