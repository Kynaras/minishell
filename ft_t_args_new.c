#include "minishell.h"

t_args	*ft_t_args_new(char *str)
{
	t_args *new;

	if (!(new = (t_args *)malloc(sizeof(t_args))))
		return (NULL);
    new->argument = ft_strdup(str);
	new->next = NULL;
	return (new);
}