#include "main.h"
/**
 * expVar - expand variables
 * @bus: token
 * Return: char
 */
char *expVar(char *bus)
{
	char *en = NULL;
	char *pe = "$$";
	char *vs = strstr(bus, pe);
	size_t th, vh, eh;
	pid_t pd;

	if (vs != NULL)
	{
		th = _strlen(bus);
		vh = _strlen(pe);
		eh = th - vh + sizeof(pid_t);
		en = malloc(eh);
		if (en != NULL)
		{
			strncpy(en, bus, vs - bus);
			en[vs - bus] = '\0';
			pd = getpid();
			_sprintf(en + (vs - bus), "%d", pd);
			_strcat(en, vs + vh);
		}
	}
	return (en);
}
/**
 * exeEcho - execute echo
 * @tn: token
 */
void exeEcho(char *tn)
{
	char *en = expVar(tn);

	if (en != NULL)
	{
		pid_t pid = fork();

		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			execlp("echo", "echo", en, NULL);
			perror("execlp");
			exit(EXIT_FAILURE);
		}
		else
		{
			int ss;

			waitpid(pid, &ss, 0);
		}
	}
}
