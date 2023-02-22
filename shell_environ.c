#include "shell.h"

/**
 * _getenv - get the string of a enironment variable
 * @name: The name of the variable to find
 * Return: return the string founded
 */

char *_getenv(const char *name)
{
	int i = 0, j = 0, k = 0;
	int len = _strlen((char *)name);
	char **env = environ;

	char *str = malloc(sizeof(char) * 150);
	if (!str)
		return (NULL);
	if (!name)
	{
		free(str);
		return (NULL);
	}
	while (env[i][j] != '\0')
	{
		if (_strncmp(env[i], (char *)name, len) != 0)
			i++;
		else
		{
			if (env[i][len] == '=')
			{
				while (env[i][len + j] != '\0')
				{
					str[k] = (env[i][len + j + 1]);
					k++;
					j++;
				}
				return ((char *)str);
			}
		}
	}
	free(str);
	return (NULL);
}
