/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_args_2d_new.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:20:09 by keverett          #+#    #+#             */
/*   Updated: 2020/01/30 12:20:11 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args_2d	*ft_t_args_2d_new(t_args *lst)
{
	t_args_2d *new;

	if (!(new = (t_args_2d *)malloc(sizeof(t_args_2d))))
		return (NULL);
	new->next = NULL;
	new->node = lst;
	return (new);
}
