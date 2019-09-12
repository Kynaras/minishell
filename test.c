#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include "minishell.h"
#include <dirent.h>

char **character_name_completion(const char *, int, int);
char *character_name_generator(const char *, int);

char *character_names[] = {
    "Arthur Dent",
    "Ford Prefect",
    "Tricia McMillan",
    "Zaphod Beeblebrox",
    NULL
};

char **ft_pathget(t_env_list *env)
{
	while (env)
	{
		if (!ft_strcmp(env->name, "PATH"))
			break ;
		env = env->next;
	}
	if (env)
		return (ft_strsplit(env->value, ':'));
	return (NULL);
}

int
main(int argc, char *argv[])
{
    rl_attempted_completion_function = character_name_completion;

    printf("Who's your favourite Hitchiker's Guide character?\n");
    char *buffer = readline("> ");
    if (buffer) {
        printf("You entered: %s\n", buffer);
        free(buffer);
    }

    return 0;
}

char **
character_name_completion(const char *text, int start, int end)
{
    rl_attempted_completion_over = 1;
    return rl_completion_matches(text, character_name_generator);
}

char *
character_name_generator(const char *text, int state)
{
	DIR *dr;
	struct dirent *dir;
	extern char **environ;
	t_env_list *env = ft_splitenv(environ);
	static int list_index, len;
    char *name;
	static int i;

    if (!state) {
        list_index = 0;
        len = strlen(text);
    }

	char **array = ft_pathget(env);
	//ft_putstr(array[i]);
	while (array[i++])
	{
		// return (NULL);
		// ft_putstr(array[i]);
		if ((dr = opendir(array[i])))
		{
			while((dir = readdir(dr)))
			{
				if (strncmp(dir->d_name, text, len) == 0)
				{
					name = ft_strdup(dir->d_name);
					closedir(dr);
					return (name);
				}
			}
		}

	}
	return (NULL);
}
    // while ((name = array[list_index++])) 
	// {
    //     if (strncmp(name, text, len) == 0) 
	// 	{
    //         return strdup(name);
    //     }
    // }

//     return NULL;
// }