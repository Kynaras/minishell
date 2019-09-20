/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_args_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:26:27 by keverett          #+#    #+#             */
/*   Updated: 2019/09/20 10:26:29 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_t_args_free(t_args **head)
{
	t_args *tmp;

	while (*head)
	{
		tmp = *head;
		ft_strdel(&(*head)->argument);
		*head = (*head)->next;
		free(tmp);
	}
}