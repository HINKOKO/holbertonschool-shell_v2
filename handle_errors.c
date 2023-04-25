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

/**
 * _isdigit - check if characters in input are number(s)
 * @num: the "chars" to check
 * Return: 0 if no digit, 1 if digit
*/

int _isdigit(char *num)
{
	int i = 0;

	if (num == NULL)
		return (0);
	while (num[i])
	{
		if (num[i] < 48 || num[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
