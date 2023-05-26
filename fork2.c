#include <stdio.h>
#include <unistd.h>


int main(void){

        pid_t pid;


        pid = fork();

        if (pid == -1){
                perror("Unsuccessful\n");
        }

        if (pid == 0){
                sleep(5);
                printf("I am the child\n");
        }
        else
                printf("I am the Parent\n");

        return 0;
}
