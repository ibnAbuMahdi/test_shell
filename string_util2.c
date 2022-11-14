#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/**
 * _strtok - find the first occurrence of ndl in s
 * @s: the string
 * @ndl: the delim
 * Return: the position of ndl in s if it exist or len of s otherwise
 */

int _strtok(char *s, char *ndl)
{
	char *dup = s;
	int dif;
	size_t l;

	if (!s || !ndl)
		return (0);

	l = _strlen(ndl);
	while ((dup = _strstr(s, ndl)))
	{
		if (_strncmp(s, ndl, l) != 0)
		{
			dif = dup - s;
			return (dif);
		}
		s = s + l;
	}
	if (*s)
		return (_strlen(s));
	return (0);
}

/**
 * _strncpy - same as strncpy
 * @dest: destination buffer
 * @src: source buffer
 * @n: number of chars to copy
 * Return: address of the new dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	for (; i < n && src[i]; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = 0;
	return (dest);
}

/**
 * rem_space - removes space at the beginning of s
 * @s: the string
 * Return: address of the first non-space char in s
 */

char *rem_space(char *s)
{
	if (!s)
		return (NULL);
	while (*s)
		if (*s == ' ')
			s++;
		else
			return (s);
	return (s);
}

