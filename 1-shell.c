#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>

char **split(char *, char *);

/**
 * main - super simple shell exercise
 * Return: Always 0.
 */

int main(void)
{
	size_t n;
	int stat = 0;
	pid_t child;
	char **argv, *line;
	extern char **environ;

	while (1)
	{
		child = fork();

		if (child == 0)
		{
			printf("#cisfun$ ");
			if (getline(&line, &n, stdin) == -1)
				return (9);
			argv = split(line, "\n");
			if (execve(argv[0], &argv[0], environ) == -1)
			{
				perror("Error:");
			}
		}
		else
		{
			wait(&stat);
			if (WEXITSTATUS(stat) == 9)
			{
				exit(1);
			}
		}
	}
	return (0);
}
