/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pathget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:21:46 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 12:26:55 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <dirent.h>

char	**ft_pathget(t_env_list *env)
{
	DIR				*dr;
	struct dirent	*dir;
	char			**array;
	int				i;

	i = 0;
	while (env)
	{
		if (!ft_strcmpalpha(env->name, "PATH"))
			break ;
		env = env->next;
	}
	if (env)
		return (ft_strsplit(env->value, ';'));
	else
		return (NULL);
}
