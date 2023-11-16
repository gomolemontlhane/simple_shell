#include "shell.h"
/**
 * main - Entry point for the simple shell program
 *
 * Return: Always 0
 */
int main(void)
{
	char *command;

	/* Loop for interactive mode */
	while (1)
	{
		display_prompt();
		command = read_command();
		tokenize_command(command);
		execute_command(command);

		/* Free allocated memory for command */
		free(command);
	}

	return (0);
}
