#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "shell.h"

/**
 * _getenv - gets environment variable with named name
 * @name: name of the variable
 * Return: the pointer to the value of the variable
 */

char *_getenv(char *name)
{
	size_t i = 0;
	int n = 0, pos;
	char *temp, *value;
	
	while (environ[i])
	{
		pos = _strtok(environ[i], "=");
		temp = malloc(pos + 1);
		if (!temp)
			return (NULL);
		_strncpy(temp, environ[i], pos);

		n = _strcmp(temp, name);
		if (n == 0)
		{
			size_t len = _strlen(environ[i] + pos + 1);

			value = malloc(len + 1);
			if (!value)
				return (NULL);
			_strncpy(value, environ[i] + pos + 1, len);
			return (value);
		}
		i++;
	}
	return (NULL);
}

/**
 *
 */

void printenv(void)
{
	size_t i = 0;

	while (environ[i])
	{
		_puts(environ[i]);
		_puts("\n");
		i++;
	}
	
}

/**
 *
 */

int _setenv(char *name, char *value)
{
	size_t i = 0;
	int n = 0, pos;
	char *temp;

	if (!name)
		return (0);
	while (environ[i])
	{
		pos = _strtok(environ[i], "=");
		temp = malloc(pos + 1);
		if (!temp)
			return (0);
		_strncpy(temp, environ[i], pos);
		n = _strcmp(temp, name);
		if (n == 0)
		{
			_strcat(temp, "=");
			_strcat(temp, value);
			environ[i] = temp;
			return (1);
		}
		i++;
	}
	if (_putenv(name, value, i))
		return (1);
	return (0);
}

/**
 *
 */

int _putenv(char *name, char *value, size_t env_size)
{
	char *new;

	if (!environ)
		return (0);
	new = _strdup(name);

	if (new)
	{
		_strcat(new, "=");
		_strcat(new, value);
		environ[env_size] = new;
		environ[++env_size] = NULL;
		return (1);
	}
	return (0);
}

/**
 *
 */

int _unsetenv(char *name)
{
	size_t i = 0, found = 0;
	int n = 0;
	char *temp;
	int pos;

	while (environ[i])
	{
		pos = _strtok(environ[i], "=");

		temp = malloc(pos + 1);
		if (!temp)
			return (0);
		_strncpy(temp, environ[i], pos);
		n = _strcmp(temp, name);

		if (n == 0)
		{
			found = 1;
			environ[i] = environ[i + 1];
		}
		else if (found)
		{
			environ[i] = environ[i + 1];
		}
		i++;
	}
	return (1);	
}

/*
int main(void)
{
if (ac == 2)
	{
		if (_unsetenv(av[1]))
			printf("unsetenv success\n");
	}
	else if (ac == 3)
	{
		if (_setenv(av[1], av[2]))
			printf("setenv success\n");
	}
	
	return (0);

	printf("%s\n", _getenv("PATH"));
	return (0);
}
*/


