#ifndef _ENV_HEADER_
#define _ENV_HEADER_

#include <unistd.h>

extern char **environ;

char *_getenv(const char *name);
int _setenv(const char *name, const char *value, int overwrite);
int _unsetenv(char *name);
int set_env(char **args);
int un_setenv(char **args);

#endif
