#include "minishell.h"
#include "libft/libft.h"

size_t ft_count_args(char *input)
{
	size_t i;
	size_t d;
	size_t strings;

	i = 0;
	d = 1;
	strings = 0;
	while (input[i] != '\0')
	{
		if (input[i] != '"' && d == 1)
		{
			d = 0;
			strings++;
		}
		if (input[i] == '"' && d == 0)
			d = 1;
		i++;
	}
	ft_putnbr((int)strings);
	return (strings);
}



char **ft_arg_split(char *input)//logic is bad here
{
	int i;
	int j;
	int n;
	char **input_split;

	j = 0;
	i = 0;
	n = 0;
	input_split = NULL;
	input_split = (char**)malloc(sizeof(char *) * (ft_count_args(input) + 2));
	while (input[i])
	{
		if (ft_iswhitespace(input[i]) != 1 && input[i] != '"' && input[i] != '\n')
		{
			j = 0;
			while (input[i + j] && ft_iswhitespace(input[i + j]) != 1)
				j++;
			input_split[n] = ft_strsub(input, i, j);
			i = i + j + 1;
			n++;
		}
		else if (input[i] == '"')
		{
			j = 0;
			i++;
			while (input[i + j] && input[i + j] != '"')
				j++;
			input_split[n] = ft_strsub(input, i, j);
			n++;
			i = i + j + 1;
		}
		else
			i++;
	}
	input_split[n] = NULL;
	return input_split;
}

int ft_read_args(char **input, int count)
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
	ft_join(input, tmp1);
	if (count == 1)
	{
		write(1, "dquote> ", 8);
		ft_read_args(input, count);
	}
	return 1;
}

int main() //make sure there is only one command
{
	extern char **environ;
	char *input;
	char **input_split;
	t_e_list *env;
	int i;

	i = 0;
	input = NULL;
	env = ft_splitenv(environ);
	while (write(1, "$> ", 3) && ft_read_args(&input, 0))
	{
		ft_putstr(input);
			input_split = ft_arg_split(input);
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
			while(input_split[i])
			{
				ft_putstr(input_split[i]);
				ft_putchar('\n');
				i++;
			}
		}
		// if(ft_strstr())
		// 	ft_setenv(&env, envar, enval);//all chars
		ft_strdel(&input);
	}
}