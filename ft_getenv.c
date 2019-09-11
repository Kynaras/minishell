#include "minishell.h"

char	*ft_getenv(char *var, t_env_list *lst)
{
	while (lst)
	{
		if (!ft_strcmp(var, lst->name))
			return(lst->value);
		lst = lst->next;
	}
	return (NULL);
}
