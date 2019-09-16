/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:46:30 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 09:46:33 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env_list	*ft_t_new(char *str, int len)
{
	int			i;
	int			j;
	t_env_list	*new;

	new = malloc(sizeof(t_env_list));
	i = 0;
	j = 0;
	if ((new->name = ft_memalloc(len)) &&
		(new->value = ft_memalloc(ft_strlen(str + len))))
	{
		while (str[i] && i < len)
		{
			new->name[i] = str[i];
			i++;
		}
		i++;
		while (str[i])
		{
			new->value[j] = str[i];
			i++;
			j++;
		}
	}
	new->next = NULL;
	return (new);
}
