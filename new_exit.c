#include "shell.h"

/**
 *new_exit - function for exiting the program
 *@cmd: comand entered by user
 *@args: array of arguments
 *@env: array of strings of env
 *Return: 133 for success
 */

int new_exit(char *cmd, char **args, char **env)
{
	int stat = 0;

	(void)cmd;
	(void)env;

	if (args[1])
	{
		stat = atoi_error(args[1]);
		if (stat == -1)
		{
			return (134);
		}
		free_args(args);
	}
	free(args);
	exit(stat);
}
