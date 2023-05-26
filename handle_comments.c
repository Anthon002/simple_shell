#include "main.h"
/**
 * exeComments - handles comments
 * @tn: char
 */
void exeComments(char **tn)
{
	char *cs;
	int i = 0;

	if (tn[0] != NULL)
	{
		if (tn[0][0] == '#')
		{
			return;
		}
		while (tn[i] != NULL)
		{
			cs = strchr(tn[i], '#');
			if (cs != NULL)
			{
				*cs = '\0';
				break;
			}
			i++;
		}
	}
}
