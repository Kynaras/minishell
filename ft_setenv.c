/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:07:15 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 12:08:20 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_setenv(t_env_list *original, char *name, char *value, int write)
{
	t_env_list *lst;

	lst = original;
	if (!lst)
		return ;
	while (lst)
	{
		if (ft_strcmp(name, lst->name) == 0)
			break ;
		else
			lst = lst->next;
	}
	if (lst && write > 0)
	{
		free(lst->name);
		free(lst->value);
		lst->name = ft_strdup(name);
		lst->value = ft_strdup(value);
		return ;
	}
	else if (!lst)
		ft_t_add(original, ft_t_vnew(name, value));
}
