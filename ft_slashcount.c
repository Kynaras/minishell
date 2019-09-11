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
		if (path[i] == '/')
			ignore--;
		i--;
	}
	if (i == -1) 
		return (0);
	else
		return (i);
}