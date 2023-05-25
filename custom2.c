#include "main.h"
/**
 * _strlen - string length
 * @str: string
 * Return: ln
 */
int _strlen(char *str)
{
	int ln = 0;

	while (str[ln])
	{
		ln++;
	}
	return (ln);
}

/**
 * _strcmp - same as strcmp
 * @ch1: first character
 * @ch2: second character
 * Return: result
 */
int _strcmp(const char *ch1, char *ch2)
{
	int r;

	do {
		r = *ch1 - *ch2;
		ch1++;
		ch2++;
	} while (*ch1 != '\0' && *ch1 != '\0' && r == 0);
	return (r);
}
