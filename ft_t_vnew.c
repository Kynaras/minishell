#include "minishell.h"

t_e_list *ft_t_vnew(char *name, char *value)
{
    t_e_list *new;

    new = malloc(sizeof(t_e_list));
    new->name = ft_strdup(name);
    new->value = ft_strdup(value);
    return (new);
}
