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
		if (!_cmd_ext(bus[0]))
		{
			write(STDOUT_FILENO, "No such file or directory \n", 26);
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
                else
                {
                    wait(&tree);
                }
		}
	}
}
