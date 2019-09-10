#include "minishell.h"

int    ft_env(t_e_list *lst)
{
    while (lst)
    {
        ft_putstr(lst->name);
        ft_putchar('=');
        ft_putstr(lst->value);
        ft_putchar('\n');
        lst = lst->next;
	}
	return 0;
}
