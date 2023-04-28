#ifndef __SIMPLE_SHELL__
#define __SIMPLE_SHELL__

#define IN 1
#define OUT 0

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define ERR_FND 127
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

extern char **environ;

/**
 * struct built_in - struct handling the builtins functions
 * @command: command entered
 * @f: pointer function
*/

typedef struct built_in
{
	char *command;
	int (*f)();
} built_in;

/* Libraries */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <limits.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>

/* Program Running commands */
int executor(char *buff, char **env, int line);
void _prompt(void);
int exec_path(char **args, char **env, int line);
char *pathfinder(char *cmd, char *PATH);

/* Builtin helpers functions */
int (*check_builtin(char *command))(char *cmd, char **args, char **env);
int new_exit(char *cmd, char **args, char **env);
int change_dir(char *cmd, char **args, char **env);
int _exit_me(char *cmd, char **args, char **env);
int help_user(char *cmd, char **args, char **env);



/* Strings functions */
char **get_args(char *buff);
size_t wordcount(char *s);
void free_args(char **args);

/* signal handling */
void handle_signal(__attribute__((unused)) int signum);

/* Env functions */
int print_env(char *cmd, char **args, char **env);

/* string utilities */
int _strlen(const char *s);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *_strdup(const char *str);
int _strncmp(char *s1, char *s2, size_t n);
char *_strstr(char *hays, char *need);
int _puts(char *str);
int _putchar(char c);


/* About environment */

char *_getenv(char *name);
int my_setenv(char *cmd, char **args, char **env);
int build_env(char *name, char *value, int overwrite);

/* /////// */
int _unsetenv(char *cmd, char **args, char **env);


char **malloc_double(size_t size);
char **copy_double(char **old, char **new);
size_t overwrite_after(char *delim, char *str, char *dest);
char **realloc_environ(char **environ, size_t new_size);
char *write_variable(const char *name, const char *val, char *dest);

int sethanv(char *name, char *value, int overwrite);
int add_environ(char *name, char *value, int replace);

/* ///////////////////////// WORK ///////// */


/* error management // exit utilities */
int atoi_error(char *s);
int _isdigit(char *num);



/* stream tools to come */



#endif
