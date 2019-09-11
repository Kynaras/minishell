#include "minishell.h"

void 	ft_elstdel(t_env_list *lst)
{
	while (lst)
	{
		free(lst->name);
		free(lst->value);
		lst = lst->next;
	}
}