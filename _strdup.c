#include "main.h"
void _strdup(char *str, char **str_copy)
{
	int i = 0, j = 0;
	char *tmp;

	while (*(str + i))
	{
		i++;
	}

	*str_copy = malloc(sizeof(char) * (i + 1));
	tmp = *str_copy;

	while (j <= i)
	{
		tmp[j] = str[j];
		j++;
	}
}
