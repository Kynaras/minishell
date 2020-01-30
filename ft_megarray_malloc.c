/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_megarray_malloc.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:43:41 by zhelm             #+#    #+#             */
/*   Updated: 2020/01/30 15:43:47 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "minishell.h"
#include <dirent.h>
#include <fcntl.h>

int		ft_megarray_malloc(char **array)
{
	DIR				*dr;
	struct dirent	*dir;
	int				i;
	int				str;

	str = 0;
	i = -1;
	while (array[++i])
	{
		if ((dr = opendir(array[i])))
		{
			while ((dir = readdir(dr)))
				str++;
		}
		closedir(dr);
	}
	return (str);
}
