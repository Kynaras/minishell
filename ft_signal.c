/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: keverett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:20:23 by keverett          #+#    #+#             */
/*   Updated: 2020/01/30 12:20:25 by keverett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include <setjmp.h>

pid_t g_childpid;
char *g_buf;
static int g_i;
jmp_buf g_jump;

void	ft_kill(int signum)
{
	g_i++;
	if (g_childpid != 0 && g_childpid != 1)
	{
		kill(g_childpid, SIGTERM);
	}
	if (g_childpid == 1)
	{
		ft_putendl("Wow");
		longjmp(g_jump, 1);
		ft_putchar('\n');
	}
}

int		main()
{
	pid_t pid;
	jmp_buf jump;
	g_buf = NULL;

	g_childpid = 1;
	signal(SIGINT, ft_kill);
	if (setjmp(jump))
		goto LOOP;
LOOP:
	while (1)
	{
		g_buf = readline("Here we go");
		if (!g_buf)
			break;
		pid = fork();
		if (pid != 0)
		{
			g_childpid = pid;
			printf("PID SET == %d\n", g_childpid);
			wait(NULL);
			ft_putendl("Child dead?");
		}
		else
		{
			g_childpid = 0;
			while (1)
			{
				ft_putendl("Hahaha");
				sleep(1);
			}
		}
	}
	pid = 0;
	while (pid < 10)
	{
		ft_putendl("It works");
		pid++;
	}
}
