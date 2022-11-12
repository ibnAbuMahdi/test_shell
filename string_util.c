#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * words - counts the number of words in a string delimited by needle
 * @s: the string
 * @needle: the delimiter
 * Return: the word count
 */

int words(char *s, char *needle)
{
	int wc = 0;
	char *dup = s, *temp;

	if (!s || !needle)
		return (-1);
	while ((temp = strstr(dup, needle)))
	{
		if (strncmp(dup, needle, strlen(needle)) != 0)
			wc++;
		dup = temp + 1;
	}
	if (*dup)
		wc++;
	return (wc);
}

/**
 * split: splits a string into words delimited by delim
 * @str: the string
 * @delim: the delimiter
 * Return: address of the array of words
 */

char **split(char *str, char *delim)
{
	char **temp;
	char *strp, *s = str;
	size_t i = 0;

	if (!str || !delim)
		return (NULL);
	temp = malloc((sizeof(char *)) * (words(str, delim) + 1));

	if (!temp)
		return (NULL);

	while ((strp = strtok(s, delim)))
	{
		temp[i] = strp;
		i++;
		s = NULL;
	}
	temp[i] = NULL;
	return (temp);
}

/**
 *
 */

int has_char(char *s, char c)
{
	while (*s)
		if (*s++ == c)
			return (1);
	return (0);
}
