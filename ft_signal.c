#include "libft/libft.h"
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t childpid;

void    ft_kill(int num)
{
    kill(childpid, SIGTERM);
}

int main()
{
    signal(SIGINT, ft_kill);

    pid_t pid;
    if ((pid = fork()) == 0)
    {
        while (1)
        {
            ft_putendl("Hahaha");
        }
    }
    else
    {
        childpid = pid;
        wait(NULL);
        ft_putendl("Child dead?");
    }
    pid = 0;
    while (pid < 10)
    {
        ft_putendl("It works");
        pid++;
    }
    

}