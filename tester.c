#include "minishell.h"

int main()
{
	extern char **environ;
	t_env_list *lst = ft_splitenv(environ);
	char *path = NULL;

	if ((path = ft_findpath("ls", lst)))
	{
		ft_putendl(path);
	}
}
