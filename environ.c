#include "shell.h"

/**
 * _myenv - prints the current environment
 * @inff: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _myenv(info_t *inff)
{
	print_list_str(inff->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @inff: Structure containing potential arguments. Used to maintain
 * @namme: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *inff, const char *namme)
{
	list_t *node = inff->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, namme);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}

/**
 * _mysetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @inff: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _mysetenv(info_t *inff)
{
	if (inff->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(inff, inff->argv[1], inff->argv[2]))
		return (0);
	return (1);
}

/**
 * _myunsetenv - Remove an environment variable
 * @inff: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _myunsetenv(info_t *inff)
{
	int i;

	if (inff->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (i = 1; i <= inff->argc; i++)
		_unsetenv(inff, inff->argv[i]);

	return (0);
}

/**
 * populate_env_list - populates env linked list
 * @inff: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int populate_env_list(info_t *inff)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		add_node_end(&node, environ[i], 0);
	inff->env = node;
	return (0);
}
