#include "minishell.h"

void	ft_t_args_add(t_args **lst, t_args *new)
{
	t_args *ptr;

	ptr = NULL;
	if (lst)
		ptr = *lst;
	if (ptr)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
		new->next = NULL;
	}
}
