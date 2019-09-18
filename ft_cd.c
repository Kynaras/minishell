/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:11:44 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 11:12:13 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char *destination, t_env_list *env)
{
	char buf[PATH_MAX + 1];

	if (!destination)
	{
		ft_setenv(env, "OLDPWD", ft_getenv("PWD", env), 1);
		ft_setenv(env, "PWD", ft_getenv("HOME", env), 1);
		return ;
	}
	chdir(ft_getenv("PWD", env));
	if (chdir(destination) < 0)
	{
		ft_errorfind(destination);
	}
	else
	{
		ft_setenv(env, "OLDPWD", ft_getenv("PWD", env), 1);
		ft_setenv(env, "PWD", getcwd(buf, PATH_MAX), 1);
	}
	return ;
}
