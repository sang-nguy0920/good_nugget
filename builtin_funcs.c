#include "shell.h"
/**
* hsh_exit - exits shell
* Description: exits shell
* Return: void
*/

int hsh_exit(void)
{
    kill(getpid(), SIGTERM);
return (-1);
}


/**
* hsh_env - function that prints the enviroment
* @void : void
* Description: function that prints the enviroment
* Return: nothing
*/

int hsh_env(void)
{
unsigned int i;

i = 0;
while (environ[i] != NULL)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
i++;
}
return (0);
}
