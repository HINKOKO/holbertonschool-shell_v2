#include "shell.h"

/**
 * _strncmp - mimic strncmp function
 * compares two strings up to n bytes
 * @s1: string 1
 * @s2: string 2
 * @n: n bytes to compares up to
 * Return: 1 when strings are equal to n bytes, 0 otherwise
*/

int _strncmp(char *s1, char *s2, size_t n)
{
	while (*s1 == *s2 && n != 0)
	{
		s1++;
		s2++;
		n--;
	}
	if (n == 0 && *s2 == 0)
		return (1);
	return (0);
}
