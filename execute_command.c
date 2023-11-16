#include "shell.h"

/**
 *execute_command - Executes a command in the shell
 *@command: The command to execute
 */
void execute_command(char *command)
{
	pid_t pid;
	int status;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/*Child process */
		char **args = malloc(sizeof(char *) * 2);

		if (!args)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}

		args[0] = command;
		args[1] = NULL;

		execute_child_process(command, args);
	}
	else
	{
		/*Parent process */
		wait_for_child_process(pid, &status);
		handle_child_process_exit(command, status);
	}
}

/**
 *execute_child_process - Executes the command in the child process
 *@command: The command to execute
 *@args: Array of arguments for the command
 */
void execute_child_process(char *command, char **args)
{
	if (execve(command, args, environ) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}

	free(args);
}

/**
 *wait_for_child_process - Waits for the child process to finish
 *@pid: Process ID of the child process
 *@status: Pointer to the status variable
 */
void wait_for_child_process(pid_t pid, int *status)
{
	if (waitpid(pid, status, 0) == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

/**
 *handle_child_process_exit - Handles the exit status of the child process
 *@command: The command that was executed
 *@status: The exit status of the child process
 */
void handle_child_process_exit(char *command, int status)
{
	if (WIFEXITED(status) && WEXITSTATUS(status) == 127)
	{
		fprintf(stderr, "%s: command not found\n", command);
	}
	else if (WIFSIGNALED(status))
	{
		fprintf(stderr, "%s: killed by signal %d\n", command, WTERMSIG(status));
	}
}
