#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_COMMAND_LENGTH 100

int main() {
        char command[MAX_COMMAND_LENGTH];

         while (1) {
                 printf("OgShell$ ");
                 fgets(command, MAX_COMMAND_LENGTH, stdin);


        // Remove trailing newline character

        command[strcspn(command, "\n")] = '\0';



        //Exit the shell if the user types "exit"

        if (strcmp(command, "exit") == 0) {
                break;
        }


        //Execute the command using system()

        system(command);
	 }

	 return 0;

}
