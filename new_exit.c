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

	if (args[1] != NULL)
	{
		if (_isdigit(args[1]))
		{
			if (args[1])
			{
				check = atoi_error(args[1]);
				if (check > 255)
					check = check % 256;
				if (check == -1)
					return (1);
				if (check < 0)
				{
					fprintf(stderr, "./hsh: 1: exit: Illegal number: %d\n", check);
					check = 2;
				}
			}
		}
		else
		{
			fprintf(stderr, "./hsh: 1: exit: Illegal number: %s\n", args[1]);
			check = 2;
		}
	}
	free_args(args);
	return (check);
}
