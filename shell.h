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
void execute_child_process(char *command, char **args);
void execute_command_in_current_directory(char *command, char **args);
void search_command_in_path(char *command, char **args);
char *build_full_path(char *directory, char *command);
void execute_command_with_full_path(char *full_path, char **args);

#endif /* SHELL_H */

