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
			chdir_ret = chdir((dir = _getenv("PWD=")) ? dir : "/");
		chdir_ret = chdir(dir);
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		dir = _getenv("OLDPWD");
		if (!dir)
		{
			fprintf(stderr, "OLDPWD not set\n");
			return (-1);
		}
		chdir_ret = chdir(dir);
	}
	else
		chdir_ret = chdir(args[1]);
	if (chdir_ret == -1)
	{
		fprintf(stderr, "./hsh: 1: cd: can't cd to %s\n", args[1]);
		return (-1);
	}
	return (0);
}
