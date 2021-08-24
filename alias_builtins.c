/*
 * File: builtins.c
 * Auth: Dismas Kipchumba
 	 Hanifa Chepkorir
 */
#include <shell.h>

int shellby_alias(char **args, char __attribute__((__unused__)) **front);
void set_alias(char *var_name, char *value);
void print_alias(alias_t *alias);

/**
 * replace_aliases - checks the arguments and replaces any matching alias with their value
 * @args: 2D pointer to the arguments
 * Return: 2D pointer to the arguments
 */

char **replace_aliases(char **args)
{
	alias_t *temp;
	int i;
	char *new_value;

	if (_strcmp(args[0], "alias") == 0)
		return (args);
	for (i = 0; args[i]; i++)
	{
		temp = aliases;
		while (temp)
		{
			if (_strcmp(args[i], temp->name) == 0)
			{
				new_value = malloc(sizeof(char) * (_strlen(temp->value) + 1));
				if (!new_value)
				{
					free_args(args, args);
					return (NULL);
				}
				_strcpy(new_value, temp->value);
				free(args[i]);
				args[i] = new_value;
				i--;
				break;
			}
			temp = temp->next;
		}
	}
	return (args);
}
/**
 * shellby_alias - Builtin command that either prints all aliases, specific
 * aliases, or sets an alias.
 * @args: an array of arguments
 * @front: a double pointer to the beginning of args.
 * Return: -1 if an error occurs, otherwise 0
 */
int shellby_aias(char **args, char __attribute__((__unused__)) **front)
{
	alias_t *temp = aliases;
	int i, ret

