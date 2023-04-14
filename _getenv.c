#include "shell.h"

/**
 * _getenv - custom implementation of "getenv"
 * @name: the name from which to retrieve the env
 * Return: the env or NULL
*/

char *_getenv(char *name)
{
	int len = _strlen(name);
	char **tmp = environ;

	while (*tmp != NULL)
	{
		if (_strncmp(*tmp, name, len) == 1 && (*tmp)[len] == '=')
		{
			/* return a pointer to the corresponding value string of VAR*/
			/* just as man 3 getenv behaves */
			/* printf("%s\n", (*tmp + len + 1)); */
			return (*tmp + len + 1);
		}
		tmp++;
	}
	return (NULL);
}
