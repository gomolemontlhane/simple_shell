#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Function prototypes */
char *readline(void);
char **split_input(char *input);
int execute_command(char **args);
int _strlen(char *str);
char *find_path(char *command);
int is_exit(char *command);
int is_env(char *command);

#endif /* HEADER_H */
