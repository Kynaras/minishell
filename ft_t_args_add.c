#include "minishell.h"

void	ft_t_args_add(t_args **lst, t_args *new)
{
	t_args *ptr;

	ptr = *lst;
	if (lst)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->next = NULL;
	}
}