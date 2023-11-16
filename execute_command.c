#include "shell.h"

/**
 *execute_command - Executes the specified command
 *@command: The command to execute
 */
void execute_command(char *command)
{
	/*Check if the command is "exit" */
	if (strcmp(command, "exit") == 0)
	{
		free(command); /*Free allocated memory for command */
		exit(EXIT_SUCCESS);
	}

	if (access(command, X_OK) == 0)
	{
		char **args = malloc(2 * sizeof(char *));

		if (args == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;

		execute_child_process(args);
	}
	else
	{
		printf("%s: command not found\n", command);
	}
}

/**
 *execute_child_process - Executes the command in the child process
 *@args: The array of arguments for execve
 */
void execute_child_process(char **args)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		free(args);
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		/*In the child process */
		execve(args[0], args, environ);

		/*If execve fails */
		perror("execve");
		free(args);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*In the parent process */
		wait_for_child_process();
		free(args);
	}
}

/**
 *wait_for_child_process - Waits for the child process to complete
 */
void wait_for_child_process(void)
{
	wait(NULL);
}
