/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlonglong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/07 12:46:53 by keverett          #+#    #+#             */
/*   Updated: 2019/08/07 12:49:45 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putlonglong(long long n)
{
	if (n > 9)
		ft_putlonglong(n / 10);
	ft_putchar((int)n % 10 + 48);
}
