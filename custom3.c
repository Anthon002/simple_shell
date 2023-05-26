#include "main.h"
/**
 * _sigemptyset - replicates sigemptyset
 * @st: set
 * Return:void
 */
void _sigemptyset(sigset_t *st)
{
	long *ptr = (long *)st;
	int ngs = sizeof(sigset_t) / sizeof(long);
	int i = 0;

	while (i < ngs)
	{
		ptr[i] = 0;
		i++;
	}
}
/**
 * _at - atoi
 * @s: string
 * Return: int
 */
int _at(const char *s)
{
	int rt, sn, i;

	rt = 0;
	sn = 1;
	i = 0;
	while (s[i] == '\t' || s[i] == ' ')
		i++;
	if (s[i] == '-')
	{
		sn = -1;
		i++;
	}
	else if (s[i] == '+')
	{
		i++;
	}
	while (s[i] <= '9' && s[i] >= '0')
	{
		rt = rt * 10 + (s[i] - '0');
		i++;
	};
	return (sn * rt);
}
/**
 * _strcat - strcat
 * @d: destination
 * @s: source
 */
void _strcat(char *d, const char *s)
{
	while (*d)
		d++;
	while (*s)
	{
		*d = *s;
		d++;
		s++;
	}
	*d = '\0';
}

/**
 * int_Str - int to string
 * @n: num
 * @s: str
 */
void int_Str(int n, char *s)
{
	bool ie = false;
	int i = 0, j = 0;
	int len;
	char tp;

	if (n < 0)
	{
		ie = true;
		n = -n;
	}
	do {
		s[i++] = n % 10 + '0';
		n /= 10;
	} while (n != 0);
	if (ie)
		s[i++] = '-';
	len = i;
	while (j < len / 2)
	{
		tp = s[j];
		s[j] = s[len - j - 1];
		s[len - j - 1] = tp;
		j++;
	}
	s[i] = '\0';
}
/**
 * _sprintf - sprintf
 * @s: char
 * @ft: constr char
 * Return: ws
 */
int _sprintf(char *s, const char *ft, ...)
{
	va_list as;
	int ws;

	va_start(as, ft);
	ws = pro_f(s, ft, as);
	va_end(as);

	return (ws);
}


