#ifndef MINISHELL_H

# define MINISHELL_H
#	include "minishell.h"
#	include <stdio.h>
#	include <readline/readline.h>
#	include <readline/history.h>
#	include "libft/libft.h"
#	include <unistd.h>
#	include <stdlib.h>
#	include <limits.h>
#	include <sys/stat.h>
#	include <dirent.h>
#	include <sys/types.h>
#	include <sys/wait.h>

# define BUFF_SIZE 2048

typedef struct	s_args
{
	char			*argument;
	struct s_args	*next;
}				t_args;

typedef struct s_args_2d
{
	struct  s_args *node;
	struct s_args_2d *next;
}				t_args_2d;

typedef struct s_e_list
{
    char *name;
    char *value;
    struct s_e_list *next;
}              t_env_list;

typedef struct s_v_list
{
	DIR				*dr;
	struct dirent	*dir;
	int				i;
	char			**path;
	char			*exepath;
}				t_v_list;

void		ft_cd(char *destination, t_env_list *env);
void		ft_unsetenv(t_env_list **env, const char *name);
char		**ft_t_lst_array(t_args *args);
t_env_list	*ft_splitenv(char **environ);
void		ft_t_add(t_env_list *lst, t_env_list *new);
t_env_list	*ft_t_new(char *str, int len);
int 		ft_env(t_env_list *lst);
t_env_list 	*ft_t_vnew(char *name, char *value);
void		ft_elstdel(t_env_list *lst);
void        ft_setenv(t_env_list *original, char *name, char *value, int write);
int			ft_errorfind(char *path);
int			ft_slashcount(char *path, int ignore);
void		ft_t_args_add(t_args **lst, t_args *new);
t_args		*ft_t_args_new(char *str);
t_args_2d	*ft_t_args_2d_new(t_args *lst);
void		ft_t_args_2d_add(t_args_2d **lst, t_args_2d *new);
size_t		ft_arr_len(char **arr);
void		ft_echo(t_args *input, t_env_list *lst);
char		**ft_lstarray(t_env_list *lst);
char		*ft_findpath(char *arg, t_env_list *env);
char		*ft_getenv(char *var, t_env_list *lst);
int			ft_finderror(char *path);
int			ft_permcheck(char *path);
void		ft_freearray(char **array);
char		*ft_namecheck(char *path);
void		ft_intro(void);
void		ft_time(void);
int			ft_toolong(char *path);

#endif
