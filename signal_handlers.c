#include "main.h"
/**
 * setup_signal_handlers - handles signal
 * Return: void
 */

void setup_signal_handlers(void)
{
	struct sigaction sa_eof, sa_int;

	sa_int.sa_handler = handle_sigint;
	sigemptyset(&sa_int.sa_mask);
	sa_int.sa_flags = 0;
	sigaction(SIGINT, &sa_int, NULL);
	sa_eof.sa_handler = handle_eof;
	sigemptyset(&sa_eof.sa_mask);
	sa_eof.sa_flags = 0;
	sigaction(SIGTSTP, &sa_eof, NULL);
}
