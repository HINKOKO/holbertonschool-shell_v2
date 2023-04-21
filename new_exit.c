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
	int status = 0;

	(void)cmd;
	(void)env;

	if (args[1])
	{
		status = atoi_error(args[1]);
		exit (status);
	}
	free(args);

	return (133);
}
