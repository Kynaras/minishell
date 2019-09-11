#include "minishell.h"

int main(int argc, char **destination, t_e_list *lst)
{
	if (!destination)
		return (0);
	/* If chdir returns less than 0, we call errorfind to identify what type of error it is */
	if (chdir(destination[1]) < 0)
	{
		ft_errorfind(destination[1]);
	}
	/*Else we change the appropriate environment variables*/

	ft_setenv(lst, "OLDPWD", ft_getenv("PWD", lst), 1);
	ft_setenv(lst, "PWD", destination, 1);
}