#include "main.h"
/**
 * psExitSts - process exit status
 * @sts: int
 */
void psExitSts(int sts)
{
	char er[10];
	int eh = sprintf(er, "%d", sts);

	write(STDOUT_FILENO, "Exit status: ", 13);
	write(STDOUT_FILENO, er, eh);
	write(STDOUT_FILENO, "\n", 1);
}
