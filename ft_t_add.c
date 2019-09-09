#include "minishell.h"

void    ft_t_add(t_e_list *lst, t_e_list *new)
{
    if (!lst)
        return ;
    while (lst->next)
    {
        lst = lst->next;
    }
    lst->next = new;
}
