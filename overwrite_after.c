#include "shell.h"

/**
 * overwrite_after - copy str into dest
 * after the delim character
 * @delim: the delimiter character to write after to
 * @str: pointer old string
 * @dest: pointer to new string
 * Return: size of new string
*/

size_t overwrite_after(char *delim, char *str, char *dest)
{
	int size = 0, i = 0;

	while (dest[size] != *delim)
		size++;
	size++;
	while (dest[size] != '\0')
	{
		dest[size] = str[i];
		size++;
		if (str[i] != '\0')
			i++;
	}
	return (size);
}
