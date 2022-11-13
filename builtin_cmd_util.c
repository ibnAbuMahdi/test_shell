#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * builtin - check if cmd is a built-in
 * @cmd_b: the command
 * Return: >0 if builtin else 0
 */

int builtin(char **cmd_b)
{
	char *cmds_b[] = {"env", "exit", "setenv", "unsetenv", NULL};
	size_t i = 0, index = 0;
	
	cmd_b = split(cmd_b[0], " ");
	while (cmds_b[i])
	{
		if (_strcmp(cmds_b[i], cmd_b[0]) == 0)
		{
			index = i + 1;
			break;
		}
		i++;
	}
	switch (index)
	{
		case (1):
			printenv();
			break;
		case (2):
			printf("yes exit\n");
			break;
		case (3):
		{
			if (count(cmd_b) != 3)
			{
				write(2, "Usage: setenv VARIABLE VALUE\n", 29);
				break;
			}
			_setenv(cmd_b[1], cmd_b[2]);
			break;
		}
		case (4):
		{
			if (count(cmd_b) != 2)
			{
				write(2, "Usage: unsetenv VARIABLE\n", 25);
				break;
			}
			_unsetenv(cmd_b[1]);
			break;
		}
	}
	return (index);
}

/**
 *
 */

size_t count(char **array)
{
	size_t i = 0;
	
	if (!array)
		return (0);
	while (array[i])
		i++;
	return (i);
}
