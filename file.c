#include "minishell.h"

t_env_list *ft_t_vnew(char *name, char *value)
{
	t_env_list *new;

	new = malloc(sizeof(t_env_list));
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	return (new);
}