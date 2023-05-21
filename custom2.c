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
