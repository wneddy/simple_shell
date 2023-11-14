#include "main.h"

/**
 * str_cmp - function to compare two strings
 * @str1: string one
 * @str2: string two
 *
 * Return: differential
 */
int str_cmp(char *str1, char *str2)
{
	int comparison, counter;

	counter = 0;
	while (str1[counter] != '\0' && str2[counter] != '\0')
	{
		comparison = str1[counter] - str2[counter];
		if (comparison)
			return (comparison);
		counter++;
	}
	comparison = str1[counter] - str2[counter];
	if (comparison)
		return (comparison);

	return (0);
}

/**
 * str_len - function to get string length
 * @s: string
 * Return: length
 */
int str_len(char *s)
{
	int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * str_bytecmp - function to compare first n bytes of two strings
 * @str1: string one
 * @str2: string two
 * @nmbr: bytes to compare
 * Return: 0, diffrence on failure
 */
size_t str_bytecmp(char *str1, char *str2, size_t nmbr)
{
	size_t counter, check;/* check - for comparison*/

	for (counter = 0; str1[counter] != '\0' && counter < n; counter++)
	{
		check = str1[counter] - str2[counter];

		if (check != 0)
			return (check);
	}
	return (0);
}

/**
 * str_cat - prototype function to concatenate two strings
 * @to: destination of the string
 * @from: source of the string
 *
 * Return: concatenated string
 */
char *str_cat(char *to, char *from)
{
	int e = 0, d = 0;

	while (to[e])
		e++;

	while (from[d])
	{
		to[e] = from[d];
		e++;
		d++;
	}
	to[e] = '\0';
	return (to);
}

/**
 * str_cpy - function to copy string content
 * @to: copy to
 * @from: copy from
 *
 * Return: copied string
 */
char *str_cpy(char *to, char *from)
{
	int a = 0;

	while (from[a])
	{
		to[a] =from[a];
		a++;
	}
	to[a] = from[a];

	return (to);
}
