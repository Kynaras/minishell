/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errorfind.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:27:14 by keverett          #+#    #+#             */
/*   Updated: 2019/09/18 09:27:16 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_errorfind(char *path)
{
	char *path2;
	char *tmp;
	struct stat sb;
	int slashes;
	int count;

	if (!path)
		return (0);
	if (ft_strlen(path) > PATH_MAX)
	{
		ft_putstr("cd : Path length too long: ");
		ft_putendl(path);
		return (-1);
	}
	else if ((path2 = ft_namecheck(path)))
	{
		ft_putstr("cd: file name too long: ");
		ft_putendl(path2);
		return (0);
	}

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
	{
		slashes = 1;
		while (path2 && (count = ft_slashcount(path, slashes)))
		{
			tmp = path2;
			path2 = ft_strsub(path, 0, count + 1);
			if (access(path2, X_OK) < 0)
			{
				count = -5;
				break;
			}
			free(tmp);
			slashes++;
		}
		if (count != -5 && path2[0] != '/')
		{
			if (lstat(path, &sb) == 0 && stat(path, &sb) == -1)
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
