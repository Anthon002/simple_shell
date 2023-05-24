#include "main.h"
/**
 * _cmd_ext - checks if command exits
 * @cmd: cmd
 * Return: true or false
 */

bool _cmd_ext(const char *cmd)
{
	char *ph, *ph_cp, *d, pth_bfr[1024];

	ph = getenv("PATH");
	ph_cp = strdup(ph);
	d = strtok(ph_cp, ":");

	if (access(cmd, X_OK) == 0)
	{
		free(ph_cp);
		return (true);
	}

	if (ph == NULL)
	{
		free(ph_cp);
		return (false);
	}

	if (ph_cp == NULL)
		return (false);

	do {
		snprintf(pth_bfr, sizeof(pth_bfr), "%s/%s", d, cmd);

		if (access(pth_bfr, X_OK) == 0)
		{
			free(ph_cp);
			return (true);
		}

		d = strtok(NULL, ":");
	}

	while (d != NULL);
	free(ph_cp);

	return (false);
}
