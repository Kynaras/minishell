#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

pid_t childpid;
int inr;

void    ft_kill(int signum)
{
	kill(childpid, SIGKILL);
}

int main()
{
    signal(SIGINT, ft_kill);

    pid_t pid;

	while(1)
	{
		readline("Here we go");
    if ((pid = fork()) != 0)
    {
		ft_putendl("parental guideance");
        childpid = pid;
		printf("%d\n", childpid);
        wait(NULL);
        ft_putendl("Child dead?");
    }
    else
    {
		 while (1)
        {
            ft_putendl("Hahaha");
			sleep (1);
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