#include "main.h"
void print_str(args_t **head, char *str)
{
	int i = 0, j = 0;
	char *not_found = ": not found";
	args_t *aux = *head;

	(void) head;
	(void) aux;

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
