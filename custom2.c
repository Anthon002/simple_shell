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
/**
 * _strchr - custom strchr
 * @s: str
 * @c: int
 * Return: NULL
 */
char *_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
/**
 * _hfs - handle format specifiers
 * @s: char
 * @ft: char
 * @as: valist
 * @ws: int
 * @sx: int
 * @i: int
 * Return: int
 */
void _hfs(char *s, const char *ft, va_list *as, int *ws, int *sx, int *i)
{
	int lh;

	switch (ft[*i])
	{
		case 'd':
			{
				int n = va_arg(*as, int);
				char nr[20];

				int_Str(n, nr);
				lh = _strlen(nr);
				while (*i < lh)
				{
					s[*sx++] = nr[*i];
					(*i)++;
				}
				*ws += lh;
				break;
			}
		default:
			s[*sx++] = ft[*i];
			(*ws)++;
			break;
	}
	(*i)++;
}
