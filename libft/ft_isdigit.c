/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 10:19:57 by keverett          #+#    #+#             */
/*   Updated: 2019/05/30 15:12:33 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int d)
{
	if (d >= '0' && d <= '9')
		return (1);
	else
		return (0);
}
