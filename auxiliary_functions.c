#include "main.h"
/**
 * free_listint2 - free a list
 * @head: pointer to list
 *
 * Return: void
 */
void _free_list(args_t **head)
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
