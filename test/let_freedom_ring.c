#include "shell.h"

/**
 * free_everything - frees all malloc'd space at end of main loop
 * @tokens: pointer to tokens array
 * @path: pointer to path var
 * @line: pointer to user input buffer
 * @fullpath: pointer to full path
 * @alert: alert marking if full_path was malloc'd
 * Return: void
 */
void free_everything(char **tokens, char *path, char *line,
char *fullpath, int alert)
{
	free(path);
	free(tokens);
	free(line);
	if (alert == 1)
	free(fullpath);
}

/**
 * free_dp - free double pointer
 * @array: double pointer to free
 * @len: len of double pointer
 * Return: void
 */
void free_dp(char **array, unsigned int len)
{
	unsigned int i = 0;

	while (i < len)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
