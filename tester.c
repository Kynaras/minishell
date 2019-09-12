#include "minishell.h"

int main()
{
	char buf[100];

	while (1)
	{
		read(1, buf, 20);
		ft_putstr(buf);
	}
}