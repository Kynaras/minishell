#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "minishell.h"
#include <dirent.h>
#include <fcntl.h>

int ft_megarray_malloc(char **array)
{
	DIR *dr;
	struct dirent *dir;
	int i;
	int str;
	
	str = 0;
	i =  -1;

	while (array[++i])
	{
		if ((dr = opendir(array[i])))
		{
			while ((dir = readdir(dr)))
				str++;
		}
		closedir(dr);
	}
	return (str);
}