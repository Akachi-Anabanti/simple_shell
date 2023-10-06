#include "main.h"

/**
 * get_command - returns the command if command is file of from path;
 * @arg: The command;
 * Return: pointer to th command;
 */
char *get_command(char *arg)
{
	int filefound;
	char *isFile, *cmd, *gc;
	struct stat buffer;

	isFile = _strchr(arg, '/');
	filefound = stat(arg, &buffer);

	if (isFile && filefound == 0)
	{
		cmd = malloc(sizeof(char) * (_strlen(arg) + 1));
		_strcpy(cmd, arg);
	}
	else if (isFile && filefound != 0)
	{
		_perror_file(arg, NULL);
		return (NULL);
	}
	else
	{
		 gc = getcmd(arg);
		if (gc == NULL)
		{
			command_not_found(arg);
			return (NULL);
		}
		cmd = malloc(sizeof(char) * (_strlen(gc) + 1));
		_strcpy(cmd, gc);
		free(gc);
	}

	return (cmd);
}
/**
 * execmd - executes commmand
 *
 * @args: command arguments
 */
void execmd(char **args)
{
	int status; /*flag to indicate if getcmd was used*/
	pid_t pid;

	char *my_command = get_command(args[0]);

	if (my_command == NULL)
	{
		free(my_command);
		return;
	}

	pid = fork();
	if (pid == -1)
	{
		perror("fork error");
		free(my_command);
		return;
	}
	else if (pid == 0)
	{
		if (execve(my_command, args, NULL) == -1)
		{
			perror("couldn't execute command\n");
			free(my_command);
			return;
		}
	}
	else
		waitpid(pid, &status, 0);
	free(my_command);
}
