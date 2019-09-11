#include "minishell.h"

void ft_echo( *input)
{
	int i;

	i = 1;
	while (input[i])
	{
		ft_putstr(input[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}