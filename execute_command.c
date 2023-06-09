#include "main.h"
#include "environ.h"
/**
 * parseCmd - parsing command
 * @cmd: command
 * @bus: charcter
 */
void parseCmd(char *cmd, char *bus[])
{
	int i = 0;
	char *tok = strtok(cmd, " \t\n");

	while (tok != NULL && i < 63)
	{
		bus[i] = tok;
		tok = strtok(NULL, " \t\n");
		i++;
	}
	bus[i] = NULL;
}
/**
 * executeCmd - execute command
 * @bus: array
 * Return:void
 */
void executeCmd(char *bus[])
{
	pid_t pid = fork();
	int tree;

	if (pid == -1)
	{
		perror("fork");
		_exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (_strchr(bus[0], '/') != NULL)
		{
			if (execve(bus[0], bus, environ) == -1)
			{
				perror(bus[0]);
				exit(127);
			}
		}
		else
		{
			exeCmdPath(bus, &tree);
		}
	}
	else
	{
		wait(&tree);
		if (WIFEXITED(tree) && WEXITSTATUS(tree) != 0)
		{
			psExitSts(tree);
		}
	}
}
/**
 * fill - fills up bus
 * @bus: array
 */
void fill(char *bus[])
{
	int i = 0;

	while (i < 64)
	{
		bus[i] = NULL;
		i++;
	}
}
/**
 * exeCmd - main
 * @cmd: command
 * Return: void
 */
void exeCmd(char *cmd)
{
	char *bus[64];

	fill(bus);
	parseCmd(cmd, bus);
	if (bus[0] != NULL)
	{
		if (_strcmp(bus[0], "exit") == 0)
		{
			exit_func();
		}
		else if (_strcmp(bus[0], "cd") == 0)
		{
			exe_cd(bus[1]);
		}
		else if (_strcmp(bus[0], "env") == 0)
		{
			exe_env();
		}
		else if (!_cmd_ext(bus[0]))
		{
			write(STDOUT_FILENO, bus[0], _strlen(bus[0]));
			write(STDOUT_FILENO, ": ", 2);
			write(STDOUT_FILENO, "not found\n", 10);
		}
		else if (_strcmp(bus[0], "setenv") == 0)
		{
			exeSet(bus[1], bus[2]);
		}
		else if (_strcmp(bus[0], "unsetenv") == 0)
		{
			exeUnset(bus[1]);
		}
		else
		{
			executeCmd(bus);
		}
	}
}
