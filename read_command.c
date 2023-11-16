#include "shell.h"

/**
 *read_command - Reads a command from the user
 *
 *Return: The entered command
 */
char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;

	getline(&command, &len, stdin);
	return (command);
}
