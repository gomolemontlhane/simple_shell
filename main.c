#include "shell.h"

/**
 *main - Simple shell main function
 *Return: Always 0
 */
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	char *args[MAX_ARGS];
	int i;

	while (1)
	{
		printf("($) ");
		getline(&line, &len, stdin);

		/*Tokenize the input line */
		args[0] = strtok(line, " \n");
		if (args[0] == NULL)
		{
			continue;
		}

		for (i = 1; i < MAX_ARGS; i++)
		{
			args[i] = strtok(NULL, " \n");
			if (args[i] == NULL)
			{
				break;
			}
		}

		/*Check for the "exit" command */
		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}

		/*Execute the command */
		execute_command(args[0], args);
	}

	free(line);
	return (0);
}

