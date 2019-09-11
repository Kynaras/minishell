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


FLAGS = -g -Wall -Wextra -Werror
all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	make -C libft/
	gcc $(FLAGS) $(SRC) $(LIBRARY) -lreadline

clean:
	rm -f minishell

fclean: clean

re: fclean all