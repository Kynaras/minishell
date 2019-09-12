#include "minishell.h"

t_args_2d	*ft_t_args_2d_new(t_args *lst)
{
	t_args_2d *new;

	if (!(new = (t_args_2d *)malloc(sizeof(t_args_2d))))
		return (NULL);
	new->next = NULL;
	new->node = lst;
	return (new);
}