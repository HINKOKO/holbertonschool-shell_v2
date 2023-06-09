#include "shell.h"

/**
 *pathfinder - look in the path if the command exists
 *@cmd: command entered by user
 *@PATH: path to process and find
 *Return: the command with path
 */

char *pathfinder(char *cmd, char *PATH)
{
	char *p_item = NULL;
	char *fullpath = NULL;

	p_item = strtok(PATH, ":");
	while (p_item)
	{
		fullpath = malloc(sizeof(char) * (_strlen(cmd) + _strlen(p_item)) + 2);
		fullpath = _strcpy(fullpath, p_item);
		fullpath = _strcat(fullpath, "/");
		fullpath = _strcat(fullpath, cmd);
		if (access(fullpath, X_OK) == 0)
			return (fullpath);
		free(fullpath);
		fullpath = NULL;
		p_item = strtok(NULL, ":");
	}
	return (_strdup(cmd));
}
