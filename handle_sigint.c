#include "main.h"
/**
 * handle_sigint - handles sigin
 * @signum: int
 * Return: void
 */
void handle_sigint(int signum)
{
	(void)signum;
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}

