#include "main.h"
/**
 * free_listint2 - free a list
 * @head: pointer to list
 *
 * Return: void
 */
void _free_list(args_t *head)
{
	(void) head;
}
/**
 * _free_args - free a list
 * @head: pointer to list
 *
 * Return: void
 */
void _free_args(char **args)
{
	int i;

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args[i]);
	free(args);
}
