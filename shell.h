#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pwd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define MAX_ALIASES 100
#define MAX_HISTORY 100

/**
 * typedef struct alias - has values
 * @name: char
 * @value: char
 */

typedef struct {
	char *name;
	char *value;
} alias;

char *read_line(void);
char **split_line(char *line);
int execute(char **args);
void handle_signals(int signal);
void handle_cd(char **args);
void handle_setenv(char **args);
void handle_unsetenv(char **args);
void handle_alias(char **args);
void handle_history(void);
void handle_help(void);
void hande_ctrl_l(void);
void handle_ctrl_d(void);
int run_batch_mode(char *filename);
int launch(char **args);

#endif
