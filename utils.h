#ifndef _UTILS_H
#define _UTILS_H

#include <string.h>
int contains_only_spaces(const char *str);
char *getcmd(char *cmd);
int calc_num_tokens(char *str);
char **parse_line(char *line);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
#endif
