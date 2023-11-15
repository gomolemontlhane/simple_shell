#include "header.h"

/**
 *find_path - Find the full path of a command
 *
 *Return: Full path of the command if found, NULL otherwise
 */
char *find_path(void)
{
	char *path;
	char *token;

	path = getenv("PATH");
	if (path == NULL)
		return (NULL);

	path = strdup(path);
	if (path == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		if (access(token, X_OK) == 0)
		{
			free(path);
			return (token);
		}

		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}
