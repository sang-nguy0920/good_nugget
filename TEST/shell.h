#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define MALLOC_ERROR "Can't malloc space\n"
#define FORK_ERROR "Can't fork and create child process\n"
#define PATH_ERROR "not found\n"
#define BUFFER 1024
extern char **environ;

/**
 * struct built_s - linked list of builtins
 * @name: name of builtin
 * @p: pointer to function
 *
 * Description: struct for builtin functions.
**/
typedef struct built_s
{
	char *name;
	int (*p)(void);
} built_s;


int child(char *fullpath, char **tokens);
char **copy_env(char **env_copy, unsigned int env_len);
void errors(int error);
int exec_builtin(char **tokens);
char *_getenv(const char *name);
char *_getline(FILE *fp);
char **parse(char *line);
void prompt(int fd, struct stat buf);
char *search_for_path(char *cmd, char *fullpath, char *path);
int hsh_env(void);
int hsh_exit(void);
int shell_num_builtins(built_s builtin[]);
void signal_handler(int sig);
int _strcmp(char *name, char *var, unsigned int len);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strncmp(char *name, char *var, unsigned int len);
void free_everything(char **tokens, char *path, char *line,
char *fullpath, int alert);
void free_dp(char **array, unsigned int len);

#endif