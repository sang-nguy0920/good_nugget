#include "shell.h"

/**
* child - child process function
* @fullpath: full path of exec
* @tokens: parsed tokens from input stream
* Description: check num of builtin funcs
* Return: 0 for success
*/
int child(char *fullpath, char **tokens)
{
pid_t child_pid;
int stat;
int execve_stat;
char **envp = environ;
/*
* environ points to array of enviroment strings made available
* to the process that started the execve call
*/

child_pid = fork(); /*creates new process by duplicating the calling process*/
if (child_pid == -1)/* on failure, child created */
{
errors(1);
exit(EXIT_FAILURE);
}
if (child_pid == 0)/* success */
{
execve_stat = execve(fullpath, tokens, envp);
if (execve_stat == -1)
return (-1);/* on error */
}
else
wait(&stat);
return (0);
}
