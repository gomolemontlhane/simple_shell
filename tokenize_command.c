#include "shell.h"

/**
 *tokenize_command - Tokenizes the command string
 *@command: The command string to tokenize
 */
void tokenize_command(char *command)
{
	char *token = strtok(command, " \n");

	while (token != NULL)
	{
		my_printf("%s\n", token);
		token = strtok(NULL, " \n");
	}
}
