#ifndef SHELL_H
#define SHELL_H

char **split(char *, char *);

int exec_cmd(char *, char **);

char *cmd_exist(char *);

char *_getenv(const char *);

int has_char(char *, char);


#endif /*SHELL_H*/
