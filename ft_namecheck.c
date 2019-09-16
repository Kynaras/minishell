/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_namecheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 12:09:25 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 12:09:27 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_namecheck(char *path)
{
	char	*ret;
	char	**array;
	int		i;

	i = 0;
	array = ft_strsplit(path, '/');
	while (array[i])
	{
		if (ft_strlen(array[i]) > NAME_MAX)
		{
			ret = ft_strdup(array[i]);
			ft_freearray(array);
			return (ret);
		}
		i++;
	}
	ft_freearray(array);
	return (NULL);
}
