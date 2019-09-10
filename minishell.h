#ifndef MINISHELL_H

# define MINISHELL_H

#	include "libft/libft.h"
#	include <unistd.h>
#	include <stdlib.h>
#	include <limits.h>
# define BUFF_SIZE 2048

typedef struct s_e_list
{
    char *name;
    char *value;
    struct s_e_list *next;
}              t_e_list;

t_e_list    *ft_splitenv(char **environ);
void		ft_t_add(t_e_list *lst, t_e_list *new);
t_e_list	*ft_t_new(char *str, int len);
int 		ft_env(t_e_list *lst);
t_e_list 	*ft_t_vnew(char *name, char *value);
void		ft_elstdel(t_e_list *lst);
void        ft_setenv(t_e_list *original, char *name, char *value, int write)

#endif
