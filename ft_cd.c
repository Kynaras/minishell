/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 11:11:44 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 11:12:13 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd(char **destination)
{
	if (!destination)
		return (0);
	if (chdir(destination[1]) < 0)
	{
		ft_errorfind(destination[1]);
	}
}
