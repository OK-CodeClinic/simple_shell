#ifndef SHELL_BASIC_H
#define SHELL_BASIC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>

/* File protoypes */
void shell_loop(char *args[]);
char *shell_read_line(void);
char **shell_split_line(char *line);
int shell_launch(char *args[], int flag);
int shell_execute(char *args[]);
void _free_double_pointer(char **d_pointer);

/* Functions for Built_in commands */
int shell_cd(char *args[]);
int shell_help(char *args[]);
int shell_exit(char *args[]);
int shell_env(char **environ);
int shell_num_builtins(void);

/* Environment variables and Functions */
char *_getenv(const char *name);
extern char **environ;

/* Functions for Strings */
int _strlen(char *string);
int _strcmp(char *s1, char *s2);
int _strncmp(char *s1, char *s2, int n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *str_concat(char *s1, char *s2);
int _putchar(char c);
void _puts(char *str);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

#endif
