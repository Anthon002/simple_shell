#include "main.h"
/**
 * main - Simple_shell project
 * @argc: argc
 * @argv: argv
 * Return: 0;
 */

int main(int argc, char *argv[])
{
	setup_signal_handlers();
/*	run_shell();*/
	if (argc == 2)
	{
		run_shell(argv[1]);
	}
	else
	{
		run_shell(NULL);
	};
	return (0);
}
