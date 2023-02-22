#include "shell.h"

int token_len(char *str, char *delim);
int count_tokens(char *str, char *delim);
char **strtok(char *line, char *delim);

/**
 * token_len - locates the delimiter index marking the end
 * of the first token contained within a string
 * @str: The string to be searched
 * @delim: The delimiter character
 *
 * Return: The delimiter index marking the end of the initial token pointed to be str
 */

int token_len(char *str, char *delim)
{
	int index = 0, len = 0;

	while (*(str + index) && *(str + index) != *delim)
	{
		len++;
		index++;
	}
	return (len);
}

/**
 * count_tokens - Counts the number of delimited word contained within a string.
 * @str: The string to be searched
 * @delim: The delimiter character
 *
 * Return: The number of words contained within str.
 */

int count_tokens(char *str, char *delim)
{
	int index, token = 0, len = 0;

	for (index = 0; *(str + index); index++)
		len++;

	for (index = 0; index < len; index++)
		len++;

	for (index = 0; index < len; index++)
	{
		if (*(str + index) != *delim)
		{
			token++;
			index += token_len(str + index, delim);
		}
	}

	return (token);
}

/**
 * _strtok - Tokenizes a string
 * @line: The string
 * @delim: The delimter character to tokenize the string by.
 *
 * Return: A pointer to an array containing the tokenized words
 */

char **_strtok(char *line, char *delim)
{
	char **ptr;
	int index = 0, token, t, letters, l;

	token = count_tokens(line, delim);
	if (token == 0)
		return (NULL);

	ptr = malloc(sizeof(char *) * (token + 2));

	if (!ptr)
		return (NULL);

	for (t = 0; t < token; t++)
	{
		while (line[index] == *delim)
			index++;
		letters = token_len(line + index, delim);
		ptr[t] = malloc(sizeof(char) * (letters + 1));
		if (!ptr[t])
		{
			for (index -= 1; index >= 0; index--)
				free(ptr[index]);
			free(ptr);
			return (NULL);
		}
		for (l = 0; l < letters; l++)
		{
			ptr[t][l] = line[index];
			index++;
		}
		ptr[t][l] = '\0';
	}
	ptr[t] = NULL;
	ptr[t + 1] = NULL;

	return (ptr);
}
