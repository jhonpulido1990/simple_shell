#include "main.h"
/**
 * free_list - free a list
 * @head: pointer to list
 *
 * Return: void
 */
void free_list(args_t **head)
{
	args_t *tmp;

	if (head == NULL)
	{
		return;
	}
	while (*head != NULL)
	{
		tmp = *head;
		*head = tmp->next;
		free(tmp);
	}
	*head = NULL;
	free(*head);
}
/**
 * _free_args - free args
 * @args: contain arguments
 *
 * Return: void
 */
void _free_args(char **args)
{
	int i;
	char **tmp;

	tmp = args;

	for (i = 0; tmp[i] != NULL; i++)
	{
		free(tmp[i]);
	}
	free(tmp[i]);
	free(tmp);
}
/**
 * _strcmp - s1 compare s2
 * @s1: comp 1
 * @s2: comp 2
 *
 *
 * Return: compare s1 vs s2
 */
int _strcmp(char *s1, char *s2)
{
	int r = 0, i = 0, j = 0, k = 0, b = 1;

	while (*(s1 + j))
		j++;

	while (*(s2 + k))
		k++;

	if (j != k)
		return (-1);

	while (b != 0)
	{
		r = s1[i] - s2[i];

		if (r == 0)
			i++;

		if (r != 0)
			return (-1);

		if (r != 0 || i == j)
		{
			b = 0;
			return (b);
		}
	}
	return (0);
}
/**
 * _nest - nest command to dir
 * @dir: dir take to path
 * @command: command
 * @dircon: full directory
 *
 * Return: dir + command
 */
void _nest(char *dir, char *command, char **dircon)
{
	int i = 0, j = 0, a = 0, k = 0;
	char *tmp;

	while (dir[i])
		i++;

	while (command[j])
		j++;
	*dircon = malloc(sizeof(char) * (i + j + 2));
	tmp = *dircon;
	for (a = 0; a < i; a++)
	{
		tmp[a] = dir[a];
	}
	tmp[a++] = '/';
	for (k = 0; a < (i + j + 1); k++, a++)
	{
		tmp[a] = command[k];
	}
	tmp[a++] = '\0';
}
/**
 * _strdup - nest command to dir
 * @str: original string
 * @str_copy: copy string
 *
 *
 * Return: void
 */
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
