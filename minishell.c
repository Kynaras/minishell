#include "minishell.h"
#include "libft/libft.h"
int main()
{

    char input[BUFF_SIZE];
    while(read(0, input, BUFF_SIZE))//read waits until you press enter and then it adds that newline to input
    {
        if(ft_strcmp(input, "exit\n") == 0)
            return (0);
        ft_putstr(input);
        ft_memset(input, 0, ft_strlen(input));
    }
}