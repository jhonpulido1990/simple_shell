#include "main.h"
int create_list(char* cpline, char** putline, args_t ** arguments)
{
	char* arg = NULL;

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
