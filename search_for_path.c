#include "shell.h"
/**
* search_for_path - searches dir for cmd in env PATH var
* @cmd: input to search
* @fullpath: full path of cmd to exec
* @path: full PATH var
* Description: searches dir for cmd in env PATH var
* Return: pointer to full path
*/
char *search_for_path(char *cmd, char *fullpath, char *path)
{
unsigned int cmd_len, path_len, old_path_len;
char *path_copy, *token;

cmd_len = _strlen(cmd); /* cmd is == input */
old_path_len = _strlen(path);
path_copy = malloc(sizeof(char) * old_path_len + 1);
if (path_copy == NULL)
{
perror("Error: ");
return (NULL);
}
_strcpy(path_copy, path);
token = strtok(path_copy, ":"); /* returns path up until it hits the : delim */
		if (token == NULL)
		token = strtok(NULL, ":");
while (token != NULL)
{
path_len = _strlen(token);
fullpath = malloc(sizeof(char) * (path_len + cmd_len) +2);
	if (fullpath == NULL)
	{
	perror("Error: ");
	return (NULL);
	}
_strcpy(fullpath, token); /* copies path of PATH up to delim to fullpath */
fullpath[path_len] = '/';
_strcpy(fullpath + path_len + 1, cmd);
fullpath[path_len + cmd_len + 1] = '\0';/* */
	if (access(fullpath, X_OK) != 0)
	{
	free(fullpath);
	fullpath = NULL;
	token = strtok(NULL, ":");
	}
else
break; /* when token reaches null then break out */
}
free(path_copy);
return (fullpath);
}
