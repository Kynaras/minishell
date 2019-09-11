#ifndef MINISHELL_H

# define MINISHELL_H

#	include "libft/libft.h"
#	include <unistd.h>
#	include <stdlib.h>
#	include <limits.h>
#	include <sys/stat.h>

# define BUFF_SIZE 2048

typedef struct	s_args
{
	char			*argument;
	struct s_args	*next;
}				t_args;

typedef struct s_args_2d
{
	struct  s_args *args;
	struct s_args_2d *next;
}				t_args_2d;

typedef struct s_e_list
{
    char *name;
    char *value;
    struct s_e_list *next;
}              t_env_list;

t_env_list    *ft_splitenv(char **environ);
void		ft_t_add(t_env_list *lst, t_env_list *new);
t_env_list	*ft_t_new(char *str, int len);
int 		ft_env(t_env_list *lst);
t_env_list 	*ft_t_vnew(char *name, char *value);
void		ft_elstdel(t_env_list *lst);
void        ft_setenv(t_env_list *original, char *name, char *value, int write);
int			ft_errorfind(char *path);
int			ft_slashcount(char *path, int ignore);

#endif
