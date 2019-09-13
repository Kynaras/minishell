#include "minishell.h"

char	**ft_lstarray(t_env_list *lst)
{
	char **array;
	char *temp;
	t_env_list *tmp;
	size_t len;

	tmp = lst;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	array = malloc(sizeof(char *) * len + 1);
	len = 0;
	while (lst)
	{
		array[len] = NULL;
		ft_join(&(array[len]), lst->name);
		ft_join(&(array[len]), "=");
		ft_join(&(array[len]), lst->value);
		len++;
		lst = lst->next;
	}
	array[len] = NULL;
	return(array);
}