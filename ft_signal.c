#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell.h"
#include <setjmp.h>

pid_t childpid;
char *buf;
static int i;
jmp_buf jump;

void    ft_kill(int signum)
{
	i++;
	if (childpid != 0 && childpid != 1)
	{
		kill(childpid, SIGTERM);
	}
	if (childpid == 1)
	{
		ft_putendl("Wow");
		longjmp(jump, 1);
		ft_putchar('\n');
	}
}

int main()
{
    pid_t pid;
	jmp_buf jump;
	buf = NULL;

	childpid = 1;
    signal(SIGINT, ft_kill);
	if (setjmp(jump))
			goto LOOP;
	LOOP: while(1)
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