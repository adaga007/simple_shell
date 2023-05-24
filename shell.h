#ifndef SHELL_H_
#define SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

char **string_tok(char *str, char *del, int *size);
void _execute(char *commands, char *pname, char **env);
char *_getline();
char *_getEnvp(char **envp);
char *_stringdup(char *str);
char *_stringcpy(char *dest, char *src, int n);
size_t _stringlen(char *s);
void _stringcat(char *dest, char *src);
char *_getAbsPath(char *pname, char **envp);
#endif
