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
