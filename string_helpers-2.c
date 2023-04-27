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
 * _strstr - locates a substring in a string
 * @hays: the haystack to find in the needle
 * @need: the needle `string` to find
 * Return: NULL if no match, pointer to begin of substring otherwise
*/

char *_strstr(char *hays, char *need)
{
	unsigned int i, j;
	unsigned int len_need = _strlen(need);

	if (!hays || !need)
		return (NULL);

	i = 0;
	while (hays[i])
	{
		j = 0;
		while ((need[j] == hays[i + j]) && (need[j] && hays[i + j]))
			j++;
		if (len_need == j)
			/* len matches the iteration of j */
			return (&hays[i]);
		i++;
	}
	return (NULL);
}

/**
 * _puts - prints a string stdout
 * @str: pointer to string to be printed
 * Return: number of chars written
*/

int _puts(char *str)
{
	size_t i = _strlen(str);

	write(1, str, i);
	return (i);
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
