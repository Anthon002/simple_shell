#include "main.h"
/**
 * run_shell - run shell
 * Return: 0;
 */

void run_shell(void)
{
	char car[493];
	ssize_t t_to;

	while (1)
	{
		write(STDOUT_FILENO, "$Cisfun$ ", 9);
		fflush(stdout);
		t_to = read(STDIN_FILENO, car, sizeof(car));
		if (t_to == -1)
		{
			perror("read");
			_exit(EXIT_FAILURE);
		}
		else if (t_to == 0)
		{
			write(STDOUT_FILENO, "\n", 1);
			break;
		}
		if (car[t_to - 1] == '\n')
			car[t_to - 1] = '\0';
		execute_command(car);
	}
}