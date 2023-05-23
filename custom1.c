#include "main.h"
/**
 * _getenv - gets the environment
 * @nm: character to check
 * Return: NULL
 */

char *_getenv(char *nm)
{
	int j = 0;
	int n_l = _strlen(nm);

	do {
		if (environ[j] && !_strncmp(environ[j], nm, n_l) && environ[j][n_l] == '=')
		{
			return (&(environ[j][n_l + 1]));
		};
		j++;
	}

	while (environ[j] != NULL);
	return (NULL);
}

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
