#include "shell.h"
/**
* shell_num_builtins - check num of builtin funcs
* @builtin : counts num of builtins
* Description: check num of builtin funcs
* Return: num of builtins
*/

int shell_num_builtins(built_s builtin[])
{
unsigned int i;

i = 0;
while (builtin[i].name != NULL)
i++;

return (i);
}

/**
* exec_builtin - executes builtin funcs if needed
* @tokens: tokens to compare to see if they are builtins
* Description: executes builtin funcs if needed
* Return: args
*/
int exec_builtin(char **tokens)
{
int stat;
unsigned int len, num, i;

	built_s builtin[] = {
		{"exit", hsh_exit},
		{"env", hsh_env},
		{"cd", hsh_cd},
		{"setenv", hsh_setenv},
		{"unsetenv", hsh_unsetenv},
		{NULL, NULL}
	};

if (tokens[0] == NULL)
return (1);

len = _strlen(tokens[0]);

num = shell_num_builtins(builtin);
for (i = 0; i < num; i++)
{
if (_strcmp(tokens[0], builtin[i].name, len) == 0)
{
stat = (builtin[i].p)();
return (stat); /*return builtin function */
}
}
return (1);
}
