#include "shell.h"

/**
 * atoi_error - behaves like 'atoi' (string to integer)
 * and handle errors
 * @s: the string to integerify
 * Return: the result in int, or -1 if failure
*/

int atoi_error(char *s)
{
	int i;
	int res = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i]; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * 10 + (s[i] - '0');
		else
			return (-1);
	}
	if (res > INT_MAX)
		return (-1);
	return (res);
}
