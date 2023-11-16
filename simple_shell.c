#include "shell.h"

/**
 *main - Entry point for the simple shell program
 *@argc: The number of command-line arguments
 *@argv: An array of strings containing the command-line arguments
 *
 *Return: Always 0
 */
int main(int argc, char **argv)
{
	char *command;

	if (argc > 1) /*Check if command-line arguments are provided */
	{
		command = read_command_from_file(argv[1]); /*Read command from file */
		execute_command(command); /*Execute the command */
		free(command); /*Free the allocated memory for the command */
	}
	else
	{
		/*Interactive mode */
		while (1)
		{
			display_prompt(); /*Display the prompt */
			command = read_command(); /*Read user input */

			if (!command)
				break; /*Exit the loop if Ctrl+D is pressed */

			tokenize_command(command); /*Tokenize the command */
			execute_command(command); /*Execute the command */
			free(command); /*Free the allocated memory for the command */
		}
	}

	return 0;
}
