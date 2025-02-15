# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abin-moh <abin-moh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/17 15:19:30 by muzz              #+#    #+#              #
#    Updated: 2025/02/09 11:25:10 by abin-moh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
CFLAGS = -Wall -Wextra -Werror

GNL_DIR = get_next_line
MLX_DIR = minilibx-linux
FPF_DIR = ft_printf
SRC_DIR = src

SRC = $(SRC_DIR)/so_long.c \
	  $(SRC_DIR)/check_map.c \
	  $(SRC_DIR)/check_map2.c \
	  $(SRC_DIR)/error_free.c \
	  $(SRC_DIR)/get_map_data.c \
	  $(SRC_DIR)/libft_sl.c \
	  $(SRC_DIR)/mechanism.c \
	  $(GNL_DIR)/get_next_line.c \
	  $(GNL_DIR)/get_next_line_utils.c \
	  $(FPF_DIR)/ft_printf.c \
	  $(FPF_DIR)/ft_putchar.c \
	  $(FPF_DIR)/ft_putnbr_hex_lower.c \
	  $(FPF_DIR)/ft_putnbr_hex_upper.c \
	  $(FPF_DIR)/ft_putnbr_unsigned.c \
	  $(FPF_DIR)/ft_putnbr.c \
	  $(FPF_DIR)/ft_putptr.c \
	  $(FPF_DIR)/ft_putstr.c

OBJ = $(SRC:.c=.o)

FPF = $(FPF_DIR)/libftprintf.a

MLX = $(MLX_DIR)/libmlx.a

%.o : %.c
	$(CC) $(CFLAGS) -I $(FPF_DIR) -I $(MLX_DIR) -I $(GNL_DIR) -c $< -o $@

$(NAME): $(OBJ) $(MLX) $(FPF)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(FPF) $(MLX) -lX11 -lXext

$(FPF):
	make -C $(FPF_DIR)

$(MLX):
	make -C $(MLX_DIR)

all: $(NAME)

clean:
	rm -f $(OBJ)
	make clean -C $(MLX_DIR)
	make clean -C $(FPF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(FPF_DIR)

re: fclean all

.PHONY: all clean fclean re
