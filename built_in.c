#include "main.h"
/**
 * envi - list of environment variables
 *
 * Return: list
 */
int envi(void)
{
	size_t i;

	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
	return (0);
}
/**
 * exitt - end of program
 *
 * Return: exit
 */
int exitt(void)
{
	exit(-1);
}
