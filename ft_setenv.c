#include "minishell.h"

void    ft_setenv(t_e_list **original, char *name, char *value, int write)
{
    t_e_list *lst = *original;

    if (!lst)
        return ;
    
    while (lst)
    {
        if (ft_strcmp(name, lst->name) == 0)
            break;
        else
            lst = lst->next;
    }
    if (lst && write > 0)
    {
        free(lst->name);
        free(lst->value);
        lst->name = ft_strdup(name);
        lst->value = ft_strdup(value);
        return;
    }
    else if (!lst)
        ft_t_add(*original, ft_t_vnew(name, value));   
}
