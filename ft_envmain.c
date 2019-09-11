#include "minishell.h"
//#include <readline/readline.h>
//#include <readline/history.h>

int main(int argc, char **argv)
{
	char *buf = ft_memalloc(12);

int i = 0;
	while(i < 10)
	{
		ft_putstr("Please enter >");
		buf[i] = getchar();
		i++;
	}
	ft_putstr(buf);

// }

// #include <stdio.h>
// char getch(void)
// {
//  char ch;
//  ch = getchar();
//  while(getchar()!='n')
//  ;
//  return(ch);
}
