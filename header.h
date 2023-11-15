#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Include this line to declare environ */
extern char **environ;

/* Function prototypes */
char *readline(void);
char **split_input(char *input);
int execute_command(char **args);
int _strlen(char *str);
char *find_path(void);  /* Update the declaration here */
int is_exit(char *command);
int is_env(char *command);

#endif /* HEADER_H */
