#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "minishell.h"
#include <dirent.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
	char *tmp;
	pid_t pid;
	extern char **environ;
	t_env_list *lst = ft_splitenv(environ);
	while (1)
	{
		tmp = readline("$> ");
		add_history(tmp);
		pid = fork();
		/* Once we fork the function it makes an exact copy of the main. We want to use execve to transform it into a different function */
		/* Note that when you fork, the pid is set to 0 for the child process and a PID number for the parent. */
		if (pid == 0) /* Because the PID for child is 0, this if statement will only ever fire for the child. */
		{
			execve("/bin/ls", argv, ft_lstarray(lst)); /* We are using ft_lstarray on our linked lst because execve only handles 2darrays */
			/*You would pass it the path of the relevant function and arguments based on what the user enters into command line. */
		}
		else
			wait(NULL); /* This will only apply to the parent and tells the parent to wait until the child process is finished running. */
	}
	
}