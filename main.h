#ifndef MAIN_H
#define MAIN_H
/*include library*/
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>
#define UNUSED(x) (void)(x)
extern char **environ;
/**
 * struct args_s - linked list
 * @arg: comand
 * @next: pointer to next node
 */
typedef struct args_s
{
	char *arg;
	struct  args_s *next;
} args_t;
/**
 * struct built_l - built in
 * @id: identification function
 * @f: pointer to function
 */
typedef struct built_l
{
	char *id;
	int (*f)();
} select_built_t;
/*prototypes*/
int main(int argc, char **argv, char **env);
args_t *add(args_t **head, char *arg);
char **transform(args_t **head);
void _free_list(args_t **head);
void _free_args(char **args);

int envi(void);
int exitt(void);

int _strcmp(char *s1, char *s2);
char *_getenv(const char *name);
void _nest(char *dir, char *command, char **dircon);
void _strdup(char *str, char **str_copy);
int create_list(char *cpline, char **putline, args_t **arguments);
int built_in(args_t **head);
#endif /* MAIN_H */
