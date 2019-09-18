/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:04:11 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 09:04:55 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unsetenv(t_env_list **env, const char *name)
{
	t_env_list *lst;
	t_env_list *tmp;

	lst = *env;
	tmp = NULL;
	while (lst)
	{
		if (ft_strcmp(name, lst->name) == 0)
			break ;
		tmp = lst;
		lst = lst->next;
	}
	if (lst)
	{
		free(lst->name);
		free(lst->value);
		if (tmp)
			tmp->next = lst->next;
		else if (!tmp)
			*env = lst->next;
		free(lst);
	}
	return ;
}
