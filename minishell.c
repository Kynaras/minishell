#include "minishell.h"
#include "libft/libft.h"

void ft_arg_split(t_args_2d **input, char *tmp)
{
	int i;
	int j;

	i = 0;
	while (tmp[i])
	{
		j = 0;
		if (ft_iswhitespace(tmp[i]) != 1 && tmp[i] != '"')
		{
			while (tmp[i + j] && ft_iswhitespace(tmp[i + j]) != 1)
				j++;
			if((*input)->node == NULL)
				(*input)->node = ft_t_args_new(ft_strsub(tmp, i, j));
			else
				ft_t_args_add(&((*input)->node), ft_t_args_new(ft_strsub(tmp, i, j)));
			i = i + j;
		}
		else if (tmp[i] == '"')
		{
			i++;
			while (tmp[i + j] && tmp[i + j] != '"')
				j++;
			if((*input)->node == NULL)
				(*input)->node = ft_t_args_new(ft_strsub(tmp, i, j));
			else
				ft_t_args_add(&((*input)->node), ft_t_args_new(ft_strsub(tmp, i, j)));
			i = i + j;
		}
		i++;
	}
}

char *ft_read_dquote(char *tmp, int count)
{
	int i;
	i = 0;

	ft_join(&tmp, readline("dquote> "));
	count = 0;
	while (tmp[i])
	{
		if (tmp[i] == '"')
			count = (count == 0) ? 1 : 0;
		i++;
	}
	if (count == 1)
		tmp = ft_read_dquote(tmp, count);
	return tmp;
}

int ft_read_args(t_args_2d **input_2d, int count)
{
	char *tmp;
	int i;

	if (*input_2d == NULL)
		*input_2d = ft_t_args_2d_new(NULL);
	i = 0;
	tmp = readline("$> ");
	add_history(tmp);
	while (tmp[i])
	{
		if (tmp[i] == '"')
			count = (count == 0) ? 1 : 0;
		i++;
	}
	if (count == 1)
		tmp = ft_read_dquote(tmp, count);
	ft_arg_split(input_2d, tmp);
	return 1;
}

int main() //echo, cd, setenv, unsetenv, env, exit

{
	extern char **environ;
	t_args *input;
	t_args_2d *input_2d;
	t_env_list *env;

	input_2d = NULL;
	input = ft_t_args_new(NULL);
	env = ft_splitenv(environ);
	while (input_2d || ft_read_args(&input_2d, 0))
	{
		if (input_2d)
		{
			// while(tmp)
			// {
			// 	ft_putstr(tmp->argument);
			// 	ft_putstr("\n");
			// 	tmp = tmp->next;
			// }
			if (ft_strstr(input_2d->node->argument, "exit") != NULL) //no other arguments otherwise "error exit: too many arguments" message;
			{
				ft_elstdel(env);
				return (0);
			}
			// if (ft_strstr("env", input->argument) != NULL)
			// 	ft_env(env);
			if (ft_strstr(input_2d->node->argument, "echo") != NULL)
				ft_echo(input_2d->node);
			// if(ft_strstr())
			// 	ft_setenv(&env, envar, enval);//all chars
			ft_strdel(&(input->argument));
			// ft_putstr("ok");
			input_2d = input_2d->next;
		}
	}
}