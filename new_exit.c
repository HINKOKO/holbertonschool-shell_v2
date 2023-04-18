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
	int exit_code = 0;

	(void)cmd;
	(void)env;


	if (args[1])
	/* there is an exit argument */
	{
		exit_code = atoi(args[1]);
		if (exit_code == -1)
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
			exit(2);
		}
	}
	exit(exit_code);
}
