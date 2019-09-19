#include "minishell.h"
#include "libft/libft.h"

void ft_arg_split(t_args_2d **input, char **colon) //return 2d_node
{
	int i;
	int j;
	int x;
	t_args_2d *argtmp;
	x = 0;
	while (colon[x])
	{
		if (argtmp == NULL && ft_strlen(colon[x]) != 0 && ft_strcmp(colon[x], "\n") != 0)
			*input = ft_t_args_2d_new(NULL);
		else
			ft_t_args_2d_add(input, ft_t_args_2d_new(NULL));
		argtmp = *input;
		while(argtmp->next)
			argtmp = argtmp->next;
		i = 0;
		while (ft_strlen(colon[x]) != 0 && colon[x][i] && ft_strcmp(colon[x], "\n") != 0)
		{
			j = 0;
			if (ft_iswhitespace(colon[x][i]) != 1 && colon[x][i] != '"')
			{
				while (colon[x][i + j] && ft_iswhitespace(colon[x][i + j]) != 1)
					j++;
				if (argtmp->node == NULL)
					argtmp->node = ft_t_args_new(ft_strsub(colon[x], i, j));
				else
					ft_t_args_add(&(argtmp->node), ft_t_args_new(ft_strsub(colon[x], i, j)));
				i = i + j;
			}
			else if (colon[x][i] == '"')
			{
				i++;
				while (colon[x][i + j] && colon[x][i + j] != '"')
					j++;
				if (argtmp->node == NULL)
					argtmp->node = ft_t_args_new(ft_strsub(colon[x], i, j));
				else
					ft_t_args_add(&(argtmp->node), ft_t_args_new(ft_strsub(colon[x], i, j)));
				i = i + j;
			}
			i++;
		}
		x++;
	}

}

char *ft_read_quote(char *tmp, int qcount)
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
	int qcount;
	char **colon;

	qcount = 0;
	// if (*input_2d == NULL)
	// 	*input_2d = ft_t_args_2d_new(NULL);
	i = 0;
	colon = NULL;
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
		if (qcount == 1)
			tmp = ft_read_quote(tmp, qcount);
		colon = ft_strsplit(tmp, ';');
		if(colon != NULL)
			ft_arg_split(input_2d, colon);
		}
	return 1;
}

int main() //echo, cd, setenv, unsetenv, env, exit
{
	char *arg;
	extern char **environ;
	t_args_2d *input_2d;
	t_env_list *env;
	pid_t pid;
	struct stat sb;

	input_2d = NULL;
	env = ft_splitenv(environ);
	ft_intro();
	while (input_2d || ft_read_args(&input_2d, 0))
	{
		if (input_2d != NULL && input_2d->node)
		{
			arg = input_2d->node->argument;
			if (arg) //going to activate each time
			{
				if (ft_strcmp(arg, "echo") != 0 && ft_strcmp(arg, "exit") != 0 && ft_strcmp(arg, "setenv") != 0 && ft_strcmp(arg, "cd") != 0 && ft_strcmp(arg, "unsetenv") != 0 && ft_strcmp(arg, "env") != 0)
				{
					if (lstat(arg, &sb) != -1)
					{
						pid = fork();
						if (pid == 0)
							execve(arg, ft_t_lst_array(input_2d->node), ft_lstarray(env));
						else
							wait(NULL);
					}
					else if (ft_findpath(input_2d->node->argument, env) != NULL)
					{
						pid = fork();
						if (pid == 0)
							execve(ft_findpath(input_2d->node->argument, env), ft_t_lst_array(input_2d->node), ft_lstarray(env));
						else
							wait(NULL);
					}
				}
				else if (input_2d->node->argument && ft_strcmp(input_2d->node->argument, "exit") == 0) //no other arguments otherwise "error exit: too many arguments" message;
				{
					ft_elstdel(env);
					return (0);
				}
				else if (ft_strcmpalpha("env", input_2d->node->argument) == 0)
					ft_env(env);
				else if (ft_strcmpalpha(input_2d->node->argument, "echo") == 0)
					ft_echo(input_2d->node, env);
				else if (ft_strcmpalpha("setenv", arg) == 0)
					ft_setenv(env, input_2d->node->next->argument, input_2d->node->next->next->argument, 1); //all chars
				else if (ft_strcmpalpha("unsetenv", arg) == 0)
					ft_unsetenv(&env, input_2d->node->next->argument);
				else if (ft_strcmpalpha("cd", input_2d->node->argument) == 0)
				{
					if (input_2d->node->next != NULL)
						ft_cd(input_2d->node->next->argument, env);
					else
						ft_cd(NULL, env);
				}
				else
				{
					ft_putstr("minishell: command not found : ");
					ft_putendl(arg);
				}
			}
		}
		if (input_2d)
			input_2d = input_2d->next;
	}
}