#include "minishell.h"
#include "libft/libft.h"

void ft_arg_split(t_args_2d **input)
{
	int i;
	int j;
	char *tmp;

	tmp = (*input)->node->argument;
	i = 0;
	while (tmp[i])
	{
		j = 0;
		if (ft_iswhitespace(tmp[i]) != 1 && tmp[i] != '"')
		{
			while (tmp[i + j] && ft_iswhitespace(tmp[i + j]) != 1)
				j++;
			ft_t_args_add(&((*input)->node), ft_t_args_new(ft_strsub(tmp, i, j)));
			i = i + j;
		}
		else if (tmp[i] == '"')
		{
			i++;
			while (tmp[i + j] && tmp[i + j] != '"')
				j++;
			// j--;
			ft_t_args_add(&((*input)->node), ft_t_args_new(ft_strsub(tmp, i, j)));
			i = i + j;
		}
		i++;
	}
}

int ft_read_args(t_args_2d **input_2d, int count)
{
	char *tmp; //read into one copy and paste into other one then strjoin to nput;
	char tmp1[PATH_MAX];
	char **input_arr;
	t_args_2d *ptr;
	int i;

	i = 0;
	tmp = NULL;
	ft_memset(tmp1, 0, PATH_MAX);
	tmp = (count == 0) ? readline("$> ") : readline("dquote> ");
	add_history(tmp);
	if (count == 0)
		*input_2d = NULL;
	input_arr = ft_strsplit(tmp, ';');
	if (ft_arr_len(input_arr) > 0 && count == 0)
	{
		while (input_arr[i])
		{
			if (*input_2d == NULL)
				*input_2d = ft_t_args_2d_new(ft_t_args_new(input_arr[i]));
			else if (*input_2d != NULL)
				ft_t_args_2d_add(input_2d, ft_t_args_2d_new(ft_t_args_new(input_arr[i])));
			i++;
		}
	}
	else
		ft_join(&((*input_2d)->node->argument), input_arr[0]);
	count = 0;
	ptr = *input_2d;
	while (ptr)
	{
		i = 0;
		while (ptr->node->argument[i] && ptr->node->argument[i] != '\n')
		{
			tmp1[i] = ptr->node->argument[i];
			if (ptr->node->argument[i] == '"')
				count = (count == 0) ? 1 : 0;
			i++;
		}
		tmp1[i] = '\0';
		ft_strdel(&(ptr->node->argument));
		ft_join(&(ptr->node->argument), tmp1);
		if (count == 1)
			ft_read_args(&ptr, count);
		ft_arg_split(&ptr);
		ptr = ptr->next;
	}
	return 1;
}

int main()//echo, cd, setenv, unsetenv, env, exit

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