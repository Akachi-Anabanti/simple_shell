#ifndef _MAIN_HEADER_
#define _MAIN_HEADER_

/*BUILTIN HEADERS*/
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>


/*CUSTOM HEADERS*/
#include "envs.h"
#include "string.h"
#include "utils.h"
#include "prints.h"
#include "built-ins.h"
#include "errors.h"

/*GLOBAL VARIABLES*/
extern char **environ;
char *env_variable;
int terminate_prog;
/*PROTOYPES*/
void interactive_mode(void);
void handle_command_line_args(char **av);
void handle_pipe_or_redirection(void);
void sigint_handler(int signum);
void sigterm_handler(int signum);
void execmd(char **args);
char *get_command(char *arg);
void prompt(void);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
ssize_t _getline_helper(char *buffer, size_t bufsize, FILE *stream);

int hasSpecial(char *lineptr);
#endif
