/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 16:50:03 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 16:50:06 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <time.h>

void	ft_time(void)
{
	time_t	t;
	char	**clock;

	time(&t);
	clock = ft_strsplit(ctime(&t), ' ');
	write(1, clock[3], 5);
	ft_putchar(' ');
	ft_freearray(clock);
	return (0);
}
