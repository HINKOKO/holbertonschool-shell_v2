#include "shell.h"
#include "math.h"

/**
 *new_exit - function for exiting the program
 *@cmd: comand entered by user
 *@args: array of arguments
 *@env: array of strings of env
 *Return: 133 for success
 */

int new_exit(char *cmd, char **args, char **env)
{
	int valid_arg;

	(void)cmd;
	(void)env;


	if (args[1])
	/* there is an exit argument */
	{
		valid_arg = atoi_error(args[1]);
		if (valid_arg == -1)
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
			exit(2);
		}
		exit(valid_arg);
	}
	return (133);
}
