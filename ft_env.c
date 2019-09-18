/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 09:25:39 by keverett          #+#    #+#             */
/*   Updated: 2019/09/18 09:26:23 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(t_env_list *lst)
{
	t_env_list *tmp;

	while (lst)
	{
		tmp = lst;
		ft_putstr(lst->name);
		free(lst->name);
		ft_putchar('=');
		ft_putstr(lst->value);
		free(lst->value);
		ft_putchar('\n');
		lst = lst->next;
		free(tmp);
	}
	return (0);
}
