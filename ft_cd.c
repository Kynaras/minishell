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

void	ft_subbly(t_env_list *env)
{
	char buf[PATH_MAX + 1];

	ft_setenv(env, "OLDPWD", ft_getenv("PWD", env), 1);
	ft_setenv(env, "PWD", getcwd(buf, PATH_MAX), 1);
}

void	ft_subfunc(t_env_list *env)
{
	ft_setenv(env, "OLDPWD", ft_getenv("PWD", env), 1);
	chdir(ft_getenv("HOME", env));
	ft_setenv(env, "PWD", ft_getenv("HOME", env), 1);
}

void	ft_home(t_env_list *env, char **temp, char **destination)
{
	ft_join(temp, ft_getenv("HOME", env));
	ft_join(temp, "/");
	ft_join(temp, *destination + 2);
	destination = temp;
}

void	ft_homer(t_env_list *env, char *temp)
{
	if (!ft_strcmp(ft_getenv("OLDPWD", env), ft_getenv("PWD", env)))
	{
		ft_putendl("~");
		return ;
	}
	else
	{
		temp = ft_strdup(ft_getenv("OLDPWD", env));
		ft_setenv(env, "OLDPWD", ft_getenv("PWD", env), 1);
		ft_setenv(env, "PWD", temp, 1);
		chdir(temp);
		ft_putendl(temp);
		free(temp);
		return ;
	}
}

void	ft_cd(char *destination, t_env_list *env)
{
	char *temp;
	
	temp = NULL;
	if (!destination)
	{
		ft_subfunc(env);
		return ;
	}
	if (!ft_strcmp(destination, "-"))
	{
		ft_homer(env, temp);
		return ;
	}
	if (destination[0] == '~' && destination[1] == '/'
	&& destination[2] != '\0')
		ft_home(env, &temp, &destination);
	else if (destination[0] == '~' && destination[1] == '\0')
		destination = ft_getenv("HOME", env);
	if (chdir(destination) < 0)
		ft_finderror(destination);
	else
		ft_subbly(env);
	if (temp)
		free(temp);
	return ;
}
