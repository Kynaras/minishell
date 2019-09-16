/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_findpath.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:16:13 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 13:16:16 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

char	*ft_subjoin(char *exepath, char *path, char *arg, DIR *dr)
{
	closedir(dr);
	ft_join(&exepath, path);
	ft_join(&exepath, "/");
	ft_join(&exepath, arg);
	return (exepath);
}

char	*ft_findpath(char *arg, t_env_list *env)
{
	DIR				*dr;
	struct dirent	*dir;
	int				i;
	char			**path;
	char			*exepath;

	path = ft_strsplit(ft_getenv("PATH", env), ':');
	exepath = NULL;
	i = 0;
	while (path[i])
	{
		if ((dr = opendir(path[i])))
		{
			while ((dir = readdir(dr)))
			{
				if (ft_strcmp(dir->d_name, arg) == 0)
					return (ft_subjoin(exepath, path[i], arg, dr));
			}
			closedir(dr);
		}
		i++;
	}
	return (NULL);
}
