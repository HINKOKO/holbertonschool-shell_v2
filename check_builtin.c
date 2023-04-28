#include "shell.h"

/**
 *check_builtin - function for checking
 *if a builtin exist
 *@command: command entered by user
 *Return: NULL if no builtin, or the right function if builtin is found
 */

int (*check_builtin(char *command))(char *cmd, char **args, char **env)
{
	int i;
	built_in k[] = {
		{"exit", new_exit},
		{"env", print_env},
		{"cd", change_dir},
		{"setenv", my_setenv},
		{"unsetenv", _unsetenv},
		{"help", help_user},
		{NULL, NULL},
	};

	for (i = 0; k[i].command != NULL; i++)
	{
		if (_strcmp(command, k[i].command) == 0)
			return (k[i].f);
	}
	return (NULL);
}
