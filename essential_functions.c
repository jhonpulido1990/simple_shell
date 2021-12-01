#include "main.h"
/**
 * add - linked list command
 * @head: header
 * @arg: argument
 * Return: list
 */
args_t *add(args_t **head, char *arg)
{
	args_t *node, *aux;

	aux = *head;
	if (arg == NULL)
		return (NULL);
	node = malloc(sizeof(args_t));
	if (node == NULL)
		return (NULL);
	node->arg = arg;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	while (aux->next)
	{
		aux = aux->next;
	}
	aux->next = node;
	return (node);
}
/**
 * transform - traslate list to string
 * @head: header list
 * Return: argument
 */
char **transform(args_t **head)
{
	int i = 0;
	args_t *h;
	char **arguments;

	/*builtins(head);*/

	h = *head;
	for (i = 0; h; i++)
		h = h->next;
	arguments = malloc((i + 1) * sizeof(char *));
	h = *head;
	for (i = 0; h; i++)
	{
		arguments[i] = h->arg;
		h = h->next;
	}
	arguments[i] = NULL;
	_free_list(head);
	return (arguments);
}
