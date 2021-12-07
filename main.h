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
/*include structure*/
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

/*args_t *list = NULL;*/
char *putline;
char *line;
/*prototypes prompt*/
int main(int argc, char **argv, char **env);
/*prototypes essential_functions*/
args_t *add(args_t **head, char *arg);
int built_in(args_t **head);
char **transform(args_t **head);
int create_list(char *cpline, char **putline, args_t **arguments);
/*prototypes getenv*/
char *_getenv(const char *name);
/*prototypes built in*/
int envi(void);
int exitt(args_t **lista);
/*prototypes auxiliary_functions*/
void _free_list(args_t **head);
void _free_args(char **args);
int _strcmp(char *s1, char *s2);
void _nest(char *dir, char *command, char **dircon);
void _strdup(char *str, char **str_copy);

#endif /* MAIN_H */
