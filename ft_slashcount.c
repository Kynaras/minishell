/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slashcount.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 13:14:37 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 13:14:48 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_slashcount(char *path, int ignore)
{
	int i;

	i = 0;
	while (path[i])
	{
		i++;
	}
	i--;
	while (i >= 0 && ignore > 0)
	{
		if (path[i] == '/')
			ignore--;
		i--;
	}
	if (i == -1)
		return (0);
	else
		return (i);
}
