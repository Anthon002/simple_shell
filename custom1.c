#include "main.h"
/**
 * _strncmp - custom strncmp function
 * @ch1: arg 1
 * @ch2: arg 2
 * @n: arg3
 * Return: int
 */

int _strncmp(char *ch1, char *ch2, int n)
{
	int i = 0;

	do {
		if (!ch1[i] || !ch2[i] || ch1[i] != ch2[i])
			break;
		++i;
	}

	while (i < n - 1);
	return ((int)(ch1[i] - ch2[i]));
}
