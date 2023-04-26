#include "shell.h"

/**
 * _strlen - computes lenght of string
 * @s: pointer to string to measure
 * Return: int len of string
*/

int _strlen(const char *s)
{
	int len = 0;

	if (!*s)
		return (0);
	while (*s++)
		len++;
	return (len);
}

/**
 * _strcmp - mimic the strcmp function
 * @s1: first string
 * @s2: second string
 * Return: 0 if same, -1 is s1 smaller 1 otherwise
*/

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * _strcpy - copies chars from src to dest
 * @dest: pointer to buff dest (copy of src)
 * @src: pointer to buff to cpy from
 * Return: pointer to dest buff
*/

char *_strcpy(char *dest, const char *src)
{
	int i = 0;

	if (dest == src || src == 0)
		return (dest);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

/**
 * _strcat - concatenate two strings
 * @dest: destination buff
 * @src: source buff
 * Return: pointer to dest buffer
*/

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

/**
 * _strdup - duplicates a string
 * @str: the string to dup
 * Return: pointer to duplicated string
*/

char *_strdup(const char *str)
{
	int len = 0;
	char *dst;

	if (!str)
		return (NULL);
	while (*str++)
		len++;
	dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	for (len++; len--;)
		dst[len] = *--str;
	return (dst);
}
