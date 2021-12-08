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
