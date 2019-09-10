#include "minishell.h"

t_e_list    *ft_splitenv(char **environ)
{
    t_e_list *lst;
    int i;
    int j;

    i = 0;
	lst = NULL;
    while (environ[i])
    {
        j = 0;
        while (environ[i][j] != '=')
        {
            j++;
        }
        if (lst)
            ft_t_add(&lst, ft_t_new(environ[i], j));
        else
            lst = ft_t_new(environ[i], j);
		i++;
    }
    return (lst);
}
