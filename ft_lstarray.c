/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstarray.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:49:04 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 12:49:44 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_lstarray(t_env_list *lst)
{
	char		**array;
	char		*temp;
	t_env_list	*tmp;
	size_t		len;

	tmp = lst;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	array = malloc(sizeof(char *) * len + 1);
	len = 0;
	while (lst)
	{
		array[len] = NULL;
		ft_join(&(array[len]), lst->name);
		ft_join(&(array[len]), "=");
		ft_join(&(array[len]), lst->value);
		len++;
		lst = lst->next;
	}
	array[len] = NULL;
	return (array);
}
