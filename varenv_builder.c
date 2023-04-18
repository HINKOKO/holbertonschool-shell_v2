#include "shell.h"

/**
 * build_env - mimic the setenv function
 * @name: name of new env to set
 * @value: value of the new env we want to set
 * @overwrite: integer value to allow overwriting or not
 * Return: 0 for success, -1 otherwise
*/

int build_env(char *name, char *value, int overwrite)
{
	/* Check if the variable already exists */
	char *old_value = _getenv(name);

	if (old_value != NULL && !overwrite)
	{
		/* The variable already exists and we're not allowed to overwrite it */
		return (0);
	}

	/* Build a new string of the form "name=value" */
	size_t name_len = _strlen(name);
	size_t value_len = _strlen(value);
	char *new_value = malloc(name_len + value_len + 2);
	/* +2 for the '=' and the terminating null byte */
	if (new_value == NULL)
	{
		return (-1);
	}
	sprintf(new_value, "%s=%s", name, value);

	/* Find the environment variable in the environment list */
	char **envp = environ;

	while (*envp != NULL)
	{
		if (_strncmp(*envp, name, name_len) == 0 && (*envp)[name_len] == '=')
		{
			/* The variable exists and we're allowed to overwrite it */
			/* Replace the old value with the new one */
			_strcpy(*envp, new_value);
			free(new_value);
			return (0);
		}
		envp++;
	}
	/* The variable doesn't exist, so add it to the environment list */
	*envp = new_value;
	*(envp + 1) = NULL;

	return (0);
}
