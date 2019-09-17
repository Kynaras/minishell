#include "minishell.h"
#include <dirent.h>

char	*ft_findpath(char *arg, t_env_list *env)
{
	DIR *dr;
	struct dirent *dir;
	int i = 0;
	char **path = ft_strsplit(ft_getenv("PATH", env), ':');
	char *exepath = NULL;

	while (path[i])
	{
		if ((dr = opendir(path[i])))
		{
			while ((dir = readdir(dr)))
			{
				if (ft_strcmp(dir->d_name, arg) == 0)
				{
					closedir(dr);
					ft_join(&exepath, path[i]);
					ft_join(&exepath, "/");
					ft_join(&exepath, arg);
					return(exepath);
				}
			}
			closedir(dr);
		}
		i++;
	}
	return (NULL);
}