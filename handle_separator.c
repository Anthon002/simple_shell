#include "main.h"
/**
 * handle_sep - handel sparators
 * @cmd: checks for command
 */
void handle_sep(char *cmd)
{
	int i = 0;
	int j = 0;
	char *tok = strtok(cmd, ";");
	char *commands[10];

	while (tok != NULL && i < 10)
	{
		commands[i] = tok;
		tok = strtok(NULL, ";");
		i++;
	}

	while (j < i)
	{
		exeCmd(commands[j]);
		j++;
	};
}
