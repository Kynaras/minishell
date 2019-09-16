/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:57:25 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 09:57:30 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list	*ft_splitenv(char **environ)
{
	t_env_list	*lst;
	int			i;
	int			j;

	i = 0;
	lst = NULL;
	while (environ[i])
	{
		j = 0;
		while (environ[i][j] != '=')
		{
			j++;
		}
		if (lst)
			ft_t_add(lst, ft_t_new(environ[i], j));
		else
			lst = ft_t_new(environ[i], j);
		i++;
	}
	return (lst);
}
