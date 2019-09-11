#include "minishell.h"
#include "libft/libft.h"

void 	ft_arg_split(t_args **input)
{
}

int ft_read_args(t_args **input, int count)
{
	char tmp[PATH_MAX];//read into one copy and paste into other one then strjoin to nput;
	char tmp1[PATH_MAX];
	int i;

	i = 0;
	ft_memset(tmp, 0, PATH_MAX);
	ft_memset(tmp1, 0, PATH_MAX);
	read(0, tmp, PATH_MAX);
	while(tmp[i] && tmp[i] != '\n')
	{
		tmp1[i] = tmp[i];
		if(tmp[i] == '"')
			count = (count == 0) ? 1 : 0;
		i++;
	}
	tmp1[i] = '\0';
	ft_join((*input)->argument, tmp1);
	if (count == 1)
	{
		write(1, "dquote> ", 8);
		ft_read_args(input, count);
	}
	return 1;
}

int main()
{
	extern char **environ;
	t_args *input;
	t_e_list *env;
	int i;

	i = 0;
	input = NULL;
	env = ft_splitenv(environ);
	while (write(1, "$> ", 3) && ft_read_args(&input, 0))
	{
		ft_putstr(input->argument);
		ft_arg_split(&input);
		if (ft_strcmp(input, "exit\n") == 0)
		{
			ft_elstdel(env);
			return (0);
		}
		if (ft_strcmp("env\n", input) == 0)
			ft_env(env);
		if (ft_strstr(input, "echo") != NULL)
		{
			i = 0;
			while(input)
			{
				ft_putstr(input->argument);
				ft_putchar('\n');
				input = input->next;
			}
		}
		// if(ft_strstr())
		// 	ft_setenv(&env, envar, enval);//all chars
		ft_strdel(&input);
	}
}