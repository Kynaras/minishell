/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_permcheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:31:35 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 11:31:38 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_subcheck(char *path, char *path2, int count)
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
	{
		if (lstat(path, &sb) == 0 && stat(path, &sb) == -1)
			return (-1);
		else
			return (-1);
	}
}

int	ft_permfind(char *path)
{
	char		*path2;
	struct stat	sb;
	int			count;

	if (!path)
		return (0);
	if (ft_strlen(path) > PATH_MAX)
		return (-1);
	else if ((path2 = ft_namecheck(path)))
		return (0);
	path2 = ft_strdup(path);
	lstat(path, &sb);
	if (S_ISREG(sb.st_mode))
		return (-2);
	if (access(path, F_OK) < 0)
	{
		return (ft_subcheck(path, path2, count));
	}
	if (access(path2, X_OK) < 0)
		return (-1);
	return (0);
}
