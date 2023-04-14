#include "shell.h"

/**
 * 
 * 
 * 
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
