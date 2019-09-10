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
	return (strings);
}



void ft_arg_split(char *input)
{
	int i;
	int j;
	int n;
	char **input_split;

	j = 0;
	i = 0;
	n = 0;
	input_split = (char**)malloc(sizeof(char *) * (ft_count_args(input) + 1));
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
}

int ft_read_args(char *input, int count)
{
	char tmp[PATH_MAX];
	int i;

	i = 0;
	read(0, tmp, PATH_MAX);
	while(tmp[i])
	{
		if(tmp[i] == '"')
			count = (count == 0) ? 1 : 0;
		i++;
	}
	if (count == 1)
	{
		input = ft_strjoin(input, tmp);
		ft_putendl(input);
		write(1, "dquote> ", 8);
		ft_read_args(input, count);
	}
	return 1;
}

int main() //make sure there is only one command
{
	extern char **environ;
	char input[PATH_MAX];
	t_e_list *env;

	env = ft_splitenv(environ);
	while (write(1, "$> ", 3) && ft_read_args(input, 0))
	{
		ft_putstr(input);
		if (ft_strcmp(input, "exit\n") == 0)
		{
			ft_elstdel(env);
			return (0);
		}
		ft_arg_split(input);
		if (ft_strcmp("env\n", input) == 0)
			ft_env(env);
		if (ft_strstr(input, "echo") != NULL)
			ft_arg_split(input);
		//if(ft_strstr())
		//	ft_setenv(&env, envar, enval);//all chars
		ft_memset(input, 0, ft_strlen(input));
	}
}