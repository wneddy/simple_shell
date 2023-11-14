#include "main.h"

/**
 * tokenizer - function tokenise input from the user
 * @args: user input
 * Return: string aray
 */
char **tokenizer(char *args)
{
	char *tok = NULL, **input = NULL;
	size_t tally;
	int objects = 0;

	if (!args)
		return (NULL);

	for (tally = 0; args[tally]; tally++)
	{
		if (args[tally] == ' ')
			objects++;
	}
	if ((objects + 1) == str_len(args))
		return (NULL);
	objects += 2;
	input = malloc(sizeof(char *) * (objects));
	if (!input)
		return (NULL);

	tok = str_tok(args, " \n\t\r");
	for (tally = 0; tok != NULL; tally++)
	{
		input[tally] = tok;
		tok = str_tok(NULL, " \n\t\r");
	}
	input[tally] = NULL;
	return (input);
}

/**
 * delimeter_check - finds delimeter characters
 * @ch: char
 * @s: the string
 * Return: 0 success
 */
unsigned int delimeter_check(char ch, const char *s)
{
	unsigned int tally;

	for (tally = 0; s[tally] != '\0'; tally++)
	{
		if (ch == s[tally])
			return (1);
	}
	return (0);
}

/**
 * str_tok - tokenises string
 * @s: string
 * @mark: string delimeter
 * Return: a tokenized string
 */
char *str_tok(char *s, const char *mark)
{
	static char *tok, *n_tok;
	unsigned int k;

	if (s != NULL)
		n_tok = s;
	tok = n_tok;
	if (tok == NULL)
		return (NULL);
	for (k = 0; tok[k] != '\0'; k++)
	{
		if (delimeter_check(tok[k], mark) == 0)
			break;
	}
	if (n_tok[k] == '\0' || n_tok[k] == '#')
	{
		n_tok = NULL;
		return (NULL);
	}
	tok = n_tok + k;
	n_tok = tok;
	for (k = 0; n_tok[k] != '\0'; k++)
	{
		if (delimeter_check(n_tok[k], mark) == 1)
			break;
	}
	if (n_tok[k] == '\0')
		n_tok = NULL;
	else
	{
		n_tok[k] = '\0';
		n_tok = n_tok + k + 1;
		if (*n_tok == '\0')
			n_tok = NULL;
	}
	return (tok);
}
