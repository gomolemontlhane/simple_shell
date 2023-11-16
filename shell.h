#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

extern char **environ;

/* Function prototypes */
void execute_command(char *command);
void execute_child_process(char **args);
void wait_for_child_process(void);
char *read_command(void);
void display_prompt(void);
void tokenize_command(char *command);
char *read_command_from_file(const char *filename);

#endif /* SHELL_H */
