#include "main.h"
/**
 * main - main
 *
 * Return: Always 0
 */
int main(int argc, char **argv, char **env)
{
	ssize_t status_read, tty = 1;
	char *line, *cpline, *arg = NULL, **args = NULL;
	int status_execve, status;
	pid_t pid;
	size_t lineSize = 0;
	args_t *arguments = NULL;

	UNUSED(argc);
	UNUSED(argv);
	UNUSED(env);

	isatty(STDIN_FILENO) == 0 ? tty = 0 : tty;
	do {
		tty == 1 ? write(STDOUT_FILENO, "($) ", 4) : tty;
		fflush(stdin);
		status_read = getline(&line, &lineSize, stdin);
		if (status_read == -1)
			return (-1);
		cpline = strdup(line);
		for (; (arg = strtok(cpline, " \t\n")); cpline = NULL)
		{
			if (arg == NULL)
				break;
			add(&arguments, arg);
		}
		args = transform(&arguments);
		pid = fork();
		if (pid == 1)
			return (-1);
		else if (pid == 0)
		{
			status_execve = execve(args[0], args, env);
			if (status_execve == -1)
				return (-1);
		}
		else
			wait(&status);
		arguments = NULL;
	} while (1);
	return (0);
}
