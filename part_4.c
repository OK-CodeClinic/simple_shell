#include "shell.h"

/**
 * handle_ctrl_l - handles CTRL L
 * @args: arguments
 * Returns: void
 */

void handle_ctrl_l(void)
{
	system("clear");
}

/**
 * handle_ctrl_d - handles CTRL D
 * @args: arguments
 * Return: void
 */

void handle_ctrl_d(void)
{
	fprintf(stderr, "\n");
	exit(EXIT_SUCCESS);
}

/**
 * run_batch_mode - run batch
 * @filname: accepts file name
 * Return: an integer
 */

int run_batch_mode(char *filename)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int ret = 0;
	char **args;
	
	args = malloc(sizeof(char*) * 2);
	args[0] = line;
	args[1] = NULL;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		perror("Error opening file");
		return (-1);
	}
	while ((read = getline(&line, &len, fp)) != -1)
	{
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}
		ret = execute(args);

		if (ret == EXIT_FAILURE)
			break;
	}
	free(line);
	fclose(fp);

	return (ret);
}

/**
 * launch - launch a program
 * @args: arguments
 * Return: returns an int
 */

int launch(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("hsh");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
		perror("hsh");
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return(1);
}
