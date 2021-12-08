#include "main.h"
/**
 * main - main
 *
 * @argc: unused
 * @argv: unused
 * @env: unused
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	ssize_t status_read, tty = 1;
	char *cpline = NULL, **args = NULL;
	int status_execve, status, status_trans;
	size_t lineSize = 0;
	args_t *list = NULL;

	salida = 0, line = NULL, count = 0, UNUSED(argc), argv0 = argv[0];
	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	do { tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
		fflush(stdin), status_read = getline(&line, &lineSize, stdin), count++;
		if (status_read == EOF)
		{ free(line);
			break; }
		if (*line == ' ' ||*line == '\t' || *line == '\n')
			continue;
		_strdup(line, &cpline),	pl = cpline;
		create_list(cpline, &pl, &list), status_trans = built_in(&list);
		if (status_trans == 0)
		{free_list(&list), free(pl);
			continue; }
		if (status_trans == 2)
		{free_list(&list), free(pl);
			continue; }
		args = transform(&list);
		if (args == NULL)
			return (-1);
		pid = fork();
		if (pid == 1)
			return (-1);
		else if (pid == 0)
		{
			status_execve = execve(args[0], args, env), exit(status_execve);
		} else
			wait(&status);
		if (status_trans == 3)
			free(list->arg);
		free_list(&list), free(args), free(pl), free(line), list = NULL, line = NULL;
	} while (1);
	return (0);
}
