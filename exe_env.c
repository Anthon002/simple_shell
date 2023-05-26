#include "main.h"
#include "environ.h"
/**
 * exe_env - current env printer
 * Return: void
 */
void exe_env(void)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
