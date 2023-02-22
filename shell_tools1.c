#include "shell.h"

/**
 * _strlen - this functions prints the length of a string
 * @s: string to print
 * Return: returns the length in int
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strdup - this functions copy a string
 * @str: the string to copy
 * Return: returns void
 */

char *_strdup(char *str)
{
	char *p;
	int i, s;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
		i++;
	p = malloc(i * sizeof(*str) + 1);
	if (p == NULL)
		return (NULL);
	for (s = 0; s < i; s++)
		*(p + s) = *(str + s);
	*(p + s) = '\0';
	return (p);
}

/**
 * _strncmp - this functions compare two strings
 * @s1: the first string
 * @s2: the second string
 * @n: number to compare
 * Return: returns a number depending on the result from comparation
 */

int _strncmp(char *s1, char *s2, int n)
{
	int i;

	if (s1 == NULL || s2 == NULL)
		return (-1);
	for (i = 0;(s1[i] != '\0' || s2[i] != '\0') && i < n; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}
	return (0);
}

/**
 * _strcmp - comapares two strings
 * @s1: get a char
 * @s2: get a char
 * Return: return a integer
 */

int _strcmp(char *s1, char *s2)
{
	while (((*s1 != '\0') && (*s2 != '\0')) && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 - *s2);
}
