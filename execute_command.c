#include "shell.h"

/**
 *execute_command - Executes the specified command
 *@command: The command to execute
 */
void execute_command(char *command)
{
	if (access(command, X_OK) == 0)
	{
		char **args = malloc(2* sizeof(char*));
		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;

		execve(args[0], args, environ);

		/* If execve fails */
		perror("execve");
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		my_printf("%s: command not found\n", command);
	}
}
