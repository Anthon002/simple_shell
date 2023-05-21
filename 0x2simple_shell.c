#include <stdio.h>
#include "main.h"

int main(int argc, char *argv[]){

	//char *argv[] = {
	pid_t pid;
	pid = fork();

	if (pid == -1){
		printf("Error running fork\n");
		return 1;
	}

	int exec;

	if (argc > 1) {

	if (pid == 0){
		exec = execve(argv[1], argv, NULL);
	}

	} else {
		printf("You cannot enter only one argument\n");
	}


		if (exec == -1){
			perror("Error running Execve system call\n");
			return 2;
		}

	

	else{
		wait(NULL);
		//printf("Done with Execve function\n");
	}

	return 0;

}

	


