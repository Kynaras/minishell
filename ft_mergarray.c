/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mergarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:21:41 by keverett          #+#    #+#             */
/*   Updated: 2019/09/19 13:21:51 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **ft_megarray(char **array)
{
	DIR *dr;
	struct dirent *dir;
	char **megarray;
	int i = -1;
	int str = 0;
	while (array[++i])
	{
		if ((dr = opendir(array[i])))
		{
			while((dir = readdir(dr)))
			{
				str++;
			}
		}
		closedir(dr);
	}
	megarray = ft_memalloc(sizeof (char *) * str + 2);
	i = -1;
	str = 0;
	while (array[++i])
	{
		if ((dr = opendir(array[i])))
		{
			while((dir = readdir(dr)))
			{
				megarray[str] = ft_strdup(dir->d_name);
				str++;
			}
			closedir(dr);
		}
	}
	return (megarray);
}
