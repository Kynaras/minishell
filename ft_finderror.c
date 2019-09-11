#include "minishell.h"


void 	ft_freearray(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free (array[i]);
		i++;
	}
	free(array);
}
char	*ft_namecheck(char *path)
{
	char *ret;
	char **array;
	int i;

	i = 0;
	array = ft_strsplit(path, '/');
	while (array[i])
	{
		if (ft_strlen(array[i]) > NAME_MAX)
		{
			ret = ft_strdup(array[i]);
			ft_freearray(array);
			return (ret);
		}
		i++;
	}
	ft_freearray(array);
	return (NULL);

}
int	ft_errorfind(char *path)
{
	char *path2;
	char *tmp;
	struct stat sb;
	int slashes;
	int count;

	if(ft_strlen(path) > PATH_MAX)
	{
		ft_putstr("cd : Path length too long: ");
		ft_putendl(path);
		return (-1);
	}
	else if ((path2 = ft_namecheck(path)))
	{
		ft_putstr("cd: file name too long: ");
		ft_putendl(path2);
		return(0);
	}
	
	path2 = ft_strdup(path);
	lstat(path, &sb);
	if (S_ISREG(sb.st_mode))
	{
		ft_putstr("cd: not a directory: ");
		ft_putendl(path);
		free(path2);
		return (-1);
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
			ft_putstr("cd: no such file or directory: ");
			ft_putendl(path);
			free(path2);
			return (-1);
		}
	}
	if (access(path2, X_OK) < 0)
	{
		ft_putstr("Permission denied: ");
		ft_putendl(path);
		free(path2);
		return (-1);
	}
	return (0);
}