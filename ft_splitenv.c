#include "minishell.h"

t_e_list    *ft_splitenv(char **environ)
{
    t_e_list *lst;
    int i;
    int j;

    i = 0;
    while (environ[i++])
    {
        j = 0;
        while (environ[i][j] != '=')
        {
            j++;
        }
        if (lst)
            ft_t_add(lst, ft_t_new(ft_strsub(environ[i], 0, j), j));
        else
            lst = ft_t_new(ft_strsub(environ[i], 0, j), j);
    }
    return (lst);
}
