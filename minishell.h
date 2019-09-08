#ifndef MINISHELL_H

# define MINISHELL_H

#	include "libft/libft.h"
#	include <unistd.h>
#	include <stdlib.h>
# define BUFF_SIZE 2048

typedef struct s_e_list
{
    char *name;
    char *value;
    struct s_e_list *next;
}              t_e_list;

#endif
