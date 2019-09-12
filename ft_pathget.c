#include "minishell.h"
#include <dirent.h>

char **ft_pathget(t_env_list *env)
{
	DIR *dr;
	struct dirent *dir;
	char **array;
	int i = 0;
	while (env)
	{
		if (!ft_strcmp(env->name, "PATH"))
			break ;
		env = env->next;
	}
	if (env)
		return (ft_strsplit(env->value, ';'));
	else
		return (NULL);

	// while (array[i++])
	// {
	// 	if ((dr = open(array[i])))
	// 	{
	// 		while(dir = readdir(dr))
	// 		{
				
	// 		}
	// 	}

	// }
}