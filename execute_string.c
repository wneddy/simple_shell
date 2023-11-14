#include "main.h"

/**
 * func_atoi - changes string to integer
 * @str: string to convert
 * Return: converted number
 */
int func_atoi(char *str)
{
	int tally, op, output, view;
	unsigned int number;

	tally = 0;
	op = 1;
	number = 0;
	while (str[tally] != '\0')
	{
		if (str[tally] == '-')
		{
			op = -op;
		}
		else if (str[tally] >= '0' && str[tally] <= '9')
		{
			number = number * 10 + (str[tally] - '0');
			view = tally + 1;
			if (str[view] < '0' || str[view] > '9')
				break;
		}
		tally++;
	}
	output = number * op;
	return (output);
}

/**
 * func_itoa - integer converter to string
 * @p: integer
 * @s: string
 * @station: station to use for the conversion
 * Return: string
 */
void func_itoa(int p, char *s, int station)
{
	int a = 0, op = p;

	if (op < 0)
		p = -p;
	do {
		s[a++] = p % station + '0';
	} while ((p /= station) > 0);

	if (op < 0)
		s[a++] = '-';

	s[a] = '\0';
	str_rev(s);
}

/**
 * str_rev - function to reverse the string
 * @s: string
 */
void str_rev(char *s)
{
	int l, k;
	char rhr;

	for (l = 0, k = str_len(s) - 1; l < k; l++, k--)
	{
		rhr = s[l];
		s[l] = s[k];
		s[k] = rhr;
	}
}

/**
 * str_dup - duplicates a string.
 * @s: string to duplicate
 * Return: string duplicate
 */
char *str_dup(const char *s)
{
	char *str_out;
	unsigned int l, k;

	if (s == NULL)
		return (NULL);

	for (l = 0; s[l] != '\0'; l++)
		;

	str_out = (char *)malloc(sizeof(char) * (l + 1));

	if (str_out == NULL)
		return (NULL);

	for (k = 0; k <= l; k++)
		str_out[k] = s[k];

	return (str_out);
}
