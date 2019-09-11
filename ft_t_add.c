#include "minishell.h"

void    ft_t_add(t_env_list *lst, t_env_list *new)
{
	t_env_list *tmp;
	
	tmp = lst;
	if (lst)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}
