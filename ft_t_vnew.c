/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_vnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:26:06 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 09:30:22 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list	*ft_t_vnew(char *name, char *value)
{
	t_env_list *new;

	new = malloc(sizeof(t_env_list));
	new->name = ft_strdup(name);
	new->value = ft_strdup(value);
	return (new);
}
