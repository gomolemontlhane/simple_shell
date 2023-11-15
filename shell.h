#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

void display_prompt(void);
char *read_command(void);
void tokenize_command(char *command);
void execute_command(char *command);
void my_printf(const char *format, ...);

#endif /* SHELL_H */
