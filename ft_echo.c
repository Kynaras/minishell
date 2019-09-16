/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 09:01:13 by keverett          #+#    #+#             */
/*   Updated: 2019/09/16 09:01:16 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_args *input)
{
	input = input->next;
	while (input)
	{
		ft_putstr(input->argument);
		ft_putchar(' ');
		input = input->next;
	}
	ft_putchar('\n');
}
