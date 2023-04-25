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
	int check = 0;

	(void)cmd;
	(void)env;

	if (args[1])
	{
		check = atoi_error(args[1]);
		if (check == -1)
			return (1);
	}
	free_args(args);
	return (check);
}
