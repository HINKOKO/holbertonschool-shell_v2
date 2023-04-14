#include "shell.h"

/**
 * change_dir - function for trigger builtin 'cd'
 * @cmd: command entered by user
 * @args: array of arguments
 * @env: array of strings of env
 * Return: 0 for success, -1 otherwise
*/

int change_dir(char *cmd, char **args, char **env)
{
	char *curdir, *dir, buffer[1024];
	int chdir_ret;
	(void)cmd;
	(void)env;

	curdir = getcwd(buffer, 1024);
	if (!curdir)
		return (-1);
	if (!args[1])
	{
		dir = _getenv("HOME");
		if (!dir)
			printf("HOME NOT SET\n");
		chdir_ret = chdir(dir);
	}
	else
		chdir_ret = chdir(args[1]);
	if (chdir_ret == -1)
	{
		return (-1);
	}
	return (0);
}
