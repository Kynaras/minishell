#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "minishell.h"
#include <dirent.h>
#include <fcntl.h>

char **character_name_completion(const char *, int, int);
char *character_name_generator(const char *, int);

char	**ft_megarray(char **array)
{
	DIR *dr;
	struct dirent *dir;
	char **megarray;
	int i;
	int str;
	str = ft_megarray_malloc(array);
	megarray = ft_memalloc(sizeof(char *) * str + 2);
	i = -1;
	str = 0;
	while (array[++i])
	{
		if ((dr = opendir(array[i])))
		{
			while ((dir = readdir(dr)))
			{
				megarray[str] = ft_strdup(dir->d_name);
				str++;
			}
			closedir(dr);
		}
	}
	return (megarray);
}

char	**ft_pathget(t_env_list *env)
{
	while (env)
	{
		if (!ft_strcmp(env->name, "PATH"))
			break;
		env = env->next;
	}
	if (env)
		return (ft_strsplit(env->value, ':'));
	return (NULL);
}

int		main(int argc, char *argv[])
{
	char *buffer;

	rl_attempted_completion_function = character_name_completion;

	printf("Test autocompleter has started\n");
	while ((buffer = readline("> ")) != NULL)
	{
		if (buffer)
		{
			printf("You entered: %s\n", buffer);
		}
	}
	return 0;
}

char	**
character_name_completion(const char *text, int start, int end)
{
	rl_attempted_completion_over = 1;
	rl_completion_append_character = '\0';
	if (start == 0)
		return rl_completion_matches(text, character_name_generator);
	else
		return (NULL);
}

char	*
character_name_generator(const char *text, int state)
{
	extern char **environ;
	t_env_list *env = ft_splitenv(environ);
	static int list_index, len;
	char *name;
	static int i;
	static char **array;
	open("file.txt", O_RDWR);

	if (!state)
	{
		i = -1;
		len = strlen(text);
		array = ft_megarray(ft_pathget(env));
	}
	while (array[++i])
	{
		if (ft_strncmp(array[i], text, len) == 0)
		{
			name = ft_strdup(array[i]);
			return (name);
		}
	}
	return (NULL);
}
