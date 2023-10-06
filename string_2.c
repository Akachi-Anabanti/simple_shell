#include "main.h"

/**
 * _tolower - converts a char to lower case
 * @c: The string
 *
 * Return: the converted char
 */
char _tolower(char c)
{
	if (c >= 'A' && c < 'Z')
	{
		return (c + ('a' - 'A'));
	}
	return (c);
}
/**
 * _strncmp - compares n bytes of strings
 * @str1: first string
 * @str2: Second string
 * @n: length of str2
 *
 * Return: 0 on success
 */
int _strncmp(const char *str1, const char *str2, size_t n)
{
	size_t i;

	for (i = 0; i < n; i++)
	{
		if (str1[i] != str2[i])
			return ((int)((unsigned char)str1[i]) -
					(int)((unsigned char)str2[i]));
		if (str1[i] == '\0' || str2[i] == '\0')
			return (0);
	}
	return (0);
}
/**
 * _strspn - returns numbr of bytes in the initial segment
 * of s which consist only of bytes from accept
 * @s: the string to be searched
 * @accept: the string to find
 * Return: number of bytes
 */
unsigned int _strspn(char *s, const char *accept)
{
	unsigned int i, j;

	for (i = 0; s[i]; i++)
	{
		for (j = 0; accept[j]; j++)
		{
			if (s[i] == accept[j])
			{
				break;
			}
		}
		if (!accept[j])
			break;
	}
	return (i);
}
/**
 * _strtok - splits a string into parts based on delimiter
 * @str: The string to be split
 * @delim: array of delimiters
 * Return: tokens
 */
char *_strtok(char *str, const char *delim)
{
	char *token;
	static char *next_token;
	unsigned int start, end;
	unsigned int i = 0;

	if (delim == NULL)
		return (NULL);
	if (str == NULL)
		str = next_token;
	/* Skip leading delimiters*/
	start = _strspn(str, delim);

	if (str[start] == '\0') /*If the rest of the string is all delimiters*/
	{
		next_token = str + start; /*Update the static pointer*/
		return (NULL);
	}
	/*Find the end of the token*/
	end = start + strcspn(str + start, delim);
	if (str[end] == '\0') /*If the rest of the string is the last token*/
	{
		next_token = str + end; /*Update the static pointer*/
		token = _strdup(str + start);
		return (token);
	}
	/*Allocate memory for the token and copy it*/
	token = malloc(sizeof(char) * (end - start + 1));
	if (token == NULL)
		return (NULL);
	for (i = 0; i < (end - start); i++)
		token[i] = str[start + i];
	token[i] = '\0';
	/*Update the static pointer for the next call*/
	next_token = str + end;
	return (token);
}

/**
 * _atoi - converts a string
 * @s: string to be converted
 *
 * Return: the int convreted from the string
 */
int _atoi(char *s)
{
	int i, n, len, digit;
	bool is_negative = false;

	i = 0;
	n = 0;
	len = 0;

	while (s[len] != '\0')
		len++;

	if (s[i] == '-')
	{
		is_negative = true;
		i++;
	}
	while (i < len)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			n = n * 10 + digit;

			if ((!is_negative && n > INT_MAX / 10) ||
					(is_negative && -n < INT_MIN / 10))
				return (is_negative ? INT_MIN : INT_MAX);
			if ((!is_negative && n * 10 > INT_MAX - digit) ||
					(is_negative && -n * 10 < INT_MIN))
				return (is_negative ? INT_MIN : INT_MAX);
		}
		else
			return (0);
		i++;
	}
	return (is_negative ? -n : n);

}
