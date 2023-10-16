#include "main.h"

/**
 * *_strcpy - copies a string from src to dest
 * @src: the source
 * @dest: the dest
 * Return: character
 */
char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];

		i++;
	}

	dest[i] = '\0';

	return (dest);
}

/**
 * *_strcat -  concatenates two strings
 * @dest: destination string
 * @src: source string [string to be added]
 * Return: Pointer to dest
 */
char *_strcat(char *dest, const char *src)
{
	int len_dest; /* length of the destination string*/
	int i = 0; /* LCV for src characters */

	if (dest == NULL || src == NULL)
		return (NULL);

	len_dest = _strlen(dest);

	while (src[i] != '\0')
	{
		/**
		 * overite the last value of dest
		 * increment its length by i and assign
		 * it the value of ith character
		 */
		dest[len_dest + i] = src[i];

		i++;
	}
	dest[len_dest + i] = '\0';

	return (dest);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: a positive value if S1 is greater than S2,
 * a negative value if s2 is greater than s1
 * and 0 if both strings are equal
 */
int _strcmp(const char *s1, const char *s2)
{

	while (*s1 != '\0' && *s2 != '\0')
	{

		if (*s1 != *s2)
		{
			if (*s1 > *s2)
			{

				return (1);
			}
			return (-1);
		}
		s1++;
		s2++;
	}
	if (*s1 == '\0' && *s2 == '\0')
		return (0);
	else if (*s1 == '\0')
		return (-1);
	else
		return (1);
}

/**
 * _strdup - returns a pointer to a newly allocated
 * space in memory which contains a copy of the string
 * given as parameter
 * @str:The given string
 * Return: A pointer to memory or NULL
 */
char *_strdup(const char *str)
{
	char *ptr;

	int len;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);

	ptr = malloc(sizeof(char) * (len + 1));

	if (ptr == NULL)
		return (NULL);

	for (; len >= 0; len--)
		ptr[len] = str[len];

	return (ptr);
}

/**
 * *_strchr - finds the first occurence of c in s
 * @s: string to search
 * @c: character to find
 * Return: pointer to c
 */
char *_strchr(char *s, char c)
{
	if  (*s == '\0' && *s != c)
		return ('\0');
	else if (*s == c)
		return (s);
	return (_strchr(s + 1, c));
}
