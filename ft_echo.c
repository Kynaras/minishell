#include "minishell.h"

int ft_echo(char **input)
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