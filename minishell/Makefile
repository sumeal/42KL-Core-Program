NAME = minishell
CC = cc
CFLAGS = -Wall -Wextra -Werror -I includes
SRCS = srcs/execution_builtin.c \
		srcs/execution_builtin2.c \
		srcs/execution_builtin3.c \
		srcs/execution_utils.c \
		srcs/execution_utils2.c \
		srcs/execution_utils3.c \
		srcs/execution_utils4.c \
		srcs/execution_utils5.c \
		srcs/execution.c \
		srcs/execution2.c \
		srcs/exit.c \
		srcs/export.c \
		srcs/export2.c \
		srcs/export3.c \
		srcs/minishell.c \
		srcs/signal.c \
		srcs/unset.c \
		srcs/expand_lexem.c \
		srcs/expand_utils_one.c \
		srcs/expand_utils_two.c \
		srcs/free_funcs.c \
		srcs/ft_split_quotes.c \
		srcs/ft_split_utils_one.c \
		srcs/ft_split_utils_two.c \
		srcs/is_valid_syntax.c \
		srcs/lecical_analysis.c \
		srcs/syntactic_analysis_utils.c \
		srcs/syntactic_analysis.c \
		srcs/check_pipe_end.c

LIBFT = libft/libft.a

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C libft
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -lreadline -o $(NAME)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	$(MAKE) -C libft clean
	rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft fclean
	rm -f $(NAME)

re: fclean all

me: 
	$(MAKE) fclean
	$(MAKE) all
	$(MAKE) clean

.PHONY: all clean fclean re me
