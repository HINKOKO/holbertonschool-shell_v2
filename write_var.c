#include "shell.h"

/**
 * write_variable - write new name/var couple to dest
 * @name: name of variable
 * @val: its value
 * @dest: pointer to array of strings env where to write
 * Return: pointer to new var, NULL otherwise
*/

char *write_variable(const char *name, const char *val, char *dest)
{
	size_t i = 0, s_name, s_value, y = 0;

	s_name = _strlen(name);
	s_value = _strlen(val);
	s_name += s_value + 2;
	dest = malloc(sizeof(char) * s_name);
	if (dest == NULL)
		return ('\0');
	while (name[i] != '\0')
	{
		dest[i] = name[i];
		i++;
	}
	dest[i] = '=';
	s_value = 0;
	while (dest[i])
	{
		i++;
		dest[i] = val[y];
		if (val[y] != '\0')
			y++;
	}
	dest[i] = '\0';
	return (dest);
}
