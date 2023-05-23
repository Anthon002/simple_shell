#include "main.h"
/**
 * setup_signal_handlers - handles signal
 * Return: void
 */

void setup_signal_handlers(void)
{
	struct sigaction sf, st;

	st.sa_handler = hansig1;
	_sigemptyset(&st.sa_mask);
	st.sa_flags = 0;
	sf.sa_handler = handle_eof;
	_sigemptyset(&sf.sa_mask);
	sf.sa_flags = 0;
	sigaction(SIGTSTP, &sf, NULL);
}
