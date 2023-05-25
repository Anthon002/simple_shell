#include "main.h"
/**
 * handle_sep - handel sparators
 * @cmd: checks for command
 */
void handle_sep(char *cmd)
{
	int i = 0;
	int j = 0;
	int k = 0;
	char *tok = strtok(cmd, ";");
	char *cmds[10], *toks[64];

	while (tok != NULL && i < 10)
	{
		cmds[i] = tok;
		tok = strtok(NULL, ";");
		i++;
	}

	while (j < i)
	{
		/*
		 * exeCmd(cmds[j]);
		j++;
		*/
		while (k < 64)
		{
			toks[k] = NULL;
			k++;
		}
		parseCmd(cmds[j], toks);
		if (toks[0] != NULL)
		{
			executeCmd(toks);
		}
		j++;
	};
}
