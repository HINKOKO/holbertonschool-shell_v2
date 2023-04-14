#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

#define IN 1
#define OUT 0

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

extern char **environ;

typedef struct built_in
{
	char *command;
	int (*f)(char *cmd, char **args, char **env);
} built_in;

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

/* Program Running commands */

int executor(char *buff, char **env, int line);
void _prompt(void);
int exec_path(char **args, char **env, int line);
char *pathfinder(char *cmd, char *PATH);

/* Builtin helpers functions */

int (*check_builtin(char *command))(char *cmd, char **args, char **env);
int new_exit(char *cmd, char **args, char **env);
int change_dir(char *cmd, char **args, char **env);


/* Strings functions */

char **get_args(char *buff);
size_t wordcount(char *s);
void free_args(char **args);


/* Env functions */

int print_env(char *cmd, char **args, char **env);
void handle_signal(__attribute__((unused)) int signum);

/* string utilities */
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);

/* About environment */
char *_getenv(const char *name);


#endif
