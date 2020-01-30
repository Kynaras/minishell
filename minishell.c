/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zhelm <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 09:32:03 by zhelm             #+#    #+#             */
/*   Updated: 2019/09/20 09:32:06 by zhelm            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "libft/libft.h"

char *name;
pid_t g_childpid;

void	ft_error(char *arg)
{
	ft_putstr("minishell: command not found : ");
	ft_putendl(arg);
}

void	ft_execve(char **arg, t_args_2d **input_2d, t_env_list **env)
{
	pid_t		pid;
	struct stat sb;

	if (lstat(*arg, &sb) != -1)
	{
		if ((pid = fork()) != 0)
		{
			g_childpid = pid;
			wait(NULL);
		}
		else
			execve(*arg, ft_t_lst_array((*input_2d)->node), ft_lstarray(*env));
	}
	else if ((name = ft_findpath((*input_2d)->node->argument, *env)) != NULL)
	{
		if ((pid = fork()) != 0)
		{
			g_childpid = pid;
			wait(NULL);
		}
		else
			execve(name, ft_t_lst_array((*input_2d)->node), ft_lstarray(*env));
	}
	if (name)
		free(name);
}

void	ft_minishell_mand(t_env_list **env, t_args_2d **input_2d, char **arg)
{
	if (ft_strcmpalpha("env", (*input_2d)->node->argument) == 0)
		ft_env(*env);
	else if (ft_strcmpalpha((*input_2d)->node->argument, "echo") == 0)
		ft_echo((*input_2d)->node, *env);
	else if (ft_strcmpalpha("setenv", *arg) == 0)
		ft_setenv(*env, (*input_2d)->node->next->argument,
		(*input_2d)->node->next->next->argument, 1);
	else if (ft_strcmpalpha("unsetenv", *arg) == 0)
		ft_unsetenv(env, (*input_2d)->node->next->argument);
	else if (ft_strcmpalpha("cd", (*input_2d)->node->argument) == 0)
	{
		if ((*input_2d)->node->next != NULL)
			ft_cd((*input_2d)->node->next->argument, *env);
		else
			ft_cd(NULL, *env);
	}
	else
		ft_execve(arg, input_2d, env);
}

int		ft_main_continue(t_args_2d **input_2d, t_env_list **env, char **arg)
{
	if ((*input_2d)->node->argument &&
	ft_strcmp((*input_2d)->node->argument, "exit") == 0)
	{
		ft_t_args_free(&(*input_2d)->node);
		free(*input_2d);
		ft_elstdel(*env);
		sleep (30);
		return (0);
	}
	else
		ft_minishell_mand(env, input_2d, arg);
	return (1);
}

int		main(void)
{
	char		*arg;
	extern char **environ;
	t_args_2d	*input_2d;
	t_env_list	*env;
	t_args_2d	*tmp;

	rl_attempted_completion_function = ft_namecomplete;
	input_2d = NULL;
	env = ft_splitenv(environ);
	ft_intro();
	while (input_2d || ft_read_args(&input_2d, 0))
	{
		if (input_2d != NULL && input_2d->node)
		{
			arg = input_2d->node->argument;
			if (arg && ft_main_continue(&input_2d, &env, &arg) == 0)
				return (0);
		}
		if (input_2d)
		{
			tmp = input_2d;
			ft_t_args_free(&(input_2d->node));
			input_2d = input_2d->next;
			free(tmp);
		}
	}
}
