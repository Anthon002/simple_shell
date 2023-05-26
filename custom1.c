#include "main.h"
#include "environ.h"
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
/**
 * cp_str - copy to string
 * @s: string
 * @sx: int
 * @src: source
 * Return: int
 */
int cp_str(char *s, int *sx, const char *src)
{
	int i = 0;

	while (*src != '\0')
	{
		s[(*sx)++] = *src++;
		i++;
	}
	return (i);
}
/**
 * pro_f - process format
 * @s: char
 * @ft: const char
 * @as: va_list
 * Return: int
 */
int pro_f(char *s, const char *ft, va_list as)
{
	int ws = 0, fx = 0, sx = 0;

	while (ft[fx] != '\0')
	{
		if (ft[fx] == '%')
		{
			fx++;
			switch (ft[fx])
			{
				case 'd':
					{
						int n = va_arg(as, int);
						char nr[20];

						int_Str(n, nr);
						ws += cp_str(s, &sx, nr);
						break;
					}
				default:
					s[sx++] = ft[fx];
					ws++;
					break;
			}
		}
		else
		{
			s[sx++] = ft[fx];
			ws++;
		}
		fx++;
	}
	s[sx] = '\0';
	return (ws);
}
/**
 * exeCmdPath - cmd path dir
 * @cmd: cmd
 * @sts:sts
 * Return: void
 */
void exeCmdPath(char **cmd, int *sts)
{
	char *pv = getenv("PATH");
	char *pen, *ch;

	pv = strdup(pv);
	pen = strtok(pv, ":");
	while (pen != NULL)
	{
		ch = malloc((_strlen(pen) + _strlen(cmd[0]) + 2) * sizeof(char));
		if (ch == NULL)
		{
			perror("malloc");
			exit(1);
		}
		strcpy(ch, pen);
		strcat(ch, "/");
		strcat(ch, cmd[0]);
		if (execve(ch, cmd, environ) == -1)
			free(ch);
		else
			exit(WEXITSTATUS(*sts));
		pen = strtok(NULL, ":");
	}
	free(pv);
	perror(cmd[0]);
	exit(127);
}
