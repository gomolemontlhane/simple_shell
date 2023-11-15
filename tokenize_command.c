#include "shell.h"

/**
 *tokenize_command - Tokenizes the command string
 *@command: The command string to tokenize
 */
void tokenize_command(char *command)
{
	char *token;
	char *delimiters = " \t\n";	/* Space, tab, and newline as delimiters */

	token = strtok(command, delimiters);

	while (token != NULL)
	{
		my_printf("Token: %s\n", token);
		token = strtok(NULL, delimiters);
	}
}
