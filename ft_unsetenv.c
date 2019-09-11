#include "minishell.h"

void    ft_unsetenv(t_env_list *lst, const char *name)
{
    t_env_list *tmp;

    tmp = NULL;
    while (lst)
    {
        if (ft_strcmp(name, lst->name) == 0)
            break;
        tmp = lst;
        lst = lst->next;
    }
    if (lst)
    {
        free(lst->name);
        free(lst->value);
        if(tmp)
            tmp->next = lst;
        free(lst);
    }
    return;
}
