#include "shell.h"

/**
 * realloc_environ - custom reallocation
 * @env: array of strings of env var
 * @new_size: new size after reallocation
 * Return: pointer to new_env, NULL failure
*/

char **realloc_environ(char **env, size_t new_size)
{
	char **new_env;

	new_env = malloc_double(new_size);
	if (new_env == NULL)
		return ('\0');
	new_env = copy_double(env, new_env);
	return (new_env);
}


