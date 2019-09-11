/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 12:12:14 by keverett          #+#    #+#             */
/*   Updated: 2019/08/30 12:12:18 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

ssize_t	ft_chrlen(char *buf, char c)
{
	int i;

	i = 0;
	if (buf[0] == '\0')
		return (-1);
	while (buf[i])
	{
		if (buf[0] == c)
			return (0);
		if (buf[i] == c)
			return (i);
		i++;
	}
	return (i);
}
