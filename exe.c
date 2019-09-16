#include "minishell.h"

int main()
{
	extern char **environ;
	t_env_list *lst = ft_splitenv(environ);

	if(ft_findpath("chmod", lst));
	{
		if (ft_errorfind(ft_findpath("chmod", lst)) != -1)
				ft_putendl("Success!");
				}
	
	return (0);
}
