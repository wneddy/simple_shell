#include "main.h"

/**
 * putchar_ - function to print character in the stdout
 * @ch: char to print
 * Return: no. of printed characters
 */
int putchar_(char ch)
{
	static char buff[1024];
	static int a;

	if (ch == -1 || a >= 1024)
	{
		write(STDOUT_FILENO, &buff, a);
		a = 0;
	}
	if (ch != -1)
	{
		buff[a] = ch;
		a++;
	}
	return (1);
}

/**
 * puts_ - prototype function to prints a string in the stdout
 * @s: string.
 * Return: numbers of characters printed
 */
int puts_(char *str)
{
	register int a;

	for (a = 0; s[a] != '\0'; a++)
		putchar_(s[a]);
	putchar_(-1);
	return (a);
}
