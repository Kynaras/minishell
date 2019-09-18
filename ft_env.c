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
	while (lst)
	{
		ft_putchar('o');
		ft_putstr(lst->name);
		ft_putchar('=');
		ft_putstr(lst->value);
		ft_putchar('\n');
		lst = lst->next;
	}
	return (0);
}
