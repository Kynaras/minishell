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

void	ft_cd(char **destination, t_env_list *env)
{
	if (!destination)
		return (0);
	if (chdir(destination[1]) < 0)
	{
		ft_errorfind(destination[1]);
	}
	else
	{
		ft_setenv(env, "OLDPWD", ft_getenv("PWD", env), 1);
		ft_setenv(env, "PWD", destination, 1);
	}
	return ;
}
	
}

