#include "main.h"
/**
 * exit_func - exit functionality
 * @sts: sts
 * Return: void
 */
void exit_func(char *sts)
{
	int es;

	if (sts != NULL)
	{
		switch (*sts)
		{
			case '0':
				es = 0;
				break;
			case '1':
				es = 1;
				break;
			case '2':
				es = 2;
				break;
			default:
				es = _at(sts);
				break;
		}
	}
	exit(es);
}
