#include "main.h"
/**
 * main - simple shell function
 * Return: 0
 */
int main(void)
{
	char buf[1024];
	char *args[2];
	int status;
	ssize_t bytes_read;

	while (1)
	{
		printf("$ ");
		fflush(stdout);
		bytes_read = read(STDIN_FILENO, buf, sizeof(buf));
		if (bytes_read == -1)
		{
			perror("read");
			_exit(EXIT_FAILURE);
		}
		else if (bytes_read == 0)
		{
			break;
		}
		buf[bytes_read - 1] = '\0';
		if (access(buf, X_OK) != 0)
		{
			printf("Error: %s not found.\n", buf);
			continue;
		}
		if (fork() == 0)
		{
			args[0] = buf;
			args[1] = NULL;
			execve(buf, args, environ);
			_exit(EXIT_FAILURE);
		}
		wait(&status);
	}
	return (0);
}

