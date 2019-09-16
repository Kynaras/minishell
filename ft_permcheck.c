#include "minishell.h"

int	ft_permfind(char *path)
{
	if (!path)
		return (0);
	char *path2;
	char *tmp;
	struct stat sb;
	int slashes;
	int count;

	if(ft_strlen(path) > PATH_MAX)
	{
		return (-1);
	}
	else if ((path2 = ft_namecheck(path)))
	{
		return(0);
	}
	
	path2 = ft_strdup(path);
	lstat(path, &sb);
	if (S_ISREG(sb.st_mode))
	{
		return (-2);
	}
	if (access(path, F_OK) < 0)
	{
		slashes = 1;
		while(path2 && (count = ft_slashcount(path, slashes)))
		{
			tmp = path2;
			path2 = ft_strsub(path, 0, count + 1);
			if (access(path2, X_OK) < 0)
			{
				count = -5;
				break ;
			}
			free(tmp);
			slashes++;
		}
		if (count != -5 && path2[0] != '/')
		{
			if (lstat(path, &sb) == 0 && stat(path, &sb) == -1)
			{
				return (-1);
			}
			else
			{
			return (-1);
			}
		}
	}
	if (access(path2, X_OK) < 0)
	{
		return (-1);
	}
	return (0);
}