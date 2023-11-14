#include "main.h"

/**
 * path_finder - function to find PATH value from env.
 * @env_var: enviroment variable
 * Return: PATH values
 */
char *path_finder(char **env_var)
{
	size_t tally, front, elements = 0;
	char *loc = NULL;

	for (front = 0; str_bytecmp(env_var[front], "PATH=", 5); front++)
		;
	if (!env_var[front])
		return (NULL);
	for (tally = 5; env_var[front][elements]; elements++, tally++)
		;
	loc = malloc(sizeof(char) * (tally + 1));
	if (!loc)
		return (NULL);
	for (elements = 5, tally = 0; env_var[front][elements]; elements++, tally++)
		loc[tally] = env_var[front][elements];
	loc[tally] = '\0';

	return (loc);
}

/**
 * path_handler - prototype function to handle the path value.
 * @token: tokenized user command
 * @env_var: environment variable
 * Return: success
 */
int path_handler(char **token, char **env_var)
{
	char *value = NULL, *loc_new = NULL, *command = NULL;
	size_t path_size, cmd_size;
	struct stat status;

	if (stat(*token, &status) == 0)
		return (-1);
	value = path_finder(env_var);
	if (!value)
		return (-1);
	command = str_tok(value, ":");
	cmd_size = str_len(*token);
	while (command)
	{
		path_size = str_len(command);
		loc_new = malloc(sizeof(char) * (path_size + cmd_size + 2));
		if (!loc_new)
		{
			free(value);
			return (-1);
		}
		loc_new = str_cpy(loc_new, command);
		str_cat(loc_new, "/");
		str_cat(loc_new, *token);
		if (stat(loc_new, &status) == 0)
		{
			*token = loc_new;
			free(value);
			return (0);
		}
		free(loc_new);
		token = str_tok(NULL, ":");
	}
	free(value);
	return (-1);
}
