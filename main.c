#include "shell.h"
/**
* signal_handler - handles CTRL+C, doesn't exit
* @sig : value to change
* Description: handles CTRL+C, doesn't exit
* Return: nada
*/
void signal_handler(int sig)
{
(void)sig;
write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * prompt - checks mode and prints prompt if in interactive mode
 * @fd: file stream
 * @buf: buffer
**/
void prompt(int fd, struct stat buf)
{
	fstat(fd, &buf);
	if (S_ISCHR(buf.st_mode))
	write(STDOUT_FILENO, "$ ", 2);
}

/**
* main - entry point, main shell loop
* @void : nada
* Description: main shell loop
* Return: 0 for success
*/
int main(void)
{
char *line, *path, *fullpath, **tokens;
int alert, builtin_stat, child_stat;
struct stat buf;
signal(SIGINT, signal_handler); /*SIGINT ignores interupt signal (ctrl+C) */
while (1) /* True, infinite loop */
{
prompt(STDIN_FILENO, buf);/*STDIN_FILENO MACRO== file descriptor == 0*/
line = _getline(stdin);/*FILE * line = input cmd*/
if (_strcmp(line, "\n", 1) == 0) /*if input equals \n */
{
free(line);
continue;
}
tokens = parse(line);/*Parse input taking out delims, tokens = input cmd*/
if (tokens[0] == NULL)
continue;
builtin_stat = exec_builtin(tokens); /*search through builtin*/
if (builtin_stat == 0 || builtin_stat < 0)
{
free(tokens);
free(line);
}
if (builtin_stat == 0) /* is env builtin */
continue;
if (builtin_stat == -1) /* is exit builtin */
exit(EXIT_SUCCESS);
alert = 0; /* 0 if fullpath isn't malloc*/
path = _getenv("PATH");
fullpath = search_for_path(tokens[0], fullpath, path); /* gets pathname */
if (fullpath == NULL)
fullpath = tokens[0];
else
alert = 1; /* 1 if fullpath is malloc*/
child_stat = child(fullpath, tokens);
if (child_stat == -1)
perror("./hsh: ");
free_everything(tokens, path, line, fullpath, alert); /*free everythiSng */
}
return (0);
}
