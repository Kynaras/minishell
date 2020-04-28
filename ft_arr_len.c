/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 10:29:25 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/20 10:29:27 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	ft_arr_len(char **arr)
{
	size_t len;

	len = 0;
	if (arr)
	{
		while (arr[len] != NULL)
		{
		// printf("%s", arr[len]);
			len++;
		}
	}
	printf("%ld", len);
	return (len);
}
