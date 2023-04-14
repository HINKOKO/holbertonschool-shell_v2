#include "shell.h"

/**
 * 
 * 
*/

char *_getenv(const char *name)
{
	int len = _strlen(name);
	char **tmp = environ;

	while (*tmp != NULL)
	{
		if (_strncmp(*tmp, name, len) == 0 && (*tmp)[len] == '=')
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
