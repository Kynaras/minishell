#include "minishell.h"

int    ft_env(t_env_list *lst)
{
	t_env_list *tmp;


    while (lst)
    {
    	tmp = lst;
	    ft_putstr(lst->name);
        free(lst->name);
		ft_putchar('=');
        ft_putstr(lst->value);
        free(lst->value);
		ft_putchar('\n');
        lst = lst->next;
		free(tmp);
	}
	return 0;
}
