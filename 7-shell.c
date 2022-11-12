#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "shell.h"
#include <sys/stat.h>
/**
 * main - driver code
 * Return: Always 0.
 */

int main(void)
{
	size_t n;
	char **argv, *line;
	char *path;
	struct stat st;

	while (1)
	{
		write(1, "$ ", 2);

		if (getline(&line, &n, stdin) == -1)
			exit(1);

		argv = split(line, "\n");
		if (builtin(argv[0]))
			continue;

		if (has_char(argv[0], '/'))
		{
			if (!stat(argv[0], &st))
				exec_cmd(argv[0], &argv[0]);
			else
				write(2, "Error: Not a valid command\n", 27);
		}
		else
		{
			path = cmd_exist(argv[0]);
			if (path)
				exec_cmd(path, &argv[0]);
			else
				write(2, "Error: Not a valid command\n", 27);
		}
	}
	return (0);
}

/**
 * exec_cmd - executes the command cmd with args
 * @cmd: basically args[0]
 * @args: the args
 * Return: 1 on success and 0 o.w.
 */

int exec_cmd(char *cmd, char **args)
{
	pid_t child = fork();

	if (child == -1)
	{
		perror("\nFailed to fork child ...");
		return (0);
	}
	else if (child == 0)
	{
		if (execve(cmd, args, environ) == -1)
		{
			perror("(execve) Error");
			return (0);
		}
	}
	else
	{
		wait(NULL);
		free(cmd);
		return(1);
	}
	return (0);
}

/**
 * cmd_exist - checks the PATH to determine if cmd exist
 * @cmd: the command
 * Return: a complete path cmd if cmd exist and null o.w.
 */

char *cmd_exist(char *cmd)
{
	char *value = _getenv("PATH");
	struct stat st;
	int pos;
	int i;
	char *temp;

	if (value)
	{
		while (1)
		{
			pos = _strtok(value, ":");
			
			temp = malloc(pos + 1);
			_strncpy(temp, value, pos + 1);
			_strcat(temp, "/");
			_strcat(temp, cmd);
			i = stat(temp, &st);
			if (i == 0)
			{
				return (temp);
			}
			value += pos + 1;
			if (!(pos = _strtok(value, ":")))
			{
				free(temp);
				break;
			}
			free(temp);
		}
	}

	return (NULL);
}
