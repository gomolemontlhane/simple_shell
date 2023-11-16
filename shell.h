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
void execute_child_process(char *command, char **args);
void wait_for_child_process(pid_t pid, int *status);
char *read_command(void);
void display_prompt(void);
void tokenize_command(char *command);
char *read_command_from_file(const char *filename);
void handle_child_process_exit(char *command, int status);

#endif /* SHELL_H */
