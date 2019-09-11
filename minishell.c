#include "minishell.h"
#include "libft/libft.h"

void 	ft_arg_split(t_args **input)
{
	int i;
	int j;
	char *tmp;

	tmp = (*input)->argument;
	i = 0;
	while(tmp[i])
	{
		j = 0;
		if(ft_iswhitespace(tmp[i]) != 1 && tmp[i] != '"')
		{
			while(tmp[i + j] && ft_iswhitespace(tmp[i + j]))
				j++;
			ft_t_args_add(input, ft_t_args_new(ft_strsub(tmp, i, j)));
			i = i + j;
		}
		else if (tmp[i] == '"')
		{
			while(tmp[i + j] && tmp[i + j] != '"')
				j++;
			ft_t_args_add(input, ft_t_args_new(ft_strsub(tmp, i, j)));
			i = i + j;
		}
		i++;
	}
}

int ft_read_args(t_args_2d **input, int count)
{
	char *tmp;//read into one copy and paste into other one then strjoin to nput;
	char tmp1[PATH_MAX];
	char **input_arr;
	int i;

	i = 0;
	tmp = NULL;
	ft_memset(tmp1, 0, PATH_MAX);
	tmp = (count == 0) ? readline("$> ") : readline("dquote> ");
	input_arr = ft_strsplit(tmp, ';');
	ft_putstr(input_arr[0]);
	while(tmp[i] && tmp[i] != '\n')
	{
		tmp1[i] = tmp[i];
		if(tmp[i] == '"')
			count = (count == 0) ? 1 : 0;
		i++;
	}
	tmp1[i] = '\0';
	// ft_join(&((*input)->argument), tmp1);
	if (count == 1)
		ft_read_args(input, count);
	// ft_arg_split(input);
	return 1;
}

int main()
{
	// extern char **environ;
	t_args *input;
	t_args_2d *input_2d;
	// t_env_list *env;

	input = ft_t_args_new(NULL);
	// env = ft_splitenv(environ);
	while (ft_read_args(&input_2d, 0))
	{
		// if (ft_strstr(input->argument, "exit") != NULL)//no other arguments otherwise "error exit: too many arguments" message;
		// {
		// 	ft_elstdel(env);
		// 	return (0);
		// }
		// if (ft_strstr("env", input->argument) != NULL)
		// 	ft_env(env);
		// if (ft_strstr(input->argument, "echo") != NULL)
		// {
		// 	while(input)
		// 	{
		// 		ft_putstr(input->argument);
		// 		ft_putchar('\n');
		// 		input = input->next;
		// 	}
		// }
		// if(ft_strstr())
		// 	ft_setenv(&env, envar, enval);//all chars
		ft_strdel(&(input->argument));
	}
}