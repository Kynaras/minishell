#include "minishell.h"

void 	main(t_e_list *lst)
{
	while (lst)
	{
		free(lst->name);
		free(lst->value);
		lst = lst->next;
	}
}