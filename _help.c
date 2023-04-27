#include "shell.h"

/**
 * help_user - displays general message about help function
 * and trigger to help_command according to command inputed
 * @cmd: unused
 * @args: argument used to detect help and command name
 * @env: unused
 * Return: 0 alaways success
*/

int help_user(char *cmd, char **args, char **env)
{
	(void)cmd;
	(void)env;
	(void)args;

	_puts("help `name` to find out more about the function `name`\n");
	_puts("\tComing soon...\n");
	return (0);
}
