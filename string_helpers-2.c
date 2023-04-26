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

/**
 * _strstr - mimic strstr function
 * @haystack: the STring to look into
 * @needle: the sub_string to find
 * Return: NULL if no found, pointer to first char of sub_string found
*/

char *_strstr(char *haystack, char *needle)
{
	unsigned int i, j;
	unsigned int needle_len = _strlen(needle);

	if (!haystack || !needle)
		return (NULL);

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while ((needle[j] == haystack[i + j]) && (needle[j] && haystack[i + j]))
			j++;
		if (needle_len == j)
			return (&haystack[i]);
		i++;
	}
	return (NULL);
}

/**
 * _puts - prints a string stdout
 * @str: pointer to string to be printed
*/

void _puts(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
}

/**
 * _putchar - writes character to stdout
 * @c: character to print
 * Return: 1 for success, -1 otherwise
*/

int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
