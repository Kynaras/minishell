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
	int i;

	i = 0;
	input = input->next;
	if(!ft_strcmp("-n", input->argument) || !ft_strcmp("-", input->argument))
	{
		if (!ft_strcmp("-n", input->argument))
			i = 1;
		input = input->next;
	}
	while (input)
	{
		ft_putstr(input->argument);
		if (input->next != NULL)
			ft_putchar(' ');
		input = input->next;
	}
	if (i == 0)
		ft_putchar('\n');
	else
	{
		ft_putstr("\e[30m\e[47m");
		ft_putstr("%");
		ft_putstr("\033[0m");
		ft_putchar('\n');
	}
}
