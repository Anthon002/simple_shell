#include "main.h"
/**
 * exeCmd - execute_command
 * @cmd: char command
 * Return: void;
 */
void exeCmd(char *cmd)
{
	char *tok, *bus[64];
	int tree, i;
	pid_t pid;

	for (i = 0; i < 64; i++)
	{
		bus[i] = NULL;
	}
	i = 0;
	tok = strtok(cmd, " \t\n");
	while (tok != NULL && i < 63)
	{
		bus[i] = tok;
		tok = strtok(NULL, " \t\n");
		i++;
	}
	if (bus[0] != NULL)
	{
		if (_strcmp(bus[0], "exit") == 0)
		{
			exit_func();
		}
		else if (!_cmd_ext(bus[0]))
		{
			write(STDOUT_FILENO, bus[0], _strlen(bus[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, "not found\n", 10);
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
				execvp(bus[0], bus);
				_exit(EXIT_FAILURE);
			}
			else if (pid == 0)
			{
				execlp(bus[0], bus[0], (char *)NULL);
				_exit(EXIT_FAILURE);
			}

			else
			{
				wait(&tree);
			}
		}
	}
}
