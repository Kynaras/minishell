/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_args_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:20:38 by keverett          #+#    #+#             */
/*   Updated: 2020/01/30 12:20:40 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_args	*ft_t_args_new(char *str)
{
	t_args *new;

	if (!(new = (t_args *)malloc(sizeof(t_args))))
		return (NULL);
	if (str != NULL)
		new->argument = str;
	else
		new->argument = NULL;
	new->next = NULL;
	return (new);
}
