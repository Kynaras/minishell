#include "minishell.h"

void    ft_t_add(t_e_list **lst, t_e_list *new)
{
	t_e_list *tmp;
	
	tmp = *lst;
	if (lst)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
		new->next = NULL;
	}
}
