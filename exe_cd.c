#include "main.h"
/**
 * gd - get directory
 * @arg: argument
 * Return: dy
 */
char *gd(const char *arg)
{
	char *dy = NULL;

	if (arg == NULL || _strcmp(arg, "-") == 0)
	{
		dy = _getenv("OLDPWD");
		if (dy == NULL)
		{
			write(STDOUT_FILENO, "cd: OLDPWD not set\n", 19);
			return (NULL);
		}
	}
	else
	{
		dy = (char *)arg;
	}

	return (dy);
}

/**
 * exe_cd - execute command
 * @str: string
 * Return:void
 */
void exe_cd(const char *str)
{
	char *dy = gd(str);
	char *ny;

	if (dy == NULL)
	{
		return;
	}
	if (chdir(dy) != 0)
	{
		perror("chdir");
		return;
	}
	ny = getcwd(NULL, 0);
	if (ny == NULL)
	{
		perror("getcwd");
		return;
	}
	if (setenv("PWD", ny, 1) != 0)
	{
		perror("setenv");
		free(ny);
		return;
	}
	free(ny);
}
