#include "main.h"

/**
 * get_input - gets users input
 *
 * Return: returns users input.
 */
char *get_input(void)
{
	char *input = NULL;
	size_t input_size = 0;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);
	if (getline(&input, &input_size, stdin) == -1)
	{
		free(input);
		return (NULL);
	}
	return (input);
}
