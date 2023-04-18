#include "shell.h"

/**
 * 
 * 
 * 
*/

int build_env(char *name, char *value, int overwrite)
{
	char *new = NULL, *exists = NULL;

	exists = _getenv(name);
	if (exists && overwrite == 0)
		return (0);
	new = malloc(_strlen(name) + _strlen(value) + 2);
	if (!new)
		return (-1);
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);

	int ret = putenv(new);
	if (!ret)
		return (-1);

	return (0);
}
