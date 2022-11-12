#include "shell.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * builtin - check if cmd is a built-in
 * @cmd_b: the command
 * Return: >0 if builtin else 0
 */

int builtin(char *cmd_b)
{
	char *cmds_b[] = {"env", "exit", NULL};
	size_t i = 0, index = 0;

	while (cmds_b[i])
	{
		if (strcmp(cmds_b[i], cmd_b) == 0)
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
	}

	return (index);
}
