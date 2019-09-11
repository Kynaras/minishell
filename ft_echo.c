#include "minishell.h"

void ft_echo(t_args *input)
{
	while (input)
	{
		ft_putstr(input->argument);
		ft_putchar(' ');
		input = input->next;
	}
	ft_putchar('\n');
}