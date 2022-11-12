#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * _getenv - gets environment variable with named name
 * @name: name of the variable
 * Return: the pointer to the value of the variable
 */

char *_getenv(const char *name)
{
	extern char **environ;
	size_t i = 0;
	int n = 0;

	while (environ[i])
	{
		char *key = strtok(environ[i], "=");
		char *value = strtok(NULL, "=");

		n = strcmp(key, name);
		if (n == 0)
		{
			return (value);
		}
		i++;
	}
	return (NULL);
}
