#include "shell.h"

/**
 * main - display prompt and manage input
 * @ac: argument count
 * @av: one-dim array argument
 * @env: environnement is important
 * Return: 0 success
 */

int main(int ac __attribute__((unused)), char **av, char **env)
{
	char *buff = NULL;
	ssize_t nread = 0;
	size_t read = 0;
	int ret = 0, line = 1;

	(void)av;

	while (1)
	{
		_prompt();
		signal(SIGINT, handle_signal);
		buff = NULL;
		nread = getline(&buff, &read, stdin);
		if (nread == -1)
		{
			if (buff)
				free(buff);
			if (isatty(STDIN_FILENO))
				exit(EXIT_FAILURE);
			else
				exit(EXIT_SUCCESS);
		}
		else
		{
			ret = executor(buff, env, line);
			free(buff);
			if (ret == 133)
				exit(EXIT_SUCCESS);
			else if (ret == 127)
				exit(ERR_FND);
			else if (ret != 0)
			{
				exit(ret);
			}
			line++;
		}
	}
	return (0);
}
