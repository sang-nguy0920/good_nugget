#include "shell.h"

/**
* child - child process function
* @fullpath: full path of exec
* @tokens: parsed tokens from input stream
* Description:
* Return: 0 for success
*/
int child(char *fullpath, char **tokens)
{
pid_t child_pid;
int stat, execve_stat;
char **envp = environ;

child_pid = fork(); /*creates new process by duplicating the calling process*/
if (child_pid == -1)/* on failure */
{
perror("Error: ");
_exit(EXIT_FAILURE);
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
