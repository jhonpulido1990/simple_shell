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

	status = stat(aux->arg, &buf);

	if (status == 0)
	return (1);

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
			return (3);
		}
		free(dircon);
	}
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
	select_built_t modulo[] = {{"env", envi}, {"exit", exitt},
				   {NULL, NULL}};
	args_t *aux = *head;
	int comp, i, status_nb;
	char *dato = aux->arg;

	if (head == NULL)
		return (0);

	for (i = 0; modulo[i].f != NULL; i++)
	{
		comp = _strcmp(modulo[i].id, dato);

		if (comp == 0)
		{
			if (i == 1)
			{
				modulo[i].f(head);
				return (0);
			}
			modulo[i].f();
			return (0);
		}
	}
	if (comp != 0)
	{
		status_nb = no_built_in(head);
		if (status_nb == 1)
			return (1);
		if (status_nb == 3)
		{
			return (3);
		}
		else
		{
			salida = 127;
			print_str(head, dato);
			return (2);
		}
	}
	return (2);
}
/**
 * transform - traslate list to string
 * @head: header list
 *
 * Return: argument
 */
char **transform(args_t **head)
{
	int i = 0;
	args_t *h = NULL;
	char **args;

	h = *head;
	for (i = 0; h; i++)
		h = h->next;
	args = malloc((i + 1) * sizeof(char *));
	if (args == NULL)
		return (NULL);
	h = *head;
	for (i = 0; h; i++)
	{
		args[i] = h->arg;
		h = h->next;
	}
	args[i] = NULL;
	return (args);
}
/**
 * create_list - create list
 * @cpline: line copy
 * @putline: pointer to line
 * @arguments: argument list
 *
 * Return: argument
 */
int create_list(char *cpline, char **putline, args_t **arguments)
{
	char *arg = NULL;

	(void) putline;
	for (; (arg = strtok(cpline, " \t\n")); cpline = NULL)
	{
		if (arg == NULL)
		{
			free(*putline);
			break;
		}
		add(arguments, arg);
	}
	return (0);
}
