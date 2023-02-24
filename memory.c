#include "shell.h"

/**
 * bfree -frees a pointer and NULLS the address
 * @ptr: pointer address
 * Return: 1 if freed
 */

int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
