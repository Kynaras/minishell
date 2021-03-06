NAME = minishell

HEADER = minishell.h

LIBRARY = libft/libft.a

SRC =	minishell.c \
		ft_t_add.c \
		ft_t_vnew.c \
		ft_setenv.c \
		ft_elstdel.c \
		ft_echo.c \
		ft_splitenv.c \
		ft_t_new.c \
		ft_env.c \
		ft_t_args_add.c \
		ft_t_args_new.c \
		ft_arr_len.c \
		ft_t_args_2d_add.c \
		ft_t_args_2d_new.c \
		ft_intro.c \
		ft_time.c \
		ft_t_lst_array.c \
		ft_lstarray.c \
		ft_findpath.c \
		ft_getenv.c \
		ft_cd.c \
		ft_freearray.c \
		ft_permcheck.c \
		ft_unsetenv.c \
		ft_namecheck.c \
		ft_slashcount.c \
		ft_finderror.c \
		ft_toolong.c \
		ft_arg_split.c \
		ft_read_args.c \
		ft_namecomplete.c \
		ft_mergarray.c \
		ft_namegen.c \
		ft_pathget.c \
		ft_t_args_free.c \
		ft_megarray_malloc.c \
		 
FLAGS =  -g -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	make -C libft/
	gcc $(FLAGS) $(SRC) $(LIBRARY) -lreadline

clean:
	rm -f minishell

fclean: clean

re: fclean all