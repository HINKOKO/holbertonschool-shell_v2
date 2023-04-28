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

/**
 * my_setenv - handle the built-in setenv
 * @cmd: unused
 * @args: args passed to built-in
 * @env: Unused
 * Return: 0 success: -1 otherwise
*/

int my_setenv(char *cmd, char **args, char **env)
{
	size_t i = 0;
	int num = 0;
	(void)cmd;
	(void)env;

	while (args[num] != NULL)
		num++;
	if (num != 3)
	{
		fprintf(stderr, "Wrong usage of builtin\n");
		return (-1);
	}

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], args[1]))
		{
			overwrite_after("=", (char *)args[2], environ[i]);
			return (0);
		}
		else if (!(_strcmp(environ[i], args[1])))
			return (0);
		i++;
	}
	environ = realloc_environ(environ, sizeof(char *) * (i + 1));
	if (!environ)
		return (-1);
	environ[i] = write_variable(args[1], args[2], environ[i]);
	if (environ[i] == NULL)
		return (-1);
	return (0);
}

/**
 * _unsetenv - removes an env variable
 * @cmd: unused, there to match proto of built-in
 * @args: used to check the name inputed
 * @env: unused, there to match proto of built-in
 * Return: 0 on success
*/

int _unsetenv(char *cmd, char **args, char **env)
{
	int i = 0, j = 0, k = 0;
	(void)cmd;
	(void)env;

	if (!args || *args == NULL)
		return (-1);

	while (env[i] && args[1])
	{
		while (args[1][k])
		{
			if (!env[i])
				return (-1);
			if (env[i][j] == args[1][k])
				j++, k++;
			else
				j = 0, k = 0, i++;
		}

		if (env[i][j] == '=')
		{
			env[i] = NULL;
			break;
		}
		j = 0;
		k = 0;
		i++;
	}
	if (!env[i])
		return (0);
	return (-1);
}
