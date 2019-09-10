#include "minishell.h"

int main()
{
	extern char **environ;
	t_e_list *lst = ft_splitenv(environ);
	ft_env(lst);
}
