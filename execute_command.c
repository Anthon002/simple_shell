#include "main.h"
/**
 * execute_command - execute_command
 * @command: char command
 * Return: void;
 */
void execute_command(char *command)
{
	char *tok, *bus[64];
	int tree, i;
	pid_t pid;

	for (i = 0; i < 64; i++)
	{
		bus[i] = NULL;
	}
	i = 0;
	tok = strtok(command, " \t\n");
	while (tok != NULL && i < 63)
	{
		bus[i] = tok;
		tok = strtok(NULL, " \t\n");
		i++;
	}
	if (bus[0] != NULL)
	{
		if (access(bus[0], X_OK) != 0)
		{
			write(STDOUT_FILENO, "No such file or directory\n", 26);
		}
		else
		{
			pid = fork();
			if (pid == -1)
			{
				perror("fork");
				_exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				execve(bus[0], bus, NULL);
				_exit(EXIT_FAILURE);
			}
			else
			{
				wait(&tree);
			}
		}
	}
}
