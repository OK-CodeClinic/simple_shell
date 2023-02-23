#include "shell.h"

/**
 * read_line - reads line
 * Return: returns char
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}

/**
 * split_line - splits line
 * @line: accepts char
 * @Return: char
 */

char **split_line(char *line)
{
	char *token;
	int bufsize = BUF_SIZE;
	int position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));

	if (!tokens)
	{
		fprintf(stderr, "Allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += BUF_SIZE;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "Allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return (tokens);
}


/**
 * execute - executes stuff
 * @args: arguments
 */

int execute(char **args)
{
	pid_t pid;
	int status;
	extern char **environ;

	if (args[0] == NULL)
		return (0);
	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(args[0], args, environ) == -1)
		{
			perror("execve");
			return (-1);
		}
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return (0);
}

/**
 * handle_signals - handle signals
 * @signal: integer
 */

void handle_signals(int signal)
{
	if (signal == SIGINT)
		write(STDOUT_FILENO, "\n$ ", 3);
}
