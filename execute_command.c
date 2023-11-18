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
		if (access(command, X_OK) == 0)
		{ /*If the command is executable in the current directory, execute it */
			if (execvp(command, args) == -1)
			{
				perror("execvp");
				exit(EXIT_FAILURE);
			}
		}
		else
		{ /*Search for the command in the PATH */
			char *path = getenv("PATH");
			char *token;
			char *full_path;

			token = strtok(path, ":");
			while (token != NULL)
			{ /*Check if the command exists in the current PATH directory */
				full_path = malloc(strlen(token) + strlen(command) + 2);
				if (full_path == NULL)
				{
					perror("malloc");
					exit(EXIT_FAILURE);
				}

				sprintf(full_path, "%s/%s", token, command);

				if (access(full_path, X_OK) == 0)
				{/*If found, execute the command */
					if (execv(full_path, args) == -1)
					{
						perror("execv");
						exit(EXIT_FAILURE);
					}
				}

				free(full_path);
				token = strtok(NULL, ":");
			}

			/*If the command is not found in any PATH directory, print an error */
			fprintf(stderr, "%s: command not found\n", command);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/*Parent process */
		waitpid(pid, &status, 0);
	}
}
