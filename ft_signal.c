#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"

pid_t childpid;
char *buf;
static int i;

void    ft_kill(int signum)
{
	i++;
	if (childpid != 0)
	{
		kill(childpid, SIGTERM);
	}
	if (1 > 0)
		ft_putstr("\b \b \b \b \b \b");
	ft_putchar('\r');
	// ft_putstr("\n$>");
}

int main()
{
    pid_t pid;

	buf = NULL;
    signal(SIGINT, ft_kill);
	while(1)
	{
		buf = readline("Here we go");
		if (!buf)
			break;
    	pid = fork();
	if (pid != 0)
    {
        childpid = pid;
		printf("PID SET == %d\n", childpid);
        wait(NULL);
        ft_putendl("Child dead?");
    }
    else
    {
		childpid = 0;
		 while (1)
        {
			printf("%d\n", childpid);
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