#include "main.h"
/**
 * _passing_arguments - checks for arguments
 * @strline: string
 * @args: array to store the args
 * Return: no of arguments
 */
int _passing_arguments(char *strline, char **args)
{
	char *dlm, *tokn;
	int argumentc = 0;

	dlm = " \t\n";

	while ((tokn = strtok(strline, dlm)) != NULL)
	{
		args[argumentc++] = tokn;
		strline = NULL;
	};
	args[argumentc] = NULL;

	return (argumentc);
}
