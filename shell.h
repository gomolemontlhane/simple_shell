#ifndef SHELL_H
#define SHELL_H

#define MAX_ARGS 10

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

/* Function prototypes */
void prompt(void);
void execute_command(char *command, char **args);

#endif /* SHELL_H */

