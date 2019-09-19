/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_elstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:51:09 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 12:51:42 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_elstdel(t_env_list *lst)
{
	t_env_list *tmp;

	while (lst)
	{
		tmp = lst;
		free(lst->name);
		free(lst->value);
		lst = lst->next;
		free(tmp);
	}
}
