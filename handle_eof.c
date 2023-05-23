#include "main.h"
/**
 * handle_eof - handles Ctrl + D
 * @sig: value
 * Return: void
 */
void handle_eof(int sig)
{
	(void)sig;
	h_hs = 1;
}
