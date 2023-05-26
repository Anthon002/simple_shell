#include "main.h"
/**
 * run_shell - run shell
 * @filename: filename to be opened
 * Return: 0;
 */

void run_shell(char *filename)
{
	char car[MAX_COMMAND_LENGTH];
	ssize_t t_to;

	if (filename != NULL)
	{
		FILE *fe = fopen(filename, "r");

		if (fe == NULL)
		{
			perror("fopen");
			_exit(EXIT_FAILURE);
		}
		while (fgets(car, sizeof(car), fe) != NULL)
		{
			if (car[strlen(car) - 1] == '\n')
				car[strlen(car) - 1] = '\0';

			handle_sep(car);
		}
		fclose(fe);
	}
	else
	{
		while (1)
		{
			t_to = read(STDIN_FILENO, car, sizeof(car));
			if (t_to == -1)
			{
				perror("read");
				_exit(EXIT_FAILURE);
			}
			else if (t_to == 0)
			{
				break;
			}
			if (car[t_to - 1] == '\n')
				car[t_to - 1] = '\0';
			handle_sep(car);
		}
	}
}
