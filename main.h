#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>

extern char **environ;
volatile sig_atomic_t h_hs;
void hansig1(int sig);
void setup_signal_handlers();
void run_shell();
void handle_eof(int signum);
void exeCmd(char *command);
void exit_func();
int _strlen(char* str);
int _strncmp(char* ch1, char* ch2, int n);
char* _getenv(char* name);
bool _cmd_ext(const char *cmd);
int _strcmp(char *ch1, char *ch2);
void _sigemptyset(sigset_t *st);
void exe_cd(const char *str);
void handle_sep(char *cmd);
#define MAX_COMMAND_LENGTH 2048

#endif
