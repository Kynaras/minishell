#include "minishell.h"
#include "libft/libft.h"

int main()
{
	char *arg;
	extern char **environ;
	t_args_2d *input_2d;
	t_env_list *env;
	pid_t pid;
	struct stat sb;

	signal(SIGINT, ft_kill);
	input_2d = NULL;
	env = ft_splitenv(environ);
	ft_intro();
	while (input_2d || ft_read_args(&input_2d, 0))
	{
		if (input_2d != NULL && input_2d->node)
		{
			arg = input_2d->node->argument;
			if (arg)
			{
				if (ft_strcmp(arg, "echo") != 0 && ft_strcmp(arg, "exit") != 0 && ft_strcmp(arg, "setenv") != 0 && ft_strcmp(arg, "cd") != 0 && ft_strcmp(arg, "unsetenv") != 0 && ft_strcmp(arg, "env") != 0)
				{
					if (lstat(arg, &sb) != -1)
					{
						if ((pid = fork()) == 0)
							execve(arg, ft_t_lst_array(input_2d->node), ft_lstarray(env));
						else
						{
							childpid = pid;
							wait(NULL);
						}
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
				else if (input_2d->node->argument && ft_strcmp(input_2d->node->argument, "exit") == 0)
				{
					ft_elstdel(env);
					return (0);
				}
				else if (ft_strcmpalpha("env", input_2d->node->argument) == 0)
					ft_env(env);
				else if (ft_strcmpalpha(input_2d->node->argument, "echo") == 0)
					ft_echo(input_2d->node, env);
				else if (ft_strcmpalpha("setenv", arg) == 0)
					ft_setenv(env, input_2d->node->next->argument, input_2d->node->next->next->argument, 1);
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