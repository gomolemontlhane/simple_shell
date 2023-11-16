#include "shell.h"

/**
 *find_command_location - Locates the location of a command in the PATH
 *@command: The command to locate
 *
 *Return: A pointer to the command location, or NULL if not found
 */
char *find_command_location(char *command)
{
	char *path = getenv("PATH");

	if (path)
	{
		char *path_copy = strdup(path);
		int command_length = strlen(command);
		char *path_token = strtok(path_copy, ":");
		struct stat buffer;

		while (path_token != NULL)
		{
			int directory_length = strlen(path_token);
			char *file_path = malloc(command_length + directory_length + 2);

			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");

			if (stat(file_path, &buffer) == 0)
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		}

		free(path_copy);

		if (stat(command, &buffer) == 0)
		{
			return (strdup(command));
		}

		return (NULL);
	}

	return (NULL);
}
