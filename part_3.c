#include "shell.h"

/**
 * handle_alias - handles alias
 * @args: arguments
 * Return: returns void
 */

void handle_alias(char **args)
{
	alias alias_list[MAX_ALIASES] = {0};
	int alias_count = 0;
	int i;

	if (args[1] == NULL)
	{
		for (i = 0; i < alias_count; i++)
		{
			printf("%s='%s'\n", alias_list[i].name, alias_list[i].value);
		}
	}
	else
	{
		char *name, *value;
		int index = -1;
		for (i = 0; i < alias_count; i++)
		{
			if (strcmp(alias_list[i].name, args[1]) == 0)
			{
				index = i;
				break;
			}
		}
		if (index == -1)
		{
			if (alias_count == MAX_ALIASES)
			{
				fprintf(stderr, "Too many aliases defined\n");
				return;
			}
			name = strdup(args[1]);
			value = strdup(args[2]);
			alias_list[alias_count].name = name;
			alias_list[alias_count].value = value;
			alias_count++;
		}
		else
		{
			value = strdup(args[2]);
			free(alias_list[index].value);
			alias_list[index].value = value;
		}
	}
}

/**
 * handle_history - handles history
 * @args: arguments
 * Return: returns void
 */

void handle_history(void)
{
	char *history[MAX_HISTORY];
	int history_count = 0;
	int i;

	for (i = 0; i < history_count; i++)
		printf("%d %s\n", i, history[i]);
}

/**
 * handle_help - handles help
 * args: arguments
 * Return: returns void
 */

void handle_help(void)
{
	printf("Simple Shell - A basic Unix command line interpreter\n");
	printf("Usage: simple_shell [filename]\n");
	printf("Commands:\n");
	printf(" cd [DIRECTORY]\tChange the current directory\n");
	printf(" setenv VARIABLE VALUE\tInitialize or modify an environment variable\n");
	printf(" unsetenv VARIABLE\tRemove an environment variable\n");
	printf(" alias [name[='value'] ...]\tDefine or print aliases\n");
	printf(" history\t\tPrint a list of command previously entered\n");
	printf(" help\t\tDisplay this help message\n");
}
