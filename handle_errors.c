#include "shell.h"

/**
 * atoi_error - behaves like 'atoi' (string to integer)
 * and handle errors
 * @s: the string to integerify
 * Return: the result in int, or -1 if failure
*/

int atoi_error(char *s)
{
	int i = 0;
	unsigned long int res = 0;

	if (*s == '+')
		s++;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			res *= 10;
			res += (s[i] - '0');
			if (res > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (res);
}
