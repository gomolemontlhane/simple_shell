#include "shell.h"

/**
 *search_command_in_path - Search for command in the PATH directories.
 *@command: The command to search for.
 *@args: The arguments for the command.
 */
void search_command_in_path(char *command, char **args)
{
	char *path = getenv("PATH");
	char *token;

	token = strtok(path, ":");
	while (token != NULL)
	{
		char *full_path = build_full_path(token, command);

		if (access(full_path, X_OK) == 0)
		{
			execute_command_with_full_path(full_path, args);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: command not found\n", command);
	exit(EXIT_FAILURE);
}

/**
 *build_full_path - Build the full path of the command.
 *@directory: The directory containing the command.
 *@command: The command to execute.
 *Return: The full path of the command.
 */
char *build_full_path(char *directory, char *command)
{
	char *full_path = malloc(strlen(directory) + strlen(command) + 2);

	sprintf(full_path, "%s/%s", directory, command);
	return (full_path);
}

/**
 *execute_command_with_full_path - Execute the command with the full path.
 *@full_path: The full path of the command.
 *@args: The arguments for the command.
 */
void execute_command_with_full_path(char *full_path, char **args)
{
	if (execv(full_path, args) == -1)
	{
		perror("execv");
		exit(EXIT_FAILURE);
	}
}

