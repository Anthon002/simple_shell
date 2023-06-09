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
#include <stdarg.h>

void hansig1(int sig);
void setup_signal_handlers(void);
void run_shell(char *filename);
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
char *expVar(char *bus);
char *_strchr(const char *sr, int c);
void _strcat(char *d, const char *s);
int _sprintf(char *s, const char *ft, ...);
void _hfs(char *s, const char *ft, va_list *as, int *ws, int *sx, int *i);
void int_Str(int n, char *s);
int cp_str(char *s, int *sx, const char *src);
int pro_f(char *s, const char *ft, va_list as);
void exeSet(const char *var, const char *val);
void exeUnset(const char *var);
void exeCmdPath(char **cmd, int *sts);
void psExitSts(int sts);
#define MAX_COMMAND_LENGTH 2048

#endif
