#include "main.h"
/**
 * space - this function search spaces
 * @line: line
 *
 * Return: status
 */
int space(char *line)
{
	int i = 0, status = 0;

	while (line[i] != '\n')
	{
		i++;
		if (line[i] != ' ')
			status++;
	}
	return (status);
}
