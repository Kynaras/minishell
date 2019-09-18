#include "minishell.h"

char **ft_t_lst_array(t_args *lst)
{
    char		**array;
	t_env_list	*tmp;
	size_t		len;

	tmp = lst;
	len = 0;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	array = malloc(sizeof(char *) * len + 1);
	len = 0;
	while (lst)
	{
        array[len] = ft_strdup(lst->argument);
        len++;
        lst = lst->next;
	}
	array[len] = NULL;
	return (array);
}