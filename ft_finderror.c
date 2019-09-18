/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finderror.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:33:11 by keverett          #+#    #+#             */
/*   Updated: 2019/09/18 15:33:14 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_ftoolong(char *path2)
{
	ft_putstr("cd: file name too long: ");
	ft_putendl(path2);
	free(path2);
	return (0);
}

int	ft_perm(char *path, char *path2)
{
	ft_putstr("cd: Permission denied: ");
	ft_putendl(path);
	free(path2);
	return (-1);
}

int	ft_subsubcheck(char *path, char *path2, struct stat *sb)
{
	if (lstat(path, sb) == 0 && stat(path, sb) == -1)
	{
		ft_putstr("cd: too many levels of symbolic links: ");
		ft_putendl(path);
		free(path2);
		return (-1);
	}
	else
	{
		ft_putstr("cd: no such file or directory: ");
		ft_putendl(path);
		free(path2);
		return (-1);
	}
	return (0);
}

int	ft_subcheck(char *path, char *path2, int count, struct stat *sb)
{
	char	*tmp;
	int		slashes;

	slashes = 1;
	while (path2 && (count = ft_slashcount(path, slashes)))
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
		return (ft_subsubcheck(path, path2, sb));
	return (0);
}

int	ft_finderror(char *path)
{
	char		*path2;
	struct stat	sb;
	int			count;

	count = 0;
	if (!path)
		return (0);
	if (ft_strlen(path) > PATH_MAX)
		return (ft_toolong(path));
	else if ((path2 = ft_namecheck(path)))
		return (ft_ftoolong(path2));
	path2 = ft_strdup(path);
	lstat(path, &sb);
	if (S_ISREG(sb.st_mode))
	{
		ft_putstr("cd: not a directory: ");
		ft_putendl(path);
		free(path2);
		return (-2);
	}
	if (access(path, F_OK) < 0)
		return (ft_subcheck(path, path2, count, &sb));
	if (access(path2, X_OK) < 0)
		return (ft_perm(path, path2));
	return (0);
}
