#include "minishell.h"
#include "libft/libft.h"

void	ft_arg_split(t_args_2d **input, char *tmp)
{
	int i;
	int j;

	if (*input == NULL && ft_strlen(tmp) != 0)
		*input = ft_t_args_2d_new(NULL);
	i = 0;
	while (ft_strlen(tmp) != 0 && tmp[i])
	{
		j = 0;
		if (ft_iswhitespace(tmp[i]) != 1 && tmp[i] != '"')
		{
			while (tmp[i + j] && ft_iswhitespace(tmp[i + j]) != 1)
				j++;
			if ((*input)->node == NULL)
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
			if ((*input)->node == NULL)
				(*input)->node = ft_t_args_new(ft_strsub(tmp, i, j));
			else
				ft_t_args_add(&((*input)->node), ft_t_args_new(ft_strsub(tmp, i, j)));
			i = i + j;
		}
		i++;
	}
}

char	*ft_read_quote(char *tmp, int qcount)
{
	int i;
	i = 0;

	ft_join(&tmp, readline("quote> "));
	qcount = 0;
	while (tmp[i])
	{
		if (tmp[i] == '\'')
			qcount = (qcount == 0) ? 1 : 0;
		i++;
	}
	if (qcount == 1)
		tmp = ft_read_quote(tmp, qcount);
	return tmp;
}

char	*ft_read_dquote(char *tmp, int count)
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

int		ft_read_args(t_args_2d **input_2d, int count)
{
	char *tmp;
	int i;
	int qcount;

	qcount = 0;
	// if (*input_2d == NULL)
	// 	*input_2d = ft_t_args_2d_new(NULL);
	i = 0;
	tmp = readline("$> ");
	add_history(tmp);
	if (tmp)
	{
		while (tmp[i])
		{
			if (tmp[i] == '"' && qcount == 0)
				count = (count == 0) ? 1 : 0;
			else if (tmp[i] == '\'' && count == 0)
				qcount = (qcount == 0) ? 1 : 0;
			i++;
		}
		if (count == 1)
			tmp = ft_read_dquote(tmp, count);
		if(qcount == 1)
			tmp = ft_read_quote(tmp, qcount);
		ft_arg_split(input_2d, tmp);
	}
	return 1;
}

int		main() //echo, cd, setenv, unsetenv, env, exit
{
	char *arg;
	extern char **environ;
	t_args_2d *input_2d;
	t_env_list *env;
	// pid_t pid;
	struct stat sb;

	input_2d = NULL;
	env = ft_splitenv(environ);
	ft_intro();
	while (input_2d || ft_read_args(&input_2d, 0))
	{
		if (input_2d->node)
		{
			arg = input_2d->node->argument;
			if (arg) //going to activate each time
			{
				// if (ft_strcmp(arg, "echo") != 0 && ft_strcmp(arg, "exit") != 0 && ft_strcmp(arg, "setenv") != 0 && ft_strcmp(arg, "cd") != 0 && ft_strcmp(arg, "unsetenv") != 0 && ft_strcmp(arg, "env") != 0)
				//	{
				// 		if (lstat(arg, &sb) != -1)
				//		{
				// 			if (ft_findpath(input_2d->node->argument, env) != NULL)
				// 			{
				// 				pid = fork();
				// 				if (pid == 0)
				// 					execve(ft_findpath(input_2d->node->argument, env), ft_t_lst_array(input_2d->node), ft_lstarray(env));
				// 				else
				// 					wait(NULL);
				// 			}
				//		}
				//	}
				if (input_2d->node->argument && ft_strcmp(input_2d->node->argument, "exit") == 0) //no other arguments otherwise "error exit: too many arguments" message;
				{
					ft_elstdel(env);
					return (0);
				}
				else if (ft_strcmp("env", input_2d->node->argument) == 0)
					ft_env(env);
				else if (ft_strcmp(input_2d->node->argument, "echo") == 0)
					ft_echo(input_2d->node);
				else if (ft_strcmp("setenv", arg) == 0)
					ft_setenv(env, input_2d->node->next->argument, input_2d->node->next->next->argument, 1); //all chars
				else if (ft_strcmp("unsetenv", arg) == 0)
					ft_unsetenv(env, input_2d->node->next->argument);
				else if (ft_strcmp("cd", arg))
					ft_cd(arg, env);
				else
				{
					ft_putstr("minishell: command not found :");
					ft_putendl(arg);
				}
				input_2d->node = input_2d->node->next;
			}
			input_2d = input_2d->next;
		}
	}
}