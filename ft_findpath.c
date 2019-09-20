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

char	*ft_subjoin(char *exepath, char *path, char *arg, char **array)
{
	struct stat sb;

	ft_join(&exepath, path);
	ft_join(&exepath, "/");
	ft_join(&exepath, arg);
	if (lstat(exepath, &sb) != -1)
	{
		if (ft_permcheck(exepath) == -1)
		{
			ft_putstr("minishell: Permission Denied: ");
			ft_putendl(exepath);
			free(exepath);
			ft_freearray(array);
			return (NULL);
		}
	}
	ft_freearray(array);
	return (exepath);
}

char	*ft_findpath(char *arg, t_env_list *env)
{
	t_v_list vars;

	vars.path = ft_strsplit(ft_getenv("PATH", env), ':');
	vars.exepath = NULL;
	vars.i = 0;
	while (vars.path[vars.i])
	{
		if ((vars.dr = opendir(vars.path[vars.i])))
		{
			while ((vars.dir = readdir(vars.dr)))
			{
				if (ft_strcmp(vars.dir->d_name, arg) == 0)
				{
					closedir(vars.dr);
					return (ft_subjoin(vars.exepath, vars.path
					[vars.i], arg, vars.path));
				}
			}
			closedir(vars.dr);
		}
		vars.i++;
	}
	ft_putstr("minishell: command not found :");
	ft_putendl(arg);
	ft_freearray(vars.path);
	return (NULL);
}
