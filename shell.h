#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

extern char **environ;

char **split(char *, char *);

int exec_cmd(char *, char **);

char *cmd_exist(char *);

char *_getenv(const char *);

int has_char(char *, char);

int builtin(char *);

void printenv(void);

int _putchar(char);

void _puts(char *);


#endif /*SHELL_H*/
