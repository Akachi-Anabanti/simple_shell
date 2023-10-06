#ifndef _STRING_HEADERS_
#define _STRING_HEADERS_

#include <stddef.h>
char _tolower(char c);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, const char *src);
int _strcmp(const char *s1, const char *s2);
char *_strdup(const char *str);
char *_strchr(char *s, char c);
char *_strtok(char *str, const char *delim);
unsigned int _strspn(char *s, const char *accept);
int _atoi(char *s);
int _strncmp(const char *str1, const char *str2, size_t n);
#endif
