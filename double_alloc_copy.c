#include "shell.h"

/**
 * malloc_double - a double malloc please
 * @size: size to "mallocate"
 * Return: pointer to new space, NULL if failure
*/

char **malloc_double(size_t size)
{
	char **new;
	size_t i = 0;

	new = malloc(sizeof(new) * size);
	if (new == NULL)
		return ('\0');
	while (i < size)
	{
		new[i] = '\0';
		i++;
	}
	return (new);
}

/**
 * copy_double - copy old str to new str
 * @old: old string
 * @new: new string
 * Return: pointer to new string
*/

char **copy_double(char **old, char **new)
{
	int i = 0;

	while (old[i] != NULL)
	{
		new[i] = old[i];
		i++;
	}
	return (new);
}
