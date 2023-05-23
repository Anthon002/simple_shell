#include "main.h"
/**
 * hansig1 - handles sigin
 * @sig: int
 * Return: void
 */
void hansig1(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
	fflush(stdout);
}

