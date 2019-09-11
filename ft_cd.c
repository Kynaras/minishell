#include "minishell.h"

int main(int argc, char **destination)
{
	char buf[PATH_MAX];
	if (!destination)
		return (0);
	/* If chdir returns less than 0, we call errorfind to identify what type of error it is */
	if (chdir(destination[1]) < 0)
	{
		ft_errorfind(destination[1]);
	}
}