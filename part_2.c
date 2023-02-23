#include "shell.h"

/**
 * handle_cd - change directory
 * @args: arguments
 * Returns: void
 */

void handle_cd(char **args)
{
	char *new_dir;
	char *old_dir = NULL;
	int ret_val;

	if (args[1] == NULL)
	{
		new_dir = getenv("HOME");
		if (new_dir == NULL)
		{
			perror("getenv");
			return;
		}
	}
	else if (strcmp(args[1], "-") == 0)
	{
		new_dir = getenv("OLDPWD");
		if (new_dir == NULL)
		{
			perror("getenv");
			return;
		}
		printf("%s\n", new_dir);
	}
	else
		new_dir = args[1];

	old_dir = getcwd(old_dir, 0);
	if (old_dir == NULL)
	{
		perror("getcwd");
		return;
	}

	ret_val = chdir(new_dir);
	if (ret_val != 0)
	{
		perror("chdir");
		free(old_dir);
		return;
	}

	if (setenv("OLDPWD", old_dir, 1) != 0)
	{
		perror("setenv");
		free(old_dir);
		return;
	}

	if (setenv("PWD", new_dir, 1) != 0)
	{
		perror("setenv");
		free(old_dir);
		return;
	}

	free(old_dir);
}

/**
 * handle_setenv - handles it
 * @args: accepts arguments
 * Returns: void
 */

void handle_setenv(char **args)
{
	int ret;

	if (args[1] == NULL || args[2] == NULL)
	{
		fprintf(stderr, "Usage: setenv VARIABLE VALUE\n");
		return;
	}

	ret = setenv(args[1], args[2], 1);

	if (ret != 0)
		fprintf(stderr, "setenv: Error: Unable to unset environmental variable\n");
}

/**
 * handle_unsetenv - unsets it
 * @args: arguments
 * Return: void
 */

void handle_unsetenv(char **args)
{
	int ret;

	if (args[1] == NULL)
	{
		fprintf(stderr, "Usage: unsetenv VARIABLE\n");
		return;
	}

	ret = unsetenv(args[1]);

	if (ret != 0)
		fprintf(stderr, "unsetenv: Error: Unable to unset environment variable\n");
}
