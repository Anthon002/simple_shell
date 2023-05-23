#include "main.h"
/**
 * exit_func - exit functionality
 * @sts: sts
 * Return: void
 */
void exit_func(char *sts)
{
	int es;

	if (sts == NULL)
	{
		exit(EXIT_SUCCESS);
	}
	else
	{
		es = _at(sts);
		exit(es);
	}
}
