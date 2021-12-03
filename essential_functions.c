#include "main.h"
/**
 * add - linked list command
 * @head: header
 * @arg: argument
 *
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
 * no_built_in - call to no built in functions
 * @head: list of arguments
 *
 * Return: 0 if built_in is success
 */
int no_built_in(args_t **head)
{
	char *path_string, *putpath;
	char *dir = NULL;
	char *dircon, *command;
	args_t *aux = *head;
	int status;
	struct stat buf;

	_strdup(_getenv("PATH"), &path_string);
	command  = aux->arg;
	putpath = path_string;
	for (; (dir = strtok(path_string, ":")); path_string = NULL)
	{
		if (dir == NULL)
		{
			free(putpath);
			continue;
		}
		_nest(dir, command, &dircon);
		status = stat(dircon, &buf);
		if (status == 0)
		{
			aux->arg = dircon;
			free(putpath);
			free(dircon);
			return (0);
		}
		printf("free dircon\n");
		free(dircon);
	}
	/*aux->arg = "/bin/clear";*/
	free(putpath);
	return (0);
}
/**
 * built_in - call to built in functions
 * @head: list of arguments
 *
 * Return: 0 if built_in is success
 */
int built_in(args_t **head)
{
	select_built_t modulo[] = {{"exit1", holam1}, {"exit2", holam2},
				   {"exit3", holam3}, {NULL, NULL}};
	args_t *aux = *head;
	int comp, i;
	char *dato = aux->arg;

	for (i = 0; modulo[i].f != NULL; i++)
	{
		comp = _strcmp(modulo[i].id, dato);

		if (comp == 0)
		{
			modulo[i].f();
			return (0);
		}

	}

	if (comp != 0)
	{
		no_built_in(head);
		return (1);
	}
	return (1);
}
/**
 * transform - traslate list to string
 * @head: header list
 *
 * Return: argument
 */
int transform(args_t **head, char ***args)
{
	int i = 0, statusb = 1;
	args_t *h;
	char **args_aux = *args;

	statusb = built_in(head);
	if (statusb == 0)
		return (0);
	h = *head;
	for (i = 0; h; i++)
		h = h->next;
	*args = malloc((i + 1) * sizeof(char *));
	args_aux = *args;
	h = *head;
	for (i = 0; h; i++)
	{
		args_aux[i] = h->arg;
		h = h->next;
	}
	args_aux[i] = NULL;
	return (1);
}
