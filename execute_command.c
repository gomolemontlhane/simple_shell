#include "shell.h"

/**
 *execute_command - Execute the specified command with arguments.
 *@command: The command to execute.
 *@args: The arguments for the command.
 */
void execute_command(char *command, char **args)
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
		execute_child_process(command, args);
	}
	else
	{
		/*Parent process */
		waitpid(pid, &status, 0);
	}
}

/**
 *execute_child_process - Execute the command in the child process.
 *@command: The command to execute.
 *@args: The arguments for the command.
 */
void execute_child_process(char *command, char **args)
{
	if (access(command, X_OK) == 0)
	{
		execute_command_in_current_directory(command, args);
	}
	else
	{
		search_command_in_path(command, args);
	}
}

/**
 *execute_command_in_current_directory - Execute command in the current
 *directory.
 *@command: The command to execute.
 *@args: The arguments for the command.
 */
void execute_command_in_current_directory(char *command, char **args)
{
	if (execvp(command, args) == -1)
	{
		perror("execvp");
		exit(EXIT_FAILURE);
	}
}

