#include "main.h"
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
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
/**
 * print_num - print num
 * @num: num to print
 *
 * Return: void
 */
void print_num(int num)
{
	_putchar(num + 48);
}
/**
 * _getenv - get enviroment function
 * @name: name directory path
 *
 * Return: Always 0 (Success)
 */
char *_getenv(const char *name)
{
	int i, j;
	char *value;

	if (!name)
		return (NULL);
	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;

				j++;
			}
			if (name[j] == '\0')
			{
				value = (environ[i] + j + 1);
				return (value);
			}
		}
	}
	return (0);
}
