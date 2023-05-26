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

void hansig1(int sig);
void setup_signal_handlers(void);
void run_shell(void);
void handle_eof(int signum);
void exeCmd(char *cmd);
void executeCmd(char *bus[]);
void exit_func(void);
int _strlen(char *str);
int _strncmp(char *ch1, char *ch2, int n);
/*char *_getenv(char *name);*/
bool _cmd_ext(const char *cmd);
int _strcmp(const char *ch1, char *ch2);
void _sigemptyset(sigset_t *st);
int _at(const char *s);
void exe_cd(const char *str);
void handle_sep(char *cmd);
void parseCmd(char *cmd, char *bus[]);
void exe_env(void);
void handle_comments(char **tokens);
void exeEcho(char *tn);
char *expVar(char *bus);
#define MAX_COMMAND_LENGTH 2048

#endif
