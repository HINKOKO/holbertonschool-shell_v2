#include "shell.h"

/**
 * build_env - set a new env variable
 * @name: name of env variable to set || check
 * @value: value to assing to name
 * @overwrite: flag to ON / off overwriting
 * Return: 0 success -1 otherwise
*/
int build_env(char *name, char *value, int overwrite)
{
	size_t i = 0;

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], name) && overwrite)
		{
			overwrite_after("=", (char *)value, environ[i]);
			return (0);
		}
		else if (_strcmp(environ[i], name) && !overwrite)
			return (0);
		i++;
	}
	environ = realloc_environ(environ, sizeof(char *) * (i + 1));
	if (environ == NULL)
		return (-1);
	environ[i] = write_variable(name, value, environ[i]);
	if (environ[i] == NULL)
		return (-1);
	return (0);
}
