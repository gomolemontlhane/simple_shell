#include "header.h"

/**
 *is_env - Check if the command is "env"
 *@command: The command to check
 *
 *Return: 1 if the command is "env", 0 otherwise
 */
int is_env(char *command)
{
	if (strcmp(command, "env") == 0)
		return (1);

	return (0);
}

/**
 *is_exit - Check if the command is "exit"
 *@command: The command to check
 *
 *Return: 1 if the command is "exit", 0 otherwise
 */
int is_exit(char *command)
{
	if (strcmp(command, "exit") == 0)
		return (1);

	return (0);
}

/**
 *find_path - Find the full path of a command
 *@command: The command to find
 *
 *Return: Full path of the command if found, NULL otherwise
 */
char *find_path(char *command)
{
	char *path;
	char *token;
	char *path_env = getenv("PATH");
	struct stat st;

	if (path_env == NULL)
		return (NULL);

	path = malloc(strlen(path_env) + strlen(command) + 2);
	if (path == NULL)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	strcpy(path, path_env);
	strcat(path, ":");
	strcat(path, command);

	token = strtok(path, ":");
	while (token != NULL)
	{
		if (stat(token, &st) == 0)
		{
			free(path);
			return (token);
		}

		token = strtok(NULL, ":");
	}

	free(path);
	return (NULL);
}

/**
 *execute_command - Execute a command using execve
 *@args: Array of arguments
 *
 *Return: 0 on success, -1 on failure
 */
int execute_command(char **args)
{
	char *command_path;
	pid_t child_pid;
	int status;

	/*Check if command exists in PATH */
	command_path = find_path(args[0]);
	if (command_path == NULL)
	{
		/*Command not found */
		write(STDOUT_FILENO, "Command not found\n", 18);
		return (-1);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		/*Forking error */
		perror("Error");
		return (-1);
	}

	if (child_pid == 0)
	{
		/*Child process */
		if (execve(command_path, args, NULL) == -1)
		{ /*Execution error */
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Parent process */
		wait(&status);
	}

	free(command_path);
	return (0);
}
