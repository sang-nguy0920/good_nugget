#include "shell.h"

/**
* errors - switches for diff error messages
* @error : ints for errors
* Description: switches for diff error messages
* Return: void
*/
void errors(int error)
{
	switch (error)
	{
	case 1: /* writes fork error to stderr */
		write(STDERR_FILENO, FORK_ERROR, _strlen(FORK_ERROR));
		perror("Error 1");
		break;

	case 2: /* writes execve error to stderr */
		perror("not found");
		break;

	case 3: /* writes malloc error to stderr */
		write(STDERR_FILENO, MALLOC_ERROR, _strlen(MALLOC_ERROR));
		break;
	case 4: /* writes empty path error to stderr */
		write(STDERR_FILENO, PATH_ERROR, _strlen(PATH_ERROR));
		break;

	default:
		return;
	}
}
