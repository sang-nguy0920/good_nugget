#include "shell.h"
/**
* hsh_exit - exits shell
* Description: exits shell
* Return: void
*/

int hsh_exit(void)
{
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


/**
* hsh_cd - function that changes directory
* @void : void
* Description: function that changes directory
* Return: 0
*/

int hsh_cd(void)
{
char *cwd;
char s[100];

cwd = getcwd(s, 100);

chdir(cwd);

return (0);
}

/**
* hsh_setenv - function that sets environmental variable
* @void : void
* Description: function that sets an env variable
* Return: 0
*/
int hsh_setenv(void)
{
return (0);
}

/**
* hsh_unsetenv - function that unsets environmental variable
* @void : void
* Description: function that unsets an env variable
* Return: 0
*/
int hsh_unsetenv(void)
{
return (0);
}
