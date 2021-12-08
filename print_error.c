#include "main.h"
/**
 * print_str - print str
 * @str: string to print
 *
 * Return: void
 */
void print_str(char *str)
{
	int i = 0, j = 0, k = 0;
	char *not_found = ": not found";

	while (argv0[k] != '\0')
	{
		_putchar(argv0[k]);
		k++;
	}
	_putchar(58);
	_putchar(32);
	print_num(count);
	_putchar(58);
	_putchar(32);
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	while (not_found[j] != '\0')
	{
		_putchar(not_found[j]);
		j++;
	}
	putchar('\n');
}
