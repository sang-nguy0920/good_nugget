#include "shell.h"

/**
* _strcmp - compares 2 strings exactly
* @name : input to search for
* @var : var to compare
* @len : name len
* Description: compares 2 strings exactly
* Return: 1 if equal or -1 if not
*/
int _strcmp(char *name, char *var, unsigned int len)
{
unsigned int var_len, i;

var_len = _strlen(var);
if (var_len != len)
return (-1);

i = 0;
while (name[i] != '\0' && var[i] != '\0')
{
if (name[i] != var[i])
return (1);
i++;
}
return (0);
}

/**
 * _strncmp - compares two strings up to given len
 * @name: input to search for
 * @var: var to compare
 * @len: name len
 * Return: 1 if strings are equal, -1 if they are not
 */
int _strncmp(char *name, char *var, unsigned int len)
{
unsigned int i = 0;

while (i < len)
{
if (name[i] != var[i])
return (-1);
i++;
}
return (1);
}

/**
* _strcpy - copies a string from src to dest
* @dest : string
* @src : string
* Description: copies a string from src to dest
* Return: void
*/
char *_strcpy(char *dest, char *src)
{
int i;
int j = _strlen(src);

for (i = 0; i <= j; i++)
dest[i] = src[i];

return (dest);
}
/**
* _strlen -  returns the len of a string
* @s: string
*
* Description: returns the len of a string
* Return:i
*/
int _strlen(char *s)
{
int i = 0;

while (s[i] != '\0')
i++;

return (i);
}
