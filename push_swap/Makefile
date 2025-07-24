# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: muzz <muzz@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/07 22:17:46 by muzz              #+#    #+#              #
#    Updated: 2025/02/10 19:07:51 by muzz             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FILES = ft_atol.c \
		ft_check_valid.c \
		ft_error.c \
		ft_free_stack.c \
		ft_init_stack.c \
		ft_lstadd.c \
		ft_lstnew.c \
		push_swap.c \
		ft_is_sorted.c \
		ft_lstlast.c \
		ft_op_push.c \
		ft_op_rot.c \
		ft_op_rrot.c \
		ft_op_swap.c \
		ft_sort_stack.c \
		ft_sort_stack2.c \
		ft_sort_algo.c \
		ft_sort_algo2.c \
		ft_sort_algo3.c \

OFILES = $(FILES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $(CFLAGS) $< -o $@

all: $(NAME)

clean:
	rm -f $(OFILES)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re