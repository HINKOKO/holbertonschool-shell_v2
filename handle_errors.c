#include "shell.h"

/**
 * atoi_error - behaves like 'atoi' (string to integer)
 * and handle errors
 * @s: the string to integerify
 * Return: the result in int, or -1 if failure
*/

int atoi_error(char *s)
{
	int i, sign;
	unsigned int number;

	i = number = 0;
	sign = 1;
	for (; (!(s[i] >= 48 && s[i] <= 57)) && s[i] != '\0'; i++)
	{
		if (s[i] == 45)
			sign *= -1;
	}
	if (s[i] == '\0')
		return (number);
	for (; (s[i] >= 48 && s[i] <= 57) && s[i] != '\0'; i++)
		number = (number * 10) + (s[i] - 48);
	return (number * sign);
}
