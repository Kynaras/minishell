/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toolong.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:35:29 by keverett          #+#    #+#             */
/*   Updated: 2019/09/18 15:35:35 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_toolong(char *path)
{
	ft_putstr("cd: Path length too long: ");
	ft_putendl(path);
	return (-1);
}
