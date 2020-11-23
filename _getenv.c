#include "shell.h"
/**
* _getenv - function that gets an environment var.
* @name : env var name
* Description: function that gets an environment var.
* Return: value of var else NULL
*/
char *_getenv(const char *name)
{
char **env_copy;
char *var, *value, *path;
int compare;
unsigned int path_len, env_len, len, i;
env_len = 0;
while (environ[env_len] != NULL)
env_len++;
env_copy = NULL;
env_copy = copy_env(env_copy, env_len);
len = _strlen((char *)name);
i = 0;
while (env_copy[i] != NULL)
{
var = env_copy[i]; /* loops through until PATH == var name*/
compare = _strncmp((char *)name, var, len);
	if (compare == 1) /* PATH and var are equal*/
	{
	value = strtok(var, "=");
	value = strtok(NULL, "\n");
				if (value == '\0')
				{
				perror("Error: ");
				exit(EXIT_FAILURE);
				}
	path_len = _strlen(value);
	path = malloc(sizeof(char) * path_len + 1);
				if (path == NULL)
				{
				perror("Error: ");
				return (NULL);
				}
	path = _strcpy(path, value); /* copies pathname to path */
	free_dp(env_copy, env_len);
	return (path); /* parsed path */
	}
i++;
}
return (NULL);
}

/**
* copy_env - makes copy of enviroment var array
* @env_copy : pointer to copy
* @env_len : unsigned int len
* Description: makes copy of enviroment var array
* Return: pointer to the copy
*/
char **copy_env(char **env_copy, unsigned int env_len)
{
char *var;
unsigned int var_len;
unsigned int i;

env_copy = malloc(sizeof(char **) * (env_len));
if (env_copy == NULL)
{
perror("Error: ");
return (NULL);
}

i = 0;
while (i < env_len)
{
var = environ[i];
var_len = _strlen(var); /*gets length of environ[] */

env_copy[i] = malloc(sizeof(char) * var_len + 1);
if (env_copy[i] == NULL)
{
perror("Error: ");
return (NULL);
}

_strcpy(env_copy[i], environ[i]); /*copies environ[] to env_copy*/
i++;
}
return (env_copy);
}
