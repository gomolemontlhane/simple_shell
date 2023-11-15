#include "header.h"

/**
 *main - Entry point for the Simple Shell
 *
 *Return: Always 0
 */
int main(void)
{
	char *input;
	char **args;

	while (1)
	{
		/*Display shell prompt */
		write(STDOUT_FILENO, "$ ", 2);

		/*Read user input */
		input = readline();

		/*Check for end of file (Ctrl+D) */
		if (input == NULL)
		{
			write(STDOUT_FILENO, "\n", 1);
			free(input);
			exit(0);
		}

		/*Remove newline character from input */
		input[_strlen(input) - 1] = '\0';

		/*Check if the command is "exit" */
		if (is_exit(input))
		{
			free(input);
			exit(0);
		}

		/*Check if the command is "env" */
		if (is_env(input))
		{ /*Print the current environment */
			char **env = environ;
			while (*env)
			{
				write(STDOUT_FILENO, *env, _strlen(*env));
				write(STDOUT_FILENO, "\n", 1);
				env++;
			}

			free(input);
			continue;
		}

		/*Split input into arguments */
		args = split_input(input);

		/*Execute the command using execve */
		if (execute_command(args) == -1)
		{ /*Print error message if command execution fails */
			perror("Error");
		}

		/*Free allocated memory */
		free(input);
		free(args);
	}

	return (0);
}
