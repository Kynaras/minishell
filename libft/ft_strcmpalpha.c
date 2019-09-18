/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmpalpha.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 15:40:06 by keverett          #+#    #+#             */
/*   Updated: 2019/09/18 15:41:56 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmpalpha(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] != '\0')
	{
		if (str1[i] >= 'A' && str1[i] <= 'Z')
		{
			if ((str1[i] != str2[i] && str1[i] != (str2[i] - 32)) || str2[i]
			== '\0')
				return (str1[i] - str2[i]);
		}
		else if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			if ((str1[i] != str2[i] && str1[i] != (str2[i] + 32)) || str2[i]
			== '\0')
				return (str1[i] - str2[i]);
		}
		i++;
	}
	return (str1[i] - str2[i]);
}
