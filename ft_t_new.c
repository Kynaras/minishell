#include "minishell.h"

t_e_list *ft_t_new(char *str, int len)
{
    int i;
	int j;
    t_e_list *new;

    new = malloc(sizeof(t_e_list));
    i = 0;
	j = 0;
    if ((new->name = ft_memalloc(len)) &&
    (new->value = ft_memalloc(ft_strlen(str + len))))
    {
        while (str[i] && i < len)
        {
            new->name[i] = str[i];
            i++;
        }
        i++;
        while (str[i])
        {
            new->value[j] = str[i];
            i++;
			j++;
        }
    }
    new->next = NULL;
	return (new);
}
