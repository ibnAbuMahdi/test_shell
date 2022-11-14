#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>

extern char **environ;

char **split(char *, char *);

int exec_cmd(char *, char **);

char *cmd_exist(char *);

char *_getenv(char *);

int has_char(char *, char);

int builtin(char *);

void printenv(void);

int _putenv(char *, char *, size_t);

int _putchar(char);

void _puts(char *);

char *_strstr(char *, char *);

int _strcmp(char *, char *);

int _strncmp(char *, char *, size_t);

char *_strcat(char *, char *);

char *_strdup(char *);

int _strtok(char *, char *);

size_t _strlen(char *);

char *_strncpy(char *, char *, int);

int _setenv(char *, char *);

int _unsetenv(char *);

size_t count(char **);

char *rem_space(char *);

void process_cmds(char *);

size_t cmd_index(char *);


#endif /*SHELL_H*/
