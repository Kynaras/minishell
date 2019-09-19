#include "minishell.h"

void ft_arg_split(t_args_2d **input, char **colon) //return 2d_node
{
	int i;
	int j;
	int x;
	t_args_2d *argtmp;
	x = 0;
	while (colon[x])
	{
		if (*input == NULL && ft_strlen(colon[x]) != 0 && ft_strcmp(colon[x], "\n") != 0)
            *input = ft_t_args_2d_new(NULL);
        else if (*input != NULL)
			ft_t_args_2d_add(input, ft_t_args_2d_new(NULL));
		argtmp = *input;
		while(argtmp && argtmp->next)
			argtmp = argtmp->next;
		i = 0;
		while (ft_strlen(colon[x]) != 0 && colon[x][i] && ft_strcmp(colon[x], "\n") != 0)
		{
			j = 0;
			if (ft_iswhitespace(colon[x][i]) != 1 && colon[x][i] != '"')
			{
				while (colon[x][i + j] && ft_iswhitespace(colon[x][i + j]) != 1)
					j++;
				if (argtmp && argtmp->node == NULL)
					argtmp->node = ft_t_args_new(ft_strsub(colon[x], i, j));
				else
					ft_t_args_add(&(argtmp->node), ft_t_args_new(ft_strsub(colon[x], i, j)));
				i = i + j;
			}
			else if (colon[x][i] == '"')
			{
				i++;
				while (colon[x][i + j] && colon[x][i + j] != '"')
					j++;
				if (argtmp->node == NULL)
					argtmp->node = ft_t_args_new(ft_strsub(colon[x], i, j));
				else
					ft_t_args_add(&(argtmp->node), ft_t_args_new(ft_strsub(colon[x], i, j)));
				i = i + j;
			}
			i++;
		}
		x++;
	}

}
