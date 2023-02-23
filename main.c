#include "shell.h"

#define MAX_LINE 1024

/**
 * main - starts program
 * @argc: argument count
 * @argv: arguments
 * Return: returns an integer
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, handle_signals);
	signal(SIGTSTP, handle_signals);

	do {
		printf("> ");
		line = read_line();
		args = split_line(line);
		status = execute(args);

		free(line);
		free(args);
	} while (status);

	return (0);
}
