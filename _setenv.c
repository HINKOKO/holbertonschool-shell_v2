#include "shell.h"

/**
 * build_env - set a new env variable
 * using strstr find a needle in haystack !
 * @name: name of env variable to set || check
 * @value: value to assing to name
 * Return: 0 success -1 otherwise
*/

void build_env(char *name, char *value)
{
	int i = 0;
	unsigned int j;
	int k;

	while (environ[i] != NULL)
	{
		if (_strstr(environ[i], name))
		{
			j = 0;
			k = 0;
			while (name[j])
			{
				if (environ[i][j] == name[j])
					k++;
				j++;
			}
			if (k == _strlen(name))
			{
				_strcpy(_strstr(environ[i], name) + _strlen(name) + 1, value);
				break;
			}
		}
		i++;
	}
}
