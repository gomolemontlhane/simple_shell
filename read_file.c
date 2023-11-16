#include "shell.h"

/**
 *read_command_from_file - Reads a command from a file
 *@filename: The name of the file to read the command from
 *
 *Return: A string containing the command read from the file
 *        or NULL if there is an error or end of file is reached
 */
char *read_command_from_file(const char *filename)
{
	FILE *file;
	char *command = NULL;
	size_t bufsize = 0;
	size_t len;

	file = fopen(filename, "r");
	if (!file)
	{
		perror("Error opening file");
		return (NULL);
	}

	/*Read the command from the file */
	if (getline(&command, &bufsize, file) == -1)
	{
		perror("Error reading from file");
		free(command);
		fclose(file);
		return (NULL);
	}

	fclose(file);

	/*Remove the newline character at the end, if present */
	len = strlen(command);
	if (len > 0 && command[len - 1] == '\n')
		command[len - 1] = '\0';

	return (command);
}
