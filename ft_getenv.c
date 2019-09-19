/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:12:54 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 13:13:34 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_getenv(char *var, t_env_list *lst)
{
	while (lst)
	{
		if (!ft_strcmpalpha(var, lst->name))
			return (lst->value);
		lst = lst->next;
	}
	return (NULL);
}
