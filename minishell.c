#include "minishell.h"
#include "libft/libft.h"
int main()
{
	extern char **environ;
    char input[BUFF_SIZE];

    while(write(1, "$> ", 3) && read(0, input, BUFF_SIZE))//read waits until you press enter and then it adds that newline to input
    {
        if(ft_strcmp(input, "exit\n") == 0)
            return (0);
		if(ft_strcmp("env\n", input) == 0)
				return(ft_env(ft_splitenv(environ)));
        ft_putstr(input);
        ft_memset(input, 0, ft_strlen(input));
    }
}