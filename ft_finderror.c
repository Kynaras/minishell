#include "minishell.h"

int	ft_errorfind(char *path)
{
	char *path2;
	char *tmp;
	struct stat sb;
	int slashes;
	int count;

	path2 = ft_strdup(path);
	lstat(path, &sb);

	
	if (S_ISREG(sb.st_mode))
	{
		ft_putstr("cd: not a directory: ");
		ft_putstr(path);
		ft_putchar('\n');
		free(path2);
		return (-1);
	}
	if (access(path, F_OK) < 0)
	{
		slashes = 1;
		while(path2 && (count = ft_slashcount(path, slashes)))
		{
			tmp = path2;
			path2 = ft_strsub(path, 0, slashes);
			if (access(path2, F_OK >= 0))
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
			ft_putstr(path);
			ft_putchar('\n');
			free(path2);
			sleep(30);
			return (-1);
		}
	}
	if (access(path2, X_OK) < 0)
	{
		ft_putstr("Permission denied: ");
		ft_putstr(path);
		ft_putchar('\n');
		free(path2);
		sleep (30);
		return (-1);
	}
	return (0);
}