#include "main.h"
/**
 * handle_eof - handles Ctrl + D
 * @signum: value
 * Return: void
 */
void handle_eof(int signum)
{
	(void)signum;
	h_hs = 1;
}
