#include "minishell.h"

void	ft_t_args_2d_add(t_args_2d **lst, t_args_2d *new)
{
	t_args_2d *ptr;

	ptr = *lst;
	if (lst)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->next = NULL;
	}
}