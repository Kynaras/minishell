#include "minishell.h"

int 	ft_slashcount(char *path, int ignore)
{
	int i;
	i = 0;
	while (path[i])
	{
		i++;
	}
	i--;
	while(i >= 0 && ignore > 0)
	{
		ignore--;
		if (path[i] == '/')
			ignore--;
		i--;
	}
	return (i);
}