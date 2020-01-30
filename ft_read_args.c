/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:19:26 by keverett          #+#    #+#             */
/*   Updated: 2020/01/30 12:19:29 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_read_quote(char *tmp, int qcount)
{
	int i;
	i = 0;

	ft_join(&tmp, readline("quote> "));
	qcount = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\'')
			qcount = (qcount == 0) ? 1 : 0;
		i++;
	}
	if (qcount == 1)
		tmp = ft_read_quote(tmp, qcount);
	return tmp;
}

char *ft_read_dquote(char *tmp, int count)
{
	int i;
	i = 0;

	ft_join(&tmp, readline("dquote> "));
	count = 0;
	while (tmp[i])
	{
		if (tmp[i] == '"')
			count = (count == 0) ? 1 : 0;
		i++;
	}
	if (count == 1)
		tmp = ft_read_dquote(tmp, count);
	return tmp;
}

void ft_read_args_while(char tmp, int *qcount, int *count)
{
    if (tmp == '"' && *qcount == 0)
        *count = (*count == 0) ? 1 : 0;
    else if (tmp == '\'' && count == 0)
        *qcount = (*qcount == 0) ? 1 : 0;
}

int ft_read_args(t_args_2d **input_2d, int count)
{
	char *tmp;
	int i;
	int qcount;
	char **colon;

	qcount = 0;
	i = 0;
	colon = NULL;
	tmp = readline("$> ");
	add_history(tmp);
	if (tmp)
	{
		while (tmp[i])
		{
            ft_read_args_while(tmp[i], &qcount, &count);
			i++;
		}
		if (count == 1)
			tmp = ft_read_dquote(tmp, count);
		if (qcount == 1)
			tmp = ft_read_quote(tmp, qcount);
		if((colon = ft_strsplit(tmp, ';')) && colon != NULL)
			ft_arg_split(input_2d, colon);
        ft_strdel(&tmp);
        ft_freearray(colon);
	}
	return 1;
}
