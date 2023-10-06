#ifndef _BUILTIN_
#define _BUILTIN_

#define MAX_PATH_LENGTH 4096
/**
 * struct builtinFuncMapper - maps the command to respective function
 *
 * @cmd: The command
 * @function: The associated function
 */
typedef struct builtinFuncMapper
{
	char *cmd;

	int (*function)();
} funcMapper;

int _stop(char **args);
int _changedir(char **args);
int _printenv(char **args);
int isBuiltin(char *arg);
void exec_builtin(char **args);
#endif
