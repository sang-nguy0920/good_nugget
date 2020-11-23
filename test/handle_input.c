#include "shell.h"

/**
* _getline - puts input in a buffer
* @fp : input buffer
* Description: puts input in a buffer
* Return: buffer input
*/
char *_getline(FILE *fp)
{
char *line; /* input */
ssize_t read;
size_t len = 0;
line = NULL;

read = getline(&line, &len, fp); /*returns num of bytes read from input */

if (read == -1) /* on error */
{
free(line);
exit(EXIT_SUCCESS);
}
return (line);
}

/**
* parse - parses line by delimiters
* @line : *line input pointer
* Description: parses line by delimiters
* Return: cmd input
*/
char **parse(char *line)
{
char **tokens;
char *token;
unsigned int i;

tokens = malloc(sizeof(char) * BUFFER);

if (tokens == NULL)
{
perror("Error: ");
exit(EXIT_FAILURE);
}

token = strtok(line, "\n "); /* removing delims spaces from input */

i = 0;
while (token != NULL)
{
tokens[i] = token;
token = strtok(NULL, "\n "); /*setting input to tokens */
i++;
}
tokens[i] = NULL; /* reset to [0] so main can continue*/
return (tokens);
}
