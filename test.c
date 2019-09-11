#include "minishell.h"

int main()
{
	extern char **environ;
	t_env_list *lst = ft_splitenv(environ);
	ft_env(lst);
}
