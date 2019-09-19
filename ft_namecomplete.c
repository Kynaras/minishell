/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_namecomplete.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:18:48 by keverett          #+#    #+#             */
/*   Updated: 2019/09/19 13:19:11 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_namecomplete(const char *text, int start, int end)
{
	int i;

	i = end;
    rl_attempted_completion_over = 1;
	rl_completion_append_character = '\0';
	if (start == 0)
		return rl_completion_matches(text, ft_namegen);
	else return (NULL);
}
