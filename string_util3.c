#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

/**
 * _strdup - same as strdup
 * @str: the string to duplicate
 * Return: the address of the duplicate
 */

char *_strdup(char *str)
{
	char *s;
	int i = 0;

	if (!str)
		return (NULL);
	s = malloc(_strlen(str) + 1);
	if (!s || sizeof(s) < sizeof(str))
		return (NULL);
	while (str[i])
	{
		s[i] = str[i];
		i++;
	}
	s[i] = '\0';
	return (s);
}

