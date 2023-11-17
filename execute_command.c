#include "shell.h"

/**
 *execute_command - Executes a command.
 *@command: The command to execute.
 *
 *Return: Always returns 0.
 */
int execute_command(char *command)
{
	int status;

	/*Fork a child process */
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}

	if (pid == 0) /*Child process */
	{
		char full_path[256];
		char *cmd_args[2];

		/*Check if the command is "env" */
		if (strcmp(command, "env") == 0)
		{
			extern char **environ;
			char *env_args[] = { "env", NULL
			};

			/*Print the current environment using execve */
			if (execve("/usr/bin/env", env_args, environ) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}

		/*Construct the full path for the command in /bin/ */
		snprintf(full_path, sizeof(full_path), "/bin/%s", command);

		cmd_args[0] = full_path;
		cmd_args[1] = NULL;

		/*Execute the command using execv */
		if (execv(full_path, cmd_args) == -1)
		{
			perror("execv");
			exit(EXIT_FAILURE);
		}

		exit(EXIT_SUCCESS); /*Exit child process */
	}
	else /*Parent process */
	{
		waitpid(pid, &status, 0);
	}

	return (0);
}

