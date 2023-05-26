#include "main.h"
#include "environ.h"
/**
 * exeSet - set env
 * @var: variable
 * @val: value
 * Return: void
 */
void exeSet(const char *var, const char *val)
{
	if (var == NULL || val == NULL)
	{
		write(STDERR_FILENO, "setenv: missing arguments\n", 26);
		return;
	}
	if (setenv(var, val, 1) != 0)
	{
		perror("setenv");
		return;
	}
}
/**
 * exeUnset - unsetenv
 * @var: variable
 * Return: void
 */
void exeUnset(const char *var)
{
	if (var == NULL)
	{
		write(STDERR_FILENO, "unset: missing argument\n", 27);
		return;
	}
	if (unsetenv(var) != 0)
	{
		perror("unsetenv");
		return;
	}
}
