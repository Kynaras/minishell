/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_namegen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 13:19:44 by keverett          #+#    #+#             */
/*   Updated: 2019/09/19 13:21:02 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *ft_namegen(const char *text, int state)
{
	extern char **environ;
	t_env_list *env = ft_splitenv(environ);
	static int len;
    char *name;
	static int i;
	static char **array;

	

    if (!state) {
        i = -1;
        len = strlen(text);
		array = ft_megarray(ft_pathget(env));
    }
	while (array[++i])
	{
				if (ft_strncmp(array[i], text, len) == 0)
				{
					name = ft_strdup(array[i]);
					return (name);
				}
	}
	return (NULL);
}
